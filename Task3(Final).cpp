#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;

int main() {
    ifstream fin("Task3(Final).txt"); // file containing program
    string word;
    char c;

    string keywords[] = {"int","float","double","char","if","else","while","for","return","void","main"};
    string operators = "+-*/=%<>!";

    while (fin.get(c)) {
        if (isalnum(c) || c == '_') {
            word += c; // collect word
        } else {
            if (!word.empty()) {
                // check if keyword
                bool isKeyword = false;
                for (string k : keywords) {
                    if (word == k) {
                        cout << word << " : Keyword\n";
                        isKeyword = true;
                        break;
                    }
                }
                if (!isKeyword) {
                    // check identifier
                    bool valid = true;
                    if (!isalpha(word[0]) && word[0] != '_') valid = false;
                    else {
                        for (char d : word) {
                            if (!isalnum(d) && d != '_') valid = false;
                        }
                    }
                    if (valid) cout << word << " : Identifier\n";
                    else cout << word << " : Invalid Identifier\n";
                }
                word.clear();
            }

            // check operator
            if (operators.find(c) != string::npos) {
                cout << c << " : Operator\n";
            }
        }
    }
    fin.close();
    return 0;
}

