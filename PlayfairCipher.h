#pragma once
#include <string>
#include <vector>
using namespace std;

class PlayfairCipher {
private:
    static vector<vector<char>> createMatrix(const string &key);
    static pair<int, int> findPosition(const vector<vector<char>> &matrix, char ch);

public:
    static string Encrypt(const string &plaintext, const string &key);
    static string Decrypt(const string &ciphertext, const string &key);
};
