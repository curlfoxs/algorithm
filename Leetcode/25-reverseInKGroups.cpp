/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)
            return head;
        ListNode* hn=new ListNode;
        hn->next=head;
        ListNode* pl=hn, *l=head, *p, *r;
        while(l) {
            r=l;
            int len=0;
            while(r)
                r=r->next, ++len;
            if(len<k) {
                pl->next=l;
                break;
            }
            r=l, p=nullptr;
            for(int i=0; i<k; ++i) {
                ListNode* tp=r->next;
                r->next=p;
                p=r;
                r=tp;
            }
            pl->next=p;
            pl=l;
            l=r;
        }
        return hn->next;
    }
};
