# Enigma Simulator in C++

## Overview
This project is a C++ implementation of the Enigma machine, a cipher device used during World War II for encrypting and decrypting secret messages. The program randomly generates three rotors and a plugboard configuration, allowing users to encode and decode strings.

## Features
- Randomly generated plugboard configuration.
- Three rotors with random mappings.
- Encoding and decoding of user input strings.
- Display of current plugboard and rotor configurations.
- Verification of the encoding and decoding process through assertions.

## Getting Started

### Prerequisites
- A C++ compiler (e.g., g++, clang++)
- C++11 or later

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/Uk2607/ENIGMA.git
   cd ENIGMA
   ```

2. Compile the code:
   ```bash
   g++ main.cpp -o enigma
   ```

3. Run the program:
   ```bash
   ./enigma
   ```

### Usage
1. Upon running the program, the plugboard and rotor configurations will be displayed.
2. You will be prompted to enter a string to encode.
3. The program will output the encoded string and then decode it back to the original string.
4. The program verifies that the decoded string matches the original input.

### Example
```
Plugboard Configuration::
[[a <-> b]] [[c <-> d]] [[e <-> f]] [[g <-> h]] [[i <-> j]] [[k <-> l]] [[m <-> n]] 

Rotor #1 Configuration with current index <5> ::
[[a <-> b], [a <-> c]] [[b <-> d], [b <-> e]] [[c <-> f], [c <-> g]] ...

Enter your string:: hello
Encoded string:: xxxxx
Decoded string:: hello
```

## Code Structure
- `main.cpp`: Contains the main logic for the Enigma machine, including functions for creating the plugboard and rotors, encoding and decoding characters, and displaying configurations.

## Functions
- `showPlugBoard`: Displays the current plugboard configuration.
- `showRotorState`: Displays the current state of the rotors.
- `encodeFromPlugBoard`: Encodes a character using the plugboard.
- `createPlugBoard`: Generates a random plugboard configuration.
- `createRotor`: Generates a random rotor configuration.
- `rotateRotor`: Rotates the rotor for the encoding process.
- `encodeFromRotors`: Encodes a character using the rotors.
- `codeChar`: Encodes a single character through the plugboard and rotors.
- `runEnigma`: Encodes or decodes a string using the Enigma machine logic.

## Contributing
Contributions are welcome! Please feel free to submit a pull request or open an issue for any suggestions or improvements.

## License
This project is licensed under the MIT License. See the LICENSE file for more details.

## Acknowledgments
- Inspired by the historical Enigma machine used during World War II.
- Special thanks to the open-source community for their contributions to C++ development.

---
