#include <iostream>
#include <string>
using namespace std;

int RomanCharToInt(char r) {
    switch(r) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default:
            return -1;
    }
}

int RomanToInteger(string s) {
    int n = s.length(), ans = 0;
    for(int i=0; i < n-1; ++i) {
        int current = RomanCharToInt(s[i]), next = RomanCharToInt(s[i+1]);
        if(current >= next) {
            ans += current;
        }
        else {
            ans -= current;
        }
    }
    ans += RomanCharToInt(s[n-1]);
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << RomanToInteger(s) << endl;
    return 0;
}