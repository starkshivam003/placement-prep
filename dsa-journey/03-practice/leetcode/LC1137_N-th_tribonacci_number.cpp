//attempt 1: using recursion and meomization
/*class Solution {
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
};*/
//attempt 2: using a static array
class Solution {
public:
    int tribonacci(int n) {
        static int A[38];
        static bool built = false;
        if(!built){
            A[0]=0; A[1]=1; A[2]=1;
            for(int i=3; i<38; i++){
                A[i] = A[i-1]+A[i-2]+A[i-3];
            }
            built = true;
        }
        return A[n];
    }
};
