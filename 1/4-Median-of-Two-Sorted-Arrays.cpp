#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>&, vector<int>&);

int main() {
    vector<int> nums1 = {1, 3}, nums2 = {2};
    cout << findMedianSortedArrays(nums1, nums2) << endl;

    nums1 = {1, 2}, nums2 = {3, 4};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // если объединить массивы, отсортировать и найти медиану, то мы не получим оптимальный алгоритм
    if (nums1.size() > nums2.size()) {
        swap(nums1, nums2);  // будем работать с меньшим по длине массивом, чтобы ускорить бинарный поиск
    }

    int r = nums1.size(), l = 0, i, j;

    while (r != l) {
        i = (r - l) / 2 + l;
        j = (nums1.size() + nums2.size() + 1) / 2 - i;

        if (i != 0 && nums1[i - 1] > nums2[j]) {
            r = i - 1;
        } else if (j != 0 && nums1[i] < nums2[j - 1]) {
            l = i + 1;
        } else {
            break;
        }
    } 

    if (r == l) {
        i = r;
        j = (nums1.size() + nums2.size() + 1) / 2 - i;
    }
    
    double max_1 = (i != 0 && j != 0 ? max(nums1[i - 1], nums2[j - 1]) : (i != 0 ? nums1[i - 1] : nums2[j - 1]));

    if ((nums1.size() + nums2.size()) % 2 == 0) {
        double min_2 = (i != nums1.size() && j != nums2.size() ? min(nums1[i], nums2[j]) : (i != nums1.size() ? nums1[i] : nums2[j]));
        return (max_1 + min_2) / 2;
    } else {
        return max_1;
    }
}
