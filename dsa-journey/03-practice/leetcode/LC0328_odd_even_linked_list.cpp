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
        ListNode *p,*evenTail,*evenHead;
        evenHead=head->next;
        evenTail=head;
        p=evenHead;
        while(p){
            evenTail->next=p->next;
            if(evenTail->next){
                evenTail=p->next;
            }
            else{
                break;
            }
            p->next=evenTail->next;
            if(p->next){
                p=p->next;
            }
            else{
                break;
            }
        }
        evenTail->next=evenHead;
        return head;
    }
};
