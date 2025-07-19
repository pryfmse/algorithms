#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>&, int);

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> res = twoSum(numbers, target);
    cout << res[0] << " " << res[1];
}

vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0, r = numbers.size() - 1;

    while (l != r) {
        if (numbers[l] + numbers[r] == target) {
            return {l + 1, r + 1};
        } else if (numbers[l] + numbers[r] > target) {
            r--;
        } else {
            l++;
        }
    }
    return {};
}
