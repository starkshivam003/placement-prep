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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *p;
        ListNode *q;
        ListNode *r;
        p=head;
        q=head->next;
        p->next=q->next;
        q->next=p;
        r=p;
        head=q;
        p=p->next;
        if(p==NULL || p->next==NULL){
            return head;
        }
        q=p->next;

        while(q){
            p->next=q->next;
            q->next=p;
            r->next=q;
            r=p;
            p=p->next;
            if(p==NULL || p->next==NULL){
                return head;
            }
            q=p->next;
        }
        return head;
    }
};
