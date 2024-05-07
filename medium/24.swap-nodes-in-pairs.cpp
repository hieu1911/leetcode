class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) return head;

        ListNode* left = head;
        ListNode* mid = head -> next;
        ListNode* res = mid;

        while (mid != nullptr) {
            if (mid -> next == nullptr) {
                left -> next = nullptr;
                mid -> next = left;
                return res;
            } else {
                ListNode* right = mid -> next;
                mid -> next = left;

                if (right -> next != nullptr) {
                    left -> next = right -> next;
                } else {
                    left -> next = right;
                }

                left = right;
                mid = left -> next;
            }
        }

        return res;
    }
};