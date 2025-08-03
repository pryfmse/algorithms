#include <iostream>
#include <vector>

using namespace std;

vector<int> sortArray(vector<int>&);
void quicksort(vector<int>&, int, int);

int main() {
    vector<int> nums = {5, 2, 6, 3, 1};
    vector<int> res = sortArray(nums);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    nums = {5, 1, 1, 2, 0, 0};
    res = sortArray(nums);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}

vector<int> sortArray(vector<int>& nums) {
    quicksort(nums, 0, nums.size() - 1);

    return nums;
}

void quicksort(vector<int> &nums, int left, int right) {
    if (left >= right) { return; }

    int l = left, r = right, middle = nums[(r + l) / 2];

    while (l <= r) {
        while (nums[l] < middle) { l++; }
        while (nums[r] > middle) { r--; }

        if (l <= r) {
            swap(nums[r], nums[l]); 
            l++;
            r--;
        }
    }

    quicksort(nums, left, l - 1);
    quicksort(nums, l, right);

}
