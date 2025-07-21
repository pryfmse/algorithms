#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

string minWindow(string, string);

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    // cout << minWindow(s, t);

    s = "cabwefgewcwaefgcf";
    t = "cae";
    cout << endl << minWindow(s, t);
}

string minWindow(string s, string t) {
    if (s.size() < t.size()) return "";

    unordered_map<char, int> map;
    for (char el: t) {
        map[el]++;
    }

    int l = 0, k = t.size(), min_length = s.size(), correct_l = 0;
    for (int r = 0; r < s.size(); r++) {
        if (map.find(s[r]) != map.end()) {
            map[s[r]]--;
            if (map[s[r]] >= 0) k--;
        }

        while (k == 0) {
            if (r - l < min_length) {
                min_length = r - l;
                correct_l = l;
            }
            if (map.find(s[l]) != map.end()) {
                if (map[s[l]] >= 0) break;
                map[s[l]]++;
            }
            l++;
        }
    }
    return (k == 0 ? s.substr(correct_l, min_length + 1) : "");
}
