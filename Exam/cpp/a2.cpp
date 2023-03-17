#include <iostream>
#include <string>
#include <vector>

using namespace std;
// Function to convert a string to "alternating case" for every other word
// Function to convert a string to "alternating case" for every other word
void makeAlternatingCase(string& str) {
    bool capitalize_next = true;
    for (int i = 0; i < str.size(); i++) {
        if (isalpha(str[i])) {
            if (capitalize_next) {
                str[i] = toupper(str[i]);
            }
            else {
                str[i] = tolower(str[i]);
            }
            capitalize_next = !capitalize_next;
        }
        else if (isspace(str[i])) {
            capitalize_next = true;
        }
    }
}




