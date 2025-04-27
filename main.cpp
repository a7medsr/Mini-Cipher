#include <bits/stdc++.h>
#include "CaesarCipher.h"
#include "VigenereCipher.h"
#include "PlayfairCipher.h"
#include "RailFenceCipher.h"
using namespace std;

#define e '\n'

int main() {
    int cipherChoice, action;
    cout << "Choose a cipher:" << e;
    cout << "1. Caesar Cipher" << e;
    cout << "2. Vigenere Cipher" << e;
    cout << "3. Playfair Cipher" << e;
    cout << "4. Rail Fence Cipher" << e;
    cout << "Enter your choice: ";
    cin >> cipherChoice;
    cin.ignore();

    cout << "Choose action: (1) Encrypt (2) Decrypt: ";
    cin >> action;
    cin.ignore();

    string text;
    cout << "Enter the text: ";
    getline(cin, text);

    if (cipherChoice == 1) {
        int shift;
        cout << "Enter shift value: ";
        cin >> shift;
        if (action == 1)
            cout << "Encrypted: " << CaesarCipher::Encrypt(text, shift) << e;
        else
            cout << "Decrypted: " << CaesarCipher::Decrypt(text, shift) << e;
    }
    else if (cipherChoice == 2) {
        string key;
        cout << "Enter the key: ";
        getline(cin, key);
        if (action == 1)
            cout << "Encrypted: " << VigenereCipher::Encrypt(text, key) << e;
        else
            cout << "Decrypted: " << VigenereCipher::Decrypt(text, key) << e;
    }
    else if (cipherChoice == 3) {
        string key;
        cout << "Enter the key: ";
        getline(cin, key);
        if (action == 1)
            cout << "Encrypted: " << PlayfairCipher::Encrypt(text, key) << e;
        else
            cout << "Decrypted: " << PlayfairCipher::Decrypt(text, key) << e;
    }
    else if (cipherChoice == 4) {
        int rails;
        cout << "Enter number of rails: ";
        cin >> rails;
        if (action == 1)
            cout << "Encrypted: " << RailFenceCipher::Encrypt(text, rails) << e;
        else
            cout << "Decrypted: " << RailFenceCipher::Decrypt(text, rails) << e;
    }
    else {
        cout << "Invalid choice!" << e;
    }
}
