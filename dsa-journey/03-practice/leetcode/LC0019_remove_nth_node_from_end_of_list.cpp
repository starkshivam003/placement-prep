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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=0;
        ListNode *p;
        p=head;
        while(p!=NULL){
            l++;
            p=p->next;
        }
        p=head;
        if(l==1){
            return NULL;
        }
        if(l==n){
            head=head->next;
        }
        for(int i=1;i<(l-n);i++){
            p=p->next;
        }
        p->next=p->next->next;
        return head;
    }
};
