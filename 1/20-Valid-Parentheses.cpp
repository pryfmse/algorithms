#include <iostream>
#include <forward_list>

using namespace std;

bool isValid(string);

int main() {
    string s = "([)]";
    cout << s << ":  " << (isValid(s) ? "Valid" : "NotValid") << endl;

    s = "([])";
    cout << s << ":  " << (isValid(s) ? "Valid" : "NotValid") << endl;
}

bool isValid(string s) {
    forward_list<char> queue = {s[0]};

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
            queue.push_front(s[i]);
        } else {
            if (s[i] == '}') {
                if (queue.front() != '{') {
                    return false;
                }
            } else if (s[i] == ')') {
                if (queue.front() != '(') {
                    return false;
                }
            } else {
                if (queue.front() != '[') {
                    return false;
                }
            }
            queue.pop_front();
        }
    }
    return true;
}
