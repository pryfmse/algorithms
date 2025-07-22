#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>&);

int main() {
    vector<int> nums = {3, 4, 5, 1, 2};
    // cout << findMin(nums) << endl;

    nums = {4, 5, 6, 7, 0, 1, 2};
    // cout << findMin(nums) << endl;

    nums = {11, 13, 15, 17};
    // cout << findMin(nums) << endl;

    nums = {1, 2};
    // cout << findMin(nums) << endl;

    nums = {2, 1};
    // cout << findMin(nums) << endl;

    nums = {3, 1, 2};
    cout << findMin(nums);
}

int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1, middle = r / 2;

    while (l < r) {
        if (nums[middle] <= nums[r]) {
            r = middle;
        } else {
            l = middle + 1;
        }
        middle = (r - l) / 2 + l;
    }
    return nums[l];
}
