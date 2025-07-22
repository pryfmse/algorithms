#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>&, int);

int main() {
    vector<int> nums = {1, 3};
    int target = 0;
    cout << searchInsert(nums, target);

    nums = {1, 3, 5, 6};
    target = 5;
    cout << endl << searchInsert(nums, target);

    nums = {1, 3, 5, 6};
    target = 7;
    cout << endl << searchInsert(nums, target);
}

int searchInsert(vector<int>& nums, int target) {
    int r = nums.size() - 1, l = 0, middle = (r) / 2;

    while (r > l) {
        if (nums[middle] == target) {
            return middle;
        } else if (nums[middle] < target) {
            l = middle + 1;
        } else {
            r = max(0, middle - 1);
        }
        middle = (r - l) / 2 + l;
    }

    return (nums[r] >= target ? r : r + 1);
}
