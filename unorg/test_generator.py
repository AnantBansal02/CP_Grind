def generate_specific_test_case():
    test_case = [
        "1",
        "49999*2+3 199996"
    ]
    for i in range(1, 49999+1):
        test_case.append(f"{49999*2+3} {i} {i}")
    for i in range(1, 49999+1):
        test_case.append(f"{49999*2+2} {i} {i}")
    for i in range(49999+1, 49999*2+1):
        test_case.append(f"{49999*2+2} {i} {i}")
    for i in range(49999+1, 49999*2+1):
        test_case.append(f"{49999*2+1} {i} {i}")
    test_case.append(f"{49999*2+3} {49999*2+1}")
    return '\n'.join(test_case)

def write_to_file(test_case, filename):
    with open(filename, 'w') as file:
        file.write(test_case)

if __name__ == "__main__":
    test_case = generate_specific_test_case()
    write_to_file(test_case, "input.txt")
