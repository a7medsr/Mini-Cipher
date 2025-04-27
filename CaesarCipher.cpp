#include "CaesarCipher.h"

string CaesarCipher::Encrypt(const string &plaintext, int shift) {
    string encrypted = plaintext;
    for (char &ch : encrypted) {
        if (isalpha(ch)) {
            char offset = islower(ch) ? 'a' : 'A';
            ch = (ch - offset + shift + 26) % 26 + offset;
        }
    }
    return encrypted;
}

string CaesarCipher::Decrypt(const string &ciphertext, int shift) {
    return Encrypt(ciphertext, -shift);
}
