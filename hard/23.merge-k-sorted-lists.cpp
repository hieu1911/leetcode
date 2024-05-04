class Solution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b){
            return a -> val > b -> val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != nullptr) pq.push(lists[i]);
        }

        ListNode* res = new ListNode(0);
        ListNode* tmp = res;

        while (pq.size() > 0) {
            ListNode* curr = pq.top();
            pq.pop();
            tmp -> next = curr;
            tmp = tmp -> next;

            if (curr -> next) pq.push(curr -> next);
        }

        return res -> next;
    }
};