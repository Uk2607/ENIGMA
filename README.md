# Enigma Machine Simulator

This project is a C++ implementation of the Enigma machine, the historical cipher device used during World War II. It provides functionalities for encoding and decoding messages while saving and reading machine settings to replicate the original behavior.

---

## Features

- **Encoding**: Encrypt plaintext messages into ciphertext using `encode.cpp`.
- **Saving Settings**: Save the Enigma machine's configuration to a file during encoding.
- **Decoding**: Decrypt ciphertext back to plaintext using `decode.cpp` with the saved configuration.
- **Modular Implementation**: The code is divided into separate files for clarity and maintainability.

---

## File Structure

1. **`main.cpp`**
   - Initial implementation for encoding and decoding in a single file.
   - Useful for understanding the basic functionality of the Enigma machine.

2. **`encode.cpp`**
   - Contains the main logic for encoding plaintext messages.
   - Saves the Enigma machine's rotor and plugboard settings to a configuration file for later use.

3. **`decode.cpp`**
   - Reads the saved configuration file.
   - Uses the settings to decrypt the encrypted messages back to plaintext.

---

## Installation

Follow these steps to compile and run the program:

### 1. Clone the Repository
```bash
git clone https://github.com/Uk2607/ENIGMA.git
cd ENIGMA
```

### 2. Compile the Code
To compile the individual files:
```bash
g++ -o encode encode.cpp
g++ -o decode decode.cpp
```

### 3. Run the Encoders and Decoders
#### Encoding:
```bash
./encode
```

#### Decoding:
```bash
./decode
```

---

## Usage

### Encoding a Message
1. Run `encode.cpp` using the command:
   ```bash
   ./encode
   ```
2. Follow the prompts to enter your plaintext message.
3. The program will generate the encoded ciphertext and save the Enigma machine's settings to a configuration file (`enigma_config.txt` by default).

### Decoding a Message
1. Run `decode.cpp` using the command:
   ```bash
   ./decode
   ```
2. The program will read the configuration file to retrieve the saved Enigma settings.
3. Enter the ciphertext to decrypt, and the program will display the original plaintext message.

---

## Configuration

The Enigma machine's settings (rotors, plugboard mappings, etc.) are automatically saved during encoding and read during decoding.
You can find and modify these settings in the `enigma_config.txt` file if needed.

---

## Example

### Encoding
Input:
```
HELLOWORLD
```
Output:
```
Encrypted Message: XMCKLZWOAL
Settings Saved: enigma_config.txt
```

### Decoding
Input:
```
XMCKLZWOAL
```
Output:
```
Decrypted Message: HELLOWORLD
```

---

## Limitations

- The program assumes that the same configuration file is used for both encoding and decoding.
- Manual modifications to the configuration file may result in incorrect decoding.

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## Contributing

Contributions are welcome! Feel free to fork the repository, make enhancements, and submit a pull request.

---