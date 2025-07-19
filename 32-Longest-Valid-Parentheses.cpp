#include <iostream>
#include <forward_list>

using namespace std;

int longestValidParentheses(string);

int main() {
    string s = "(()";
    cout << longestValidParentheses(s) << endl;

    s = ")()())";
    cout << longestValidParentheses(s) << endl;

    s = "";
    cout << longestValidParentheses(s);
}

int longestValidParentheses(string s) {
    int n = 0, max_length = 0;
    forward_list<char> queue;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
            queue.push_front(s[i]);
            n += 1;
        } else if (!queue.empty()) {
            if (s[i] == '}') {
                if (queue.front() != '{') {
                    max_length = (max_length > n ? max_length : n);
                    queue.clear();
                    n = 0;
                }
            } else if (s[i] == ')') {
                if (queue.front() != '(') {
                    max_length = (max_length > n ? max_length : n);
                    queue.clear();
                    n = 0;                }
            } else {
                if (queue.front() != '[') {
                    max_length = (max_length > n ? max_length : n);
                    queue.clear();
                    n = 0;                }
            }
            queue.pop_front();
            n += 1;
        } else {
            max_length = (max_length > n ? max_length : n);
            queue.clear();
            n = 0;  
        }
    }

    max_length = (max_length > n ? max_length : n);

    while (!queue.empty()) {
        max_length -= 1;
        queue.pop_front();
    }

    return max_length;
}