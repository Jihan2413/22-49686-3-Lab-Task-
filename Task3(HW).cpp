#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
   ifstream fin("Task3(HW).txt"); // file containing program
   string token;
   char c;
   string delimiters = " ;,(){}[]";
   while (fin.get(c)) {
       if (isdigit(c) || c == '.') {
           token += c; // collect numbers
       } else {
           if (!token.empty()) {
               if (token.find('.') != string::npos) cout << token << " : Real Number\n";
               else cout << token << " : Integer\n";
               token.clear();
           }
           if (delimiters.find(c) != string::npos) {
               cout << c << " : Delimiter\n";
           }
       }
   }
   fin.close();
   return 0;
}
