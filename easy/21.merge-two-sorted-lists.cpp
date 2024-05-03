class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode* result = list1;
        if (list1 -> val < list2 -> val) {
            list1 = list1 -> next;
        } else {
            result = list2;
            list2 = list2 -> next;
        }

        ListNode* temp = result;

        while(list1 != nullptr && list2 != nullptr) {
            if (list1 -> val < list2 -> val) {
                temp -> next = list1;
                list1 = list1 -> next;
            } else {
                temp -> next = list2;
                list2 = list2 -> next;
            }
            temp = temp -> next;
        }

        if (list1 == nullptr) {
            temp -> next = list2;
        } else if (list2 == nullptr) {
            temp -> next = list1;
        }

        return result;
    }
};