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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            if(head->val==val){
                return NULL;
            }
            return head;
        }
        ListNode *p,*q;
        p=head->next;
        q=head;
        while(p->next){
            if(p->val==val){
                q->next=p->next;
                p=p->next;
            }
            else{
                q=p;
                p=p->next;
            }
        }
        if(p->val==val){
            q->next=NULL;
        }
        if(head->val==val){
            if(head->next==NULL){
                head=NULL;
            }
            else{
                head=head->next;
            }
        }
        return head;
    }
};
