class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x=0, sum=0, i=1;
        while (n>0){
            if(n%10!=0){
                x=x+((n%10)*i);
                i=10*i;
            }
            sum=sum+(n%10);
            n=n/10;
        }
        return sum*x;
    }
};
