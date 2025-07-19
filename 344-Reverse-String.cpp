#include <iostream>
#include <vector>

using namespace std;

void reverseString(vector<char>&);

int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    reverseString(s);
    
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << " ";
    }
}

void reverseString(vector<char>& s) {
    int l = 0, r = s.size() - 1;

    while (l < r) {
        swap(s[l], s[r]);
        l++;
        r--;
    }
}
