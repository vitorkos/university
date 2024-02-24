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

# Exemplo de uso:
states = {0, 1, 2, 3, 4}
initial_state = 0
final_states = {4}
blank_symbol = '_'
transitions = [
    {"from": 0, "to": 1, "read": "a", "write": "A", "dir":"R"},
    {"from": 1, "to": 1, "read": "a", "write": "a", "dir":"R"},
    {"from": 1, "to": 1, "read": "B", "write": "B", "dir":"R"},
    {"from": 1, "to": 2, "read": "b", "write": "B", "dir":"L"},
    {"from": 2, "to": 2, "read": "B", "write": "B", "dir":"L"},
    {"from": 2, "to": 2, "read": "a", "write": "a", "dir":"L"},
    {"from": 2, "to": 0, "read": "A", "write": "A", "dir":"R"},
    {"from": 0, "to": 3, "read": "B", "write": "B", "dir":"R"},
    {"from": 3, "to": 3, "read": "B", "write": "B", "dir":"R"},
    {"from": 3, "to": 4, "read": "_", "write": "_", "dir":"L"}      
]

tm = TuringMachine(states, initial_state, final_states, transitions, blank_symbol)
with open('./input/duplobal2.in', 'r') as f:
    input_string = f.read().strip()
result = tm.run(input_string)
if result:
    print('aceita')
else:
    print('rejeita')
