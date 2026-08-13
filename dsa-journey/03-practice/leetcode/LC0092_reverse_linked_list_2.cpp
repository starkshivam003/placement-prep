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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL||head->next==NULL||left==right){
            return head;
        }
        ListNode *q,*r,*s;
        s=new ListNode(0,head);
        r=s;
        for(int i=1;i<left;i++){
            r=r->next;
        }
        q=r->next;
        for(int i=0;i<right-left;i++){
            ListNode *t=q->next;
            q->next=t->next;
            t->next=r->next;
            r->next=t;
        }
        return s->next;
    }
};
