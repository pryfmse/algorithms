#include <iostream>
#include <cmath>

using namespace std;

int reverse(int);

int main() {
    int x = -123;
    cout << reverse(x);
}

int reverse(int x) {
    int res = 0;
    int MAX_INT32 = pow(2, 31) - 1, MIN_INT32 = -pow(2, 31);
    bool flag = false;
    if (x < 0) {
        flag = !flag;
        x *= -1;
    }

    while (x > 0) {
        if (!(MIN_INT32 <= res * 10 + x % 10 && res * 10 + x % 10 <= MAX_INT32)) {
            return 0;
        }
        res = res * 10 + x % 10;
        x /= 10;
    }

    if (flag) {
        res *= -1;
    }

    return res;
}