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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        int l=0;
        ListNode *p;
        p=head;
        while(p){
            l++;
            p=p->next;
        }
        p=head;
        if(l==k){
            p=head->next;
            if(l==2){
                head->next=NULL;
                p->next=head;
                head=p;
                return head;
            }
            int flag=0;
            ListNode *q;
            while(p->next){
                head->next=p->next;
                if(flag==0){
                    p->next=head;
                    flag++;
                }
                else{
                    p->next=q;
                }
                q=p;
                p=head->next;
            }
            p->next=q;
            head->next=NULL;
            head=p;
            return head;
        }
        ListNode *q,*r,*s;
        q=p;
        r=p;
        for(int i=1;i<k;i++){
            p=q->next;
            q->next=p->next;
            p->next=r;
            r=p;
        }
        head=p;
        s=q;
        l-=k;
        while(l>=k){
            p=s->next;
            q=p;
            r=p;
            for(int i=1;i<k;i++){
                p=q->next;
                q->next=p->next;
                p->next=r;
                r=p;
                s->next=p;
            }
            s=q;
            l-=k;
        }
        return head;
    }
};
