class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=(int)digits.size();
        if(digits[n-1]<9){
            digits[n-1]+=1;
            return digits;
        }
        int i=n-1;
        int carry=1;
        while(carry==1&&i>=0){
            int tmp=digits[i]+carry;
            digits[i]=tmp%10;
            carry=tmp/10;
            i--;
        }
        if(carry==1){
            vector<int> ans(n+1,1);
            for(int i=1;i<n+1;i++){
                ans[i]=digits[i-1];
            }
            return ans;
        }
        return digits;
    }
};
