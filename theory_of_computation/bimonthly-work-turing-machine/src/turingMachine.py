import json

class TuringMachine:
    def __init__(self, states, initial_state, final_states, transitions, blank_symbol):
        self.states = states
        self.initial_state = initial_state
        self.final_states = final_states
        self.transitions = transitions
        self.blank_symbol = blank_symbol
        self.head_position = 0
        self.current_state = initial_state
        self.tape = [self.blank_symbol]

    def step(self):
        current_symbol = self.tape[self.head_position]
        for transition in self.transitions:
            if (transition['from'] == self.current_state and
                transition['read'] == current_symbol):
                self.tape[self.head_position] = transition['write']
                if transition['dir'] == 'R':
                    self.head_position += 1
                    if self.head_position == len(self.tape):
                        self.tape.append(self.blank_symbol)
                elif transition['dir'] == 'L':
                    self.head_position -= 1
                    if self.head_position < 0:
                        self.tape.insert(0, self.blank_symbol)
                        self.head_position = 0
                self.current_state = transition['to']
                return

    def run(self, input_string):
        self.tape = [self.blank_symbol] + list(input_string) + [self.blank_symbol]
        self.head_position = 1
        self.current_state = self.initial_state

        while True:
            if self.current_state in self.final_states:
                return True
            elif self.current_state not in self.states:
                return False
            self.step()

    def save_tape(self, output_file):
        with open(output_file, 'w') as f:
            f.write(''.join(self.tape))

with open('./duplo_bal.json', 'r') as f:
    rules = json.load(f)

states = {0, 1, 2, 3, 4}
initial_state = rules['initial']
final_states = rules['final']
blank_symbol = rules['white']
transitions = rules['transitions']

tm = TuringMachine(states, initial_state, final_states, transitions, blank_symbol)
with open('./input/duplobal.in', 'r') as f:
    input_string = f.read().strip()

result = tm.run(input_string)
if result:
    print('aceita')
else:
    print('rejeita')

tm.save_tape('./output/fita.txt')