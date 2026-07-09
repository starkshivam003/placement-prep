/*
LC002: Add Two Numbers
Difficulty: Medium

Approach: I used two-pointers and added the digits in one-pass.
Time Complexity: O(m+n)
Space Complexity: O(1) 
*/

#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p,*q;
        p=l1;
        q=l2;
        int carry=0,curr_sum=0;
        while(p!=NULL && q!=NULL){
            curr_sum= (p->val+q->val+ carry)%10;
            carry=(p->val+q->val+ carry)/10;
            p->val=curr_sum;
            q->val=curr_sum;
            if(p->next==NULL && q->next==NULL){
                if(carry>0){
                    ListNode *r = new ListNode(carry);
                    p->next=r;
                }
                return l1;
            }
            p=p->next;
            q=q->next;
        }
        if(p==NULL && q!=NULL){
            while(q){
                curr_sum=(q->val+carry)%10;
                carry=(q->val+carry)/10;
                q->val=curr_sum;
                if(q->next==NULL){
                    if(carry>0){
                        ListNode *a = new ListNode(carry);
                        q->next=a;
                    }
                    return l2;
                }
                q=q->next;
            }            
        }
        else if(p!=NULL && q==NULL){
            while(p){
                curr_sum=(p->val+carry)%10;
                carry=(p->val+carry)/10;
                p->val=curr_sum;
                if(p->next==NULL){
                    if(carry>0){
                        ListNode *b = new ListNode(carry);
                        p->next=b;
                    }
                    return l1;
                }
                p=p->next;
            }            
        }
        return l1;
    }
};

int main(){
    ListNode l1(0), l2(3);
    Solution sol;
    cout<<(sol.addTwoNumbers(&l1,&l2))->val<<endl;
    return 0;
}
