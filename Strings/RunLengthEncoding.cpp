#include <iostream>
#include <string>
using namespace std;

string RunLengthEncoding(string s) {
    int n = s.length(), count = 1;
    string ans = "";
    for(int i=1; i < n; ++i) {
        if(s[i] == s[i-1]) {
            ++count;
        }
        else {
            ans += to_string(count) + s[i-1];
            count = 1;
        }
    }
    if(n > 0)
        ans += to_string(count) + s[n-1];
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << RunLengthEncoding(s);
}