#include <iostream>
#include <vector>

using namespace std;

vector<int> runningSum(vector<int>&);

int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> res = runningSum(nums);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}

vector<int> runningSum(vector<int>& nums) {
    vector<int> res;
    res.push_back(nums[0]);

    for (int i = 1; i < nums.size(); i++) {
        res.push_back(res[i - 1] + nums[i]);
    }

    return res;
}