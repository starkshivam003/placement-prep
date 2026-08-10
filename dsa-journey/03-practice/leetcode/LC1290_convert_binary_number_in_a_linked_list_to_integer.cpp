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

 // all the solutions take O(n) time and O(1) space

 //attmept 1: two pass
/*class Solution {
public:
    int getDecimalValue(ListNode* head) {
        if(head->next==NULL){
            return (head->val)*1;
        }
        ListNode *p,*q;
        p=head->next;
        head->next=NULL;
        while(p){
            q=p;
            p=p->next;
            q->next=head;
            head=q;
        }
        p=head;
        int i=1;
        int value=0;
        while(p){
            value+=((p->val)*i);
            i*=2;
            p=p->next;
        }
        return value;
    }
};*/
//attempt 2: single pass, bit shift method 1
/*class Solution{
public:
    int getDecimalValue(ListNode* head){
        ListNode *p;
        p=head;
        int value=0;
        while(p){
            value=(value*2)+(p->val);
            p=p->next;
        }
        return value;
    }
};*/
//attempt 3: single pass, bit shift Method 2
class Solution{
public:
    int getDecimalValue(ListNode* head){
        ListNode *p;
        p=head;
        int value=0;
        while(p){
            value=((value<<1)|(p->val));
            p=p->next;
        }
        return value;
    }
};
