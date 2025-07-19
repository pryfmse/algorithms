#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trap(vector<int>&);
int sum(vector<int>&);

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(height) << endl;

    height = {4, 2, 0, 3, 2, 5};
    cout << trap(height);
}

int trap(vector<int>& height) {
    vector<int> map;
    map.resize(*max_element(height.begin(), height.end()));

    int l = 0, r = height.size() - 1, n, v;
    while (l < r && height[l] == 0) l++;
    while (l < r && height[r] == 0) r--;
    
    while (l < r) {

        n = min(height[r], height[l]);

        v = r - l - 1;
        for (int i = 0; i < n; i++) { 
            map[i] = (v > map[i] ? v : map[i] - 2);
        }

        l++;
        r--;
        while (l < r && height[l] == 0) l++;
        while (l < r && height[r] == 0) r--;

    }

    if (l == r) {
        for (int i = 0; i < height[l]; i++) {
            map[i] -= 1;
        }
    }

    return sum(map);

}

int sum(vector<int> &map) {
    int summa = 0;
    for (auto elem: map) {
        summa += elem;
    }

    return summa;
}
