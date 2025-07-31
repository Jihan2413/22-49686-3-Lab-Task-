#include <iostream>
using namespace std;

int main() {
    ifstream file("Lab Task3.txt");
    char word[100];

    if (!file) {
        cout << "File not found!" << endl;
        return 0;
    }

    while (file >> word) {
        // Check for simple keywords
        if (strcmp(word, "int") == 0 || strcmp(word, "float") == 0 || strcmp(word, "if") == 0 || strcmp(word, "else") == 0) {
            cout << word << " : Keyword" << endl;
        }
        // Check for simple operators
        else if (strcmp(word, "+") == 0 || strcmp(word, "-") == 0 || strcmp(word, "*") == 0 || strcmp(word, "=") == 0) {
            cout << word << " : Operator" << endl;
        }
        // Check if first letter is alphabet or underscore = identifier
        else if (isalpha(word[0]) || word[0] == '_') {
            cout << word << " : Identifier" << endl;
        }
        else {
            cout << word << " : Unknown" << endl;
        }
    }

    file.close();
    return 0;
}
