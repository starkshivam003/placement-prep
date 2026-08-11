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

 //attempt 1: O(n) time, O(1) space but 3 loops
/*class Solution {
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
};*/
//attempt 2: single pass
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        if(head->val>4){
            head=new ListNode(0,head);
        }
        ListNode *p;
        p=head;
        while(p){
            int carry=(p->next&&p->next->val>4)?1:0;
            p->val=(p->val*2+carry)%10;
            p=p->next;
        }
        return head;
    }
};
