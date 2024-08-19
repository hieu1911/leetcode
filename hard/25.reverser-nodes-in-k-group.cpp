class Solution {
private:
    std::pair<ListNode*, ListNode*> reverseList(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        for (int i = 0; i < k; i++) {
            if (curr == nullptr) break;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return {prev, curr};
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* ptr = dummy;

        while (ptr != nullptr) {
            ListNode* tracker = ptr;

            for (int i = 0; i < k && tracker != nullptr; i++) {
                tracker = tracker->next;
            }

            if (tracker == nullptr) break;

            auto reversedData = reverseList(ptr->next, k);

            ListNode* prev = reversedData.first;
            ListNode* curr = reversedData.second;

            ListNode* lastNodeOfReversedGroup = ptr->next;

            lastNodeOfReversedGroup->next = curr;
            ptr->next = prev;
            ptr = lastNodeOfReversedGroup;
        }

        return dummy->next;
    }
};
