#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int num1 = (l1 != nullptr) ? l1 -> val : 0;
            int num2 = (l2 != nullptr) ? l2 -> val : 0;

            int sum = num1 + num2 + carry;
            carry = sum / 10;

            ListNode* newNode = new ListNode(sum % 10);
            tail -> next = newNode;
            tail = tail -> next;

            l1 = (l1 != nullptr) ? l1 -> next : nullptr;
            l2 = (l2 != nullptr) ? l2 -> next : nullptr;
        }

        return head -> next;
    }
};

void printList(ListNode* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    cout << "Resultant List: ";
    printList(result);

    return 0;
}
