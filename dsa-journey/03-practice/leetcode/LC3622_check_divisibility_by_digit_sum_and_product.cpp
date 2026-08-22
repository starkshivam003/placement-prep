class Solution {
public:
    bool checkDivisibility(int n) {
        int digsum=0;
        int prod=1;
        int a=n;
        while(n>0){
            int pop=n%10;
            n/=10;
            digsum+=pop;
            prod*=pop;
        }
        return (a%(prod+digsum))==0;
    }
};
