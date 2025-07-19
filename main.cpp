#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Read entire file into a vector of bytes
bool readFile(const string& filename, vector<char>& data) {
    ifstream file(filename, ios::binary | ios::ate);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return false;
    }

    streamsize size = file.tellg();
    file.seekg(0, ios::beg);

    data.resize(size);
    if (!file.read(data.data(), size)) {
        cerr << "Error: Failed to read file " << filename << endl;
        return false;
    }
    file.close();
    return true;
}

// Write bytes to file
bool writeFile(const string& filename, const vector<char>& data) {
    ofstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << " for writing" << endl;
        return false;
    }

    if (!file.write(data.data(), data.size())) {
        cerr << "Error: Failed to write to file " << filename << endl;
        return false;
    }
    file.close();
    return true;
}

// XOR encrypt/decrypt using password key
void xorEncryptDecrypt(vector<char>& data, const string& password) {
    size_t passLen = password.size();
    for (size_t i = 0; i < data.size(); ++i) {
        data[i] ^= password[i % passLen];
    }
}

int main() {
    cout << "=== Advanced File Encrypter ===" << endl;

    string inputFile, outputFile, password;
    bool overwrite = false;
    int choice;

    do {
        cout << "\nOptions:\n1. Encrypt\n2. Decrypt\n0. Exit\nYour choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1 || choice == 2) {
            cout << "Enter input file path: ";
            getline(cin, inputFile);

            cout << "Overwrite input file? (y/n): ";
            char ow;
            cin >> ow;
            overwrite = (ow == 'y' || ow == 'Y');
            cin.ignore();

            if (!overwrite) {
                cout << "Enter output file path: ";
                getline(cin, outputFile);
            } else {
                outputFile = inputFile; // overwrite input
            }

            cout << "Enter password/key (any length): ";
            getline(cin, password);

            vector<char> fileData;
            if (!readFile(inputFile, fileData)) {
                continue;
            }

            cout << "File size: " << fileData.size() << " bytes\n";

            xorEncryptDecrypt(fileData, password);

            if (!writeFile(outputFile, fileData)) {
                continue;
            }

            cout << (choice == 1 ? "Encryption" : "Decryption") << " successful!\n";
            cout << "Output file: " << outputFile << "\n";
        }

    } while (choice != 0);

    cout << "Goodbye!\n";
    return 0;
}
