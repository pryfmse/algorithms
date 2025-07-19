#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>&, int);

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> res = twoSum(nums, target);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    
}

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> checked;
    int res;

    for (int i = 0; i < nums.size(); i++) {
        res = target - nums[i];
        if (checked.find(res) != checked.end()){
            return {checked[res], i};
        }
        checked[nums[i]] = i;
    }
    return {};
}
