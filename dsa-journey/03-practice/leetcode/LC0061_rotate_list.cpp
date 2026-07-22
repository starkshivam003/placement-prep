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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        int l=0;
        ListNode *p,*q;
        p=head;
        while(p){
            l++;
            p=p->next;
        }
        p=head;
        k=k%l;
        if(k==0){
            return head;
        }
        for(int i=1;i<(l-k);i++){
            p=p->next;
        }
        q=p;
        while(q->next){
            q=q->next;
        }
        q->next=head;
        head=p->next;
        p->next=NULL;
        return head;
    }
};
