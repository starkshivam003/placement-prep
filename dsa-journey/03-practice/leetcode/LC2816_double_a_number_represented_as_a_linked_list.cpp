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
    ListNode* doubleIt(ListNode* head) {
        ListNode *p,*q;
        p=head->next;
        q=head;
        head->next=NULL;
        while(p){
            q=p;
            p=p->next;
            q->next=head;
            head=q;
        }
        int carry=0;
        p=head;
        while(p){
            int total=p->val*2+carry;
            p->val=total%10;
            carry=total/10;
            q=p;
            p=p->next;
        }
        if(carry!=0){
            q->next= new ListNode(carry);
        }
        p=head->next;
        q=head;
        head->next=NULL;
        while(p){
            q=p;
            p=p->next;
            q->next=head;
            head=q;
        }
        return head;
    }
};
