class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1[0]=='0' || num2[0]=='0'){
            return "0";
        }
        int n1=num1.size();
        int n2=num2.size();
        vector<int> result(n1+n2,0);
        for(int i=n1-1;i>-1;i--){
            int digit1=num1[i]-'0';
            for(int j=n2-1;j>-1;j--){
                int digit2=num2[j]-'0';
                int multi=digit1*digit2;
                int unit_place=i+j+1;
                int tens_place=i+j;
                int sum = multi + result[unit_place];
                result[unit_place]=sum%10;
                result[tens_place]+=sum/10;
            }
        }
        string finale;
        int i=0;
        while(i<result.size() && result[i]==0){
            i++;
        }
        for(;i<result.size();i++){
            finale+=result[i]+48;
        }
        return finale;
    }
};
