#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>&);

int main() {
    vector<int> nums = {1, 1, 2};
    int res = removeDuplicates(nums);

    for (int i = 0; i < res; i++) {
        cout << nums[i] << " ";
    }
}

int removeDuplicates(vector<int>& nums) {
    int a = 0;

    for (int b = 1; b < nums.size(); b++) {
        if (nums[a] != nums[b]) {
            a++;
            nums[a] = nums[b];
        }
    }
    return a + 1;
}
