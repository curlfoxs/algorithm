class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n=0;
        ListNode* r=head;
        while(r)
            ++n, r=r->next;
        n/=2;
        while(n--)
            head=head->next;
        return head;
    }
};
