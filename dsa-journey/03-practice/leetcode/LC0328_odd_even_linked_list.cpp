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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL){
            return head;
        }
        ListNode *p,*q,*evenHead;
        evenHead=head->next;
        q=head;
        p=evenHead;
        while(p){
            q->next=p->next;
            if(q->next){
                q=p->next;
            }
            else{
                break;
            }
            p->next=q->next;
            if(p->next){
                p=p->next;
            }
            else{
                break;
            }
        }
        q->next=evenHead;
        return head;
    }
};
