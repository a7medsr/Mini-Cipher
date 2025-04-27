#pragma once
#include <string>
#include <vector>
using namespace std;

class RailFenceCipher {
public:
    static string Encrypt(const string &plaintext, int rails);
    static string Decrypt(const string &ciphertext, int rails);
};
