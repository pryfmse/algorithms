#include <iostream>
#include <vector>

using namespace std;

int shipWithinDays(vector<int>&, int);

int main() {
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    cout << shipWithinDays(weights, days);
}

int shipWithinDays(vector<int>& weights, int days) {
    int sum = 0, max_weight = 0, day = 0;

    for (int i = 0; i < weights.size(); i++) {
        sum += weights[i];
        if (max_weight < weights[i]) { max_weight = weights[i]; }
    }

    if (max_weight < (sum + days - 1) / days) { max_weight = (sum + days - 1) / days; }

    int l = max_weight, r = sum, middle = r / 2, res;
    sum = 0;

    while (l <= r) {
        for (int i = 0; i < weights.size(); i++) {
            if (sum + weights[i] > middle) {
                sum = weights[i];
                day++;
            } else {
                sum += weights[i];
            }
        }

         if (day + 1 <= days) {
            res = middle;
            r = middle - 1;
        } else {
            l = middle + 1;
        }
        middle = (r - l) / 2 + l;
        sum = 0; day = 0;
    }

    return res;

}
