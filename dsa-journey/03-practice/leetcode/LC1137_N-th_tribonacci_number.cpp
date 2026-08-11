class Solution {
public:
    int A[38]={0};
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n<3) return 1;
        if(A[n]!=0){
            return A[n];
        }
        A[n]=tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
        return A[n];
    }
};
