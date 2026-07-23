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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode *p,*q;
        p=head;
        q=head;
        int y=head->next->val;
        int x=-102;
        while(p->next){
            if(p->val!=p->next->val&&p->val!=x){
                q=p;
                p=p->next;
            }
            else{
                q->next=p->next;
                x=p->val;
                //delete p;
                p=q->next;
            }
        }
        if(p->val==x){
            q->next=NULL;
        }
        if(head->next==NULL&&q==head&&head->val==y){
            return NULL;
        }
        if(head->val==y){
            head=head->next;
        }
        return head;
    }
};
