#include <iostream>
#include <string>
using namespace std;


string caesar_cipher(string text) {
    string result = "";
    for (char& c : text) {
        if (isalpha(c)) {
            char shift = isupper(c) ? 'A' : 'a';
            result += (c - shift + 7) % 26 + shift;
        } else {
            result += c;
        }
    }
    return result;
}


string caesar_decipher(string text) {
    string result = "";
    for (char& c : text) {
        if (isalpha(c)) {
            char shift = isupper(c) ? 'A' : 'a';
            result += (c - shift + 19) % 26 + shift;
        } else {
            result += c;
        }
    }
    return result;
}


int main() {
    string text;
    cout << "Enter text to be ciphered: ";
    getline(cin, text);
    string ciphered = caesar_cipher(text);
    cout << "Ciphered: " << ciphered << endl;
    cout << "Deciphered: " << caesar_decipher(ciphered) << endl;
    return 0;
}
