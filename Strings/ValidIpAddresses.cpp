#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
    The most important thing which I learnt here was substr function of string class
    which takes in input args as start index and length of the substring.
*/

bool isValid(string s) {
    int i = 0, number = 0;
    if(s.length() > 1 && s[0] == '0') return false;
    while(i < s.length()) {
        number = number*10 + s[i] - '0';
        ++i;
    }
   // cout << number << endl;
    return number < 256 && number >= 0;
}

void ValidIpAddresses(string input) {
    int n = input.size();
    for(size_t i = 1; i < n && i < 4; ++i) {
        string first = input.substr(0, i);
        if(isValid(first)) {
            for(size_t j = 1; i+j < n && j < 4; ++j) {
                string second = input.substr(i, j);
                if(isValid(second)) {
                    for(size_t k=1; i+j+k < n && k < 4; ++k) {
                        string third = input.substr(i+j, k), forth = input.substr(i+j+k);
                        if(isValid(third) && isValid(forth)) {
                            cout << first << "." << second << "." << third << "." << forth << endl;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    string s;
    cin >> s;
    ValidIpAddresses(s);
}