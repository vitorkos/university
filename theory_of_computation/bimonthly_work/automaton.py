# Bimonthly work
# Automaton implematation

# Importing libs
import csv
import json
import time

# Function to read json file
def read_json(file):
    with open(file, 'r') as file:
        automaton_json = json.load(file)
    return automaton_json

def convert_afnd_epsilon_to_afnd(automaton_json):
    afnd ={
        "initial": automaton_json["initial"],
        "final": automaton_json["final"],
        "transitions": []
    }
    
    for transition in automaton_json["transitions"]:
        if transition["read"] is not None:
            afnd["transitions"].append(transition)
        else:
            for state in transition["to"]:
                afnd["transitions"].append({
                    "from": transition["from"],
                    "read": "",
                    "to": state
                })
    return afnd

def convert_afnd_to_afd(automaton_afnd):
    afd={
        "initial": [automaton_afnd["initial"]],
        "final": [],
        "transitions": []
    }
    
    def get_destinations(states, symbol):
        destinations = set()
        for state in states:
            for transition in automaton_afnd["transitions"]:
                if transition["from"] == state and transition["read"] == symbol:
                    destinations.add(transition["to"])
        return destinations
    
    states_to_process = [afd["initial"]]
    processed_states = set()
    
    while len(states_to_process) > 0:
        current_state = states_to_process.pop()
        processed_states.add(tuple(current_state))
        
        for symbol in {t["read"] for t in automaton_afnd["transitions"]}:
            destinations = get_destinations(current_state, symbol)
            
            if len(destinations) > 0:
                afd["transitions"].append({"from": current_state, "read": symbol, "to": list(destinations)})
                
                if tuple(destinations) not in processed_states:
                    states_to_process.append(list(destinations))
                    
        if any(final_state in current_state for final_state in automaton_afnd["final"]):
            afd["final"].append(current_state)
    
    return afd
    
    
    
    
    

def is_deterministic(automaton_json):
    for transition in automaton_json["transitions"]:
        if len(transition["read"]) > 1:
            return False
    return True


def process_input(automaton, input):
    state = automaton["initial"]
    for symbol in input:
        next_states = []
        for transition in automaton["transitions"]:
            if transition["from"] == state and transition["read"] == symbol:
                next_states.extend(transition["to"])
        state = next_states
    return state




def main():
    
    # Reading json file
    automaton_json = read_json('automaton.json')
    
    # Checking if automaton is AFND or AFD
    if "read" in automaton_json["transitions"][0]:
        is_afnd_epsilon = True
    else:
        is_afnd_epsilon = False
        
    # Converting AFND-Epsilon to AFND
    if is_afnd_epsilon:
        automaton_afnd = convert_afnd_epsilon_to_afnd(automaton_json)
        is_afnd = True
    else:
        automaton_afnd = automaton_json
        is_afnd = is_deterministic(automaton_json)
        
    # 
    if is_afnd:
        automaton_afd = convert_afnd_to_afd(automaton_afnd)    
    else:
        automaton_afd = automaton_afnd
    
    
    print("Tipo do Autômato:")
    if is_afnd_epsilon:
        print("Autômato Finito Não-Determinístico com Movimentos Vazios (AFND-ε)")
    elif is_afnd:
        print("Autômato Finito Não-Determinístico (AFND)")
    else:
        print("Autômato Finito Determinístico (AFD)")
        
    #reading_csv('automaton.csv')
    with open("input.csv", 'r') as file:
        csv_reader = csv.reader(file)
        header = next(csv_reader)
        results = [["Input", "Expected", "Result", "Time"]]
        
        for row in csv_reader:
            
            input = row[0]
            expected = row[1]
            start_time = time.time()
            
            if is_afnd_epsilon or is_afnd:
                result = process_input(automaton_afnd, input)  
                obtained_output = result in automaton_afd["final"]
            else:
                obtained_output = input in automaton_afd["final"]
                
            elapsed_time = time.time() - start_time
            results.append([input, expected, str(obtained_output), "{:.6f}".format(elapsed_time)])
            
    # writing in the output csv
    with open("output.csv", 'w', newline='') as file:
        csvwriter = csv.writer(file)
        csvwriter.writerows(results)



if __name__ == "__main__":
    main()
