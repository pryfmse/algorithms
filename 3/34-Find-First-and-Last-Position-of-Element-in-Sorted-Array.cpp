#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>&, int);
int right(vector<int>&, int);
int left(vector<int>&, int);

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    
    vector<int> res = searchRange(nums, target);
    for (int i = 0; i < res.size(); i++) { cout << res[i] << " "; }
    cout << endl;

    nums = {5, 7, 7, 8, 8, 10};
    target = 6;
    
    res = searchRange(nums, target);
    for (int i = 0; i < res.size(); i++) { cout << res[i] << " "; }
    cout << endl;

    nums = {};
    target = 0;
    
    res = searchRange(nums, target);
    for (int i = 0; i < res.size(); i++) { cout << res[i] << " "; }
    cout << endl;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int l = left(nums, target), r = right(nums, target);
    return {l, r};
}

int left(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1, middle = r / 2, res = -1;

    while (l <= r) {
        if (nums[middle] == target) {
            res = middle;
            r = middle - 1;
            middle = (r - l) / 2 + l;
            continue;
        }

        if (nums[middle] > target) {
            r = middle - 1;
        } else {
            l = middle + 1;
        }
        middle = (r - l) / 2 + l;
    }

    return res;
}

int right(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1, middle = r / 2, res = -1;

    while (l <= r) {
        if (nums[middle] == target) {
            res = middle;
            l = middle + 1;
            middle = (r - l) / 2 + l;
            continue;
        }

        if (nums[middle] > target) {
            r = middle - 1;
        } else {
            l = middle + 1;
        }
        middle = (r - l) / 2 + l;
    }

    return res;
}
