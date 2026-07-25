class Solution {
public:
    int maxProduct(int n) {
        int A[10]={0};
        while(n>0){
            A[n%10]++;
            n/=10;
        }
        int num1=0;
        int num2=0;
        for(int i=9;i>-1;i--){
            if(A[i]>0){
                num1=i;
                A[i]--;
                break;
            }
        }
        for(int i=9;i>-1;i--){
            if(A[i]>0){
                num2=i;
                break;
            }
        }
        return num1*num2;
    }
};
