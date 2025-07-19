#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &, int);

int main()
{
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    cout << "index = " << search(nums, target) << endl;

    nums = {-1, 0, 3, 5, 9, 12};
    target = 2;
    cout << "index = " << search(nums, target) << endl;
}

int search(vector<int> &nums, int target) {
    int right = nums.size() - 1, left = 0, middle = (nums.size() - left) / 2;

    while (right != left)
    {
        if (nums[middle] == target) {
            return middle;
        } else if (nums[middle] > target) {
            right = middle - 1;
            middle = left + (right - left) / 2;
        } else {
            left = middle + 1;
            middle = left + (right - left) / 2;
        }
    }

    return -1;
}
