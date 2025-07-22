#include <iostream>
#include <vector>

using namespace std;

int splitArray(vector<int>&, int);

int main() {
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    cout << splitArray(nums, k);
}

int splitArray(vector<int>& nums, int k) {
    int sum = 0, max_weight = 0, day = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (max_weight < nums[i]) { max_weight = nums[i]; }
    }

    if (max_weight < (sum + k - 1) / k) { max_weight = (sum + k - 1) / k; }

    int l = max_weight, r = sum, middle = r / 2, sum_max = 0, res;
    sum = 0;

    while (l <= r) {
        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] > middle) {
                sum_max = max(sum_max, sum);
                sum = nums[i];
                day++;
            } else {
                sum += nums[i];
            }
        }
        sum_max = max(sum_max, sum);

         if (day + 1 <= k) {
            res = sum_max;
            sum_max = 0;
            r = middle - 1;
        } else {
            l = middle + 1;
        }
        middle = (r - l) / 2 + l;
        sum = 0; day = 0;
    }

    return res;
}