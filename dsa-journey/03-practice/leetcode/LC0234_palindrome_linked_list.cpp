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
//attempt 1: failed some cases
/*class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL){
            return true;
        }
        int A[10]={0};
        ListNode *p;
        p=head;
        while(p){
            if(A[p->val]==0){
                A[p->val]++;
            }
            else{
                A[p->val]--;
            }
            p=p->next;
        }
        int count=0;
        for(int i=0;i<10;i++){
            if(A[i]!=0){
                count+=A[i];
            }
        }
        if(count>1){
            return false;
        }
        return true;
    }
};*/
//attempt 2: TC-O(n) and SC-O(n)
/*class Solution{
private:
    vector<int> stk;
    int top;
    void push(int val){
        stk.push_back(val);
        top++;
    }
    int pop(){
        int val=stk[top];
        stk.pop_back();
        top--;
        return val;
    }
    bool isEmpty(){
        return top==-1;
    }
public:
    Solution(){
        top=-1;
    }
    bool isPalindrome(ListNode* head){
        if(head->next==NULL){
            return true;
        }
        ListNode *p;
        p=head;
        int l=0;
        while(p){
            l++;
            p=p->next;
        }
        p=head;
        int i=0;
        while(i<l/2){
            push(p->val);
            p=p->next;
            i++;
        }
        if(l%2!=0){
            p=p->next;
            i++;
        }
        while(i!=l){
            if(!isEmpty()){
                if(pop()!=p->val){
                    return false;
                }
                else{
                    p=p->next;
                    i++;
                }
            }
            else{
                if(i<l){
                    return false;
                }
            }
        }
        return true;
    }
};*/
//attempt 3: TC-O(n) and SC-O(1)
class Solution {
public:
    bool isPalindrome(ListNode* head){
        if(head->next==NULL){
            return true;
        }
        ListNode *p,*q,*halfHead,*r;
        p=head->next;
        q=head;
        while(p&&p->next){
            p=p->next->next;
            q=q->next;
        }
        halfHead=q->next;
        q->next=NULL;
        q=halfHead->next;
        halfHead->next=NULL;
        while(q){
            r=q;
            q=q->next;
            r->next=halfHead;
            halfHead=r;
        }
        p=head;
        q=halfHead;
        while(p&&q){
            if(p->val!=q->val){
                return false;
            }
            p=p->next;
            q=q->next;
        }
        return true;
    }
};
