#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
    The eureka of this problem is to realize the pattern:
    I can precede V and X
    X can precede L and C
    C can precede D and M
*/

const vector<int> value = {1, 5, 10, 50, 100, 500, 1000};
const vector<string> symbol = {"I", "V", "X", "L", "C", "D", "M"};

string IntegerToRoman(int N) {
    if(N==0) return ""; // Base case
    int n = value.size()-1;
    string ans = "";
    while(n >= 0 && N / value[n] == 0) { 
        --n;
    }
    if(n & 1) { // n is odd (5, 50, 500)
        if(N >= value[n+1]-value[n-1]) {
            ans += symbol[n-1] + symbol[n+1] + IntegerToRoman(N-value[n+1]+value[n-1]);
        } else {
            ans += symbol[n] + IntegerToRoman(N-value[n]);
        }
    } else {
        if(n == 6) {
            ans += symbol[6] + IntegerToRoman(N-value[6]);
        } else if(N >= value[n+1]-value[n]) {
            ans += symbol[n] + symbol[n+1] + IntegerToRoman(N-value[n+1]+value[n]);
        } else {
            ans += symbol[n] + IntegerToRoman(N-value[n]);
        }
    }
    return ans;
}

int main() {
    int N;
    cin >> N;

    cout << IntegerToRoman(N);
}