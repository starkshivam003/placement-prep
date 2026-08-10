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
};
