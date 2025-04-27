#include "RailFenceCipher.h"

string RailFenceCipher::Encrypt(const string &plaintext, int rails) {
    if (rails <= 1) return plaintext;

    vector<string> fence(rails);
    int rail = 0;
    int direction = 1;

    for (char ch : plaintext) {
        fence[rail] += ch;
        rail += direction;
        if (rail == 0 || rail == rails - 1)
            direction *= -1;
    }

    string ciphertext;
    for (const string &row : fence)
        ciphertext += row;

    return ciphertext;
}

string RailFenceCipher::Decrypt(const string &ciphertext, int rails) {
    if (rails <= 1) return ciphertext;

    vector<int> pos(ciphertext.length(), 0);
    int rail = 0, direction = 1;
    for (int i = 0; i < ciphertext.length(); ++i) {
        pos[i] = rail;
        rail += direction;
        if (rail == 0 || rail == rails - 1)
            direction *= -1;
    }

    vector<string> rows(rails);
    vector<int> counts(rails, 0);
    for (int r : pos) counts[r]++;

    vector<int> start(rails, 0);
    for (int i = 1; i < rails; ++i)
        start[i] = start[i-1] + counts[i-1];

    string plaintext(ciphertext.length(), ' ');
    vector<int> indices = start;
    for (int i = 0; i < ciphertext.length(); ++i) {
        plaintext[i] = ciphertext[indices[pos[i]]++];
    }

    return plaintext;
}
