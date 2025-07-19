#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode*, ListNode*);

int main() {
    ListNode* list_1 = new ListNode(1);
    list_1 -> next = new ListNode(2);
    
    ListNode* list_2 = new ListNode(2);
    list_2 -> next = new ListNode(4);

    ListNode *mergedList = mergeTwoLists(list_1, list_2);

    while (mergedList != nullptr) {
        cout << mergedList -> val << " ";
        mergedList = mergedList -> next;
    }
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* res = new ListNode();  // узел, который будет указывать на начало односвязного списка
    ListNode* nums = res;
    
    while (list1 != nullptr && list2 != nullptr) {
        if (list1 -> val > list2 -> val)  {
            nums -> next = list2;
            list2 = list2 -> next;
        } else {
            nums -> next = list1;
            list1 = list1 -> next;
        }
        nums = nums -> next;
    }

    while (list1 != nullptr) {
        nums -> next = list1;
        list1 = list1 -> next;
        nums = nums -> next;
    }

    while (list2 != nullptr) {
        nums -> next = list2;
        list2 = list2 -> next;
        nums = nums -> next;
    }

    return res -> next;
}