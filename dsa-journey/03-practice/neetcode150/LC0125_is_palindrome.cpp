#include <iostream>
using namespace std;

/*
LC0125: Valid Palindrome
Difficulty: Easy
*/

/*
My First Approach: Create another string of only alpha-numeric characters, count their length then run the loop till half mark checking if the present characters matches with its counterpart or not.

Time Complexity: O(n)
Space Complexity: O(n)

Solution:
class Solution {
public:
    bool isPalindrome(string s) {
        int n=0;
        string A = "";
        for(int i=0;s[i]!='\0';i++){
            if(s[i]>64 && s[i]<91){
                A.append(char(s[i]+32));
            }
            A.append(s[i]);
        }
        for(int i=0;A[i]!='\0';i++){
            n++;
        }
        if((n==0)||(n==1)){
            return true;
        }
        for(int i=0;i<=((n-1)/2);i++){
            if(s[i]!=s[n-1-i]){
                return false;
            }
        }
        return true;
    }
};


Learnings: I had a few logical flaws which I overlooked. Need to dry test on paper before submitting. Also learned else-if is not the same as separate if blocks when conditions are mutually exclusive.
*/

/*
My Corrected Code:
*/
class Solution {
public:
    bool isPalindrome(string &s) {
        int n=0;
        string A = "";
        for(int i=0;s[i]!='\0';i++){
            if(s[i]>64 && s[i]<91){
                A.push_back(char(s[i]+32));
            }
            else if(s[i]>96 && s[i]<123){
                A.push_back(s[i]);
            }
            else if(s[i]>47 && s[i]<58){
                A.push_back(s[i]);
            }
        }
        for(int i=0;A[i]!='\0';i++){
            n++;
        }
        if((n==0)||(n==1)){
            return true;
        }
        for(int i=0;i<(n/2);i++){
            if(A[i]!=A[n-1-i]){
                return false;
            }
        }
        return true;
    }
};


int main(){
    string B;
    cout<<"Type your string here: ";
    cin>>B;
    Solution sol;
    if (sol.isPalindrome(B)){
        cout<<"Yes, it is a palindrome"<<endl;
    }
    else{
        cout<<"No, it is not a palindrome"<<endl;
    }
    return 0;
}