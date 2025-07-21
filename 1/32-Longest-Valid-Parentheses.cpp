#include <iostream>
#include <forward_list>

using namespace std;

int longestValidParentheses(string);

int main() {
    string s = "(()(((()";
    cout << longestValidParentheses(s) << endl;

    s = ")()())";
    cout << longestValidParentheses(s) << endl;

    s = ")(()(()(((())(((((()()))((((()()(()()())())())()))()()()())(())()()(((()))))()((()))(((())()((()()())((())))(())))())((()())()()((()((())))))((()(((((()((()))(()()(())))((()))()))())";
    cout << longestValidParentheses(s);
}

int longestValidParentheses(string s) {
    forward_list<int> queue;
    queue.push_front(-1);
    int max_res = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            queue.push_front(i);
        } else {
            queue.pop_front();
            if (queue.empty()) {
                queue.push_front(i);
            } else {
                max_res = max(max_res, i - queue.front());
            }
        }
    }

    return max_res;
}
