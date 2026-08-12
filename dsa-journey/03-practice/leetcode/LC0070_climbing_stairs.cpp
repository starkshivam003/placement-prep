class Solution {
public:
    int climbStairs(int n) {
        static int A[46]={0};
        static bool built=false;
        A[1]=1;
        A[2]=2;
        if(!built){
            for(int i=3;i<46;i++){
                A[i]=A[i-1]+A[i-2];
            }
        }
        return A[n];
    }
};
