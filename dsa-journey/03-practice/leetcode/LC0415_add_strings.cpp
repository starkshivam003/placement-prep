class Solution {
public:
    string addStrings(string num1, string num2) {
        int n=(int)num1.size();
        int m=(int)num2.size();
        string s="";
        int i=n-1,j=m-1,carry=0;
        while(i>-1&&j>-1){
            int sum=(num1[i]-'0')+(num2[j]-'0')+carry;
            int digit=sum%10;
            carry=sum/10;
            s+=string(1,digit+'0');
            i--;
            j--;
        }
        while(i>-1){
            int sum=(num1[i]-'0')+carry;
            int digit=sum%10;
            carry=sum/10;
            s+=string(1,digit+'0');
            i--;
        }
        while(j>-1){
            int sum=(num2[j]-'0')+carry;
            int digit=sum%10;
            carry=sum/10;
            s+=string(1,digit+'0');
            j--;
        }
        if(carry!=0){
            s+=string(1,carry+'0');
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
