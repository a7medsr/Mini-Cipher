#include "PlayfairCipher.h"
#include <cctype>

vector<vector<char>> PlayfairCipher::createMatrix(const string &key) {
    vector<vector<char>> matrix(5, vector<char>(5));
    string uniqueKey = "";
    for (char ch : key) {
        ch = tolower(ch);
        if (uniqueKey.find(ch) == string::npos && ch != 'j')
            uniqueKey += ch;
    }
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        if (uniqueKey.find(ch) == string::npos && ch != 'j')
            uniqueKey += ch;
    }
    int idx = 0;
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            matrix[i][j] = uniqueKey[idx++];
    return matrix;
}

pair<int, int> PlayfairCipher::findPosition(const vector<vector<char>> &matrix, char ch) {
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            if (matrix[i][j] == ch)
                return {i, j};
    return {-1, -1};
}

string PlayfairCipher::Encrypt(const string &plaintext, const string &key) {
    string processedText;
    for (char ch : plaintext) {
        ch = tolower(ch);
        if (ch == 'j') ch = 'i';
        if (isalpha(ch)) processedText += ch;
    }
    if (processedText.length() % 2 != 0)
        processedText += 'x';

    vector<vector<char>> matrix = createMatrix(key);
    string ciphertext = "";

    for (size_t i = 0; i < processedText.length(); i += 2) {
        char a = processedText[i];
        char b = processedText[i + 1];
        auto [row1, col1] = findPosition(matrix, a);
        auto [row2, col2] = findPosition(matrix, b);

        if (row1 == row2) {
            ciphertext += matrix[row1][(col1 + 1) % 5];
            ciphertext += matrix[row2][(col2 + 1) % 5];
        } else if (col1 == col2) {
            ciphertext += matrix[(row1 + 1) % 5][col1];
            ciphertext += matrix[(row2 + 1) % 5][col2];
        } else {
            ciphertext += matrix[row1][col2];
            ciphertext += matrix[row2][col1];
        }
    }

    return ciphertext;
}

string PlayfairCipher::Decrypt(const string &ciphertext, const string &key) {
    vector<vector<char>> matrix = createMatrix(key);
    string plaintext = "";

    for (size_t i = 0; i < ciphertext.length(); i += 2) {
        char a = tolower(ciphertext[i]);
        char b = tolower(ciphertext[i + 1]);
        auto [row1, col1] = findPosition(matrix, a);
        auto [row2, col2] = findPosition(matrix, b);

        if (row1 == row2) {
            plaintext += matrix[row1][(col1 - 1 + 5) % 5];
            plaintext += matrix[row2][(col2 - 1 + 5) % 5];
        } else if (col1 == col2) {
            plaintext += matrix[(row1 - 1 + 5) % 5][col1];
            plaintext += matrix[(row2 - 1 + 5) % 5][col2];
        } else {
            plaintext += matrix[row1][col2];
            plaintext += matrix[row2][col1];
        }
    }

    return plaintext;
}
