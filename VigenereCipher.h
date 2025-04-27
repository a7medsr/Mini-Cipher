#pragma once
#include <string>
using namespace std;

class VigenereCipher {
public:
    static string Encrypt(const string &plaintext, const string &key);
    static string Decrypt(const string &ciphertext, const string &key);
};
