#pragma once
#include <string>
using namespace std;

class CaesarCipher {
public:
    static string Encrypt(const string &plaintext, int shift);
    static string Decrypt(const string &ciphertext, int shift);
};
