#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int, vector<int>&);

int main() {
    int target = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << minSubArrayLen(target, nums) << endl;

    target = 4;
    nums = {1, 4, 4};
    cout << minSubArrayLen(target, nums) << endl;

    target = 11;
    nums = {1, 1, 1, 1, 1, 1, 1, 1};
    cout << minSubArrayLen(target, nums);
}

int minSubArrayLen(int target, vector<int>& nums) {
    int r = 0, l = 0, sum_now = 0, min_count = nums.size(), res = 0;

    for (r = 0; r < nums.size(); r++) {
        sum_now += nums[r];

        while (sum_now >= target) {
            min_count = min(r - l + 1, min_count);
            res = sum_now;
            l++;
            sum_now -= nums[l - 1];
        }
    }

    return (res == 0 ? 0 : min_count);
}
