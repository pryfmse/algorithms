#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>&);

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> res = threeSum(nums);

    for (int i = 0; i < res.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "] ";
    }
}

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int sum, left, right;
    vector<vector<int>> res;

    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        left = i + 1;
        right = nums.size() - 1;

        while (left < right) {
            sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                res.push_back({nums[i], nums[left], nums[right]});
                
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return res;
} 
