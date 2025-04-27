#include "VigenereCipher.h"
#include <cctype>

string VigenereCipher::Encrypt(const string &plaintext, const string &key) {
    string encrypted = plaintext;
    int keyIndex = 0;
    for (char &ch : encrypted) {
        if (isalpha(ch)) {
            char offset = islower(ch) ? 'a' : 'A';
            char keyChar = tolower(key[keyIndex % key.size()]);
            int shift = keyChar - 'a';
            ch = (ch - offset + shift + 26) % 26 + offset;
            keyIndex++;
        }
    }
    return encrypted;
}

string VigenereCipher::Decrypt(const string &ciphertext, const string &key) {
    string decrypted = ciphertext;
    int keyIndex = 0;
    for (char &ch : decrypted) {
        if (isalpha(ch)) {
            char offset = islower(ch) ? 'a' : 'A';
            char keyChar = tolower(key[keyIndex % key.size()]);
            int shift = keyChar - 'a';
            ch = (ch - offset - shift + 26) % 26 + offset;
            keyIndex++;
        }
    }
    return decrypted;
}
