class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = new ListNode(0);
        temp -> next = head;
        ListNode* first = temp;
        ListNode* second = temp;

        for (int i = 0; i <= n; ++i) {
            second = second -> next;
        }
        
        while (second != nullptr) {
            second = second -> next;
            first = first -> next;
        }

        ListNode* del = first -> next;
        first -> next = first -> next -> next;

        delete del;

        return temp -> next;
    }
};