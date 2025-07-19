# AdvancedFileEncrypterCPP

A robust and versatile file encryption and decryption tool written in C++. This program uses a password-based XOR cipher to securely encrypt or decrypt any type of file, whether it's text, images, documents, or executables.

## Features

- **Supports any file type** (binary safe) — encrypt or decrypt text files, images, videos, executables, etc.
- **Password-based encryption:** Uses a user-provided string password as a key for XOR encryption. The password can be any length.
- **Overwrite option:** Choose to overwrite the original file or save the output as a new file.
- **File size display:** Displays the size of the file being processed to keep users informed.
- **Robust error handling:** Checks for file read/write errors and notifies the user.
- **Simple command-line interface:** Easy to use with clear prompts.

## How It Works

The program reads the entire input file into memory and applies a bitwise XOR operation between each byte of the file and the corresponding byte in the password key. Because XOR is symmetric, running the encryption process twice with the same password restores the original file.

**Important:** This is a learning tool and should not be used for securing highly sensitive data. For real-world encryption needs, consider using strong algorithms like AES.

## How to Use

1. Compile the program using your C++ compiler (e.g., g++):

   ```bash
   g++ -o AdvancedFileEncrypter main.cpp
Run the program:

bash
Kopieren
Bearbeiten
./AdvancedFileEncrypter
Follow the on-screen prompts:

mathematica
Kopieren
Bearbeiten
Options:
1. Encrypt
2. Decrypt
0. Exit
Your choice: 1
Enter input file path: secret.docx
Overwrite input file? (y/n): n
Enter output file path: secret_encrypted.bin
Enter password/key (any length): myStrongPass123
Encryption successful!
Output file: secret_encrypted.bin
To decrypt, choose option 2 and provide the encrypted file and the same password.

If you choose to overwrite, the input file will be replaced with the encrypted/decrypted data.

Requirements
C++11 or later

Standard C++ libraries

Limitations
The XOR cipher used here is not secure against modern cryptanalysis and should only be used for educational purposes.

For stronger security, integrate industry-standard encryption libraries like OpenSSL or Crypto++.

Contributing
Feel free to fork this repository, improve the encryption logic, add support for hashes/checksums, or create a GUI frontend.

License
This project is licensed under the MIT License.
