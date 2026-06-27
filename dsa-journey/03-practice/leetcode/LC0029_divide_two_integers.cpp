/*
LC0029: Divide Two Integers
Difficulty: Medium

My Code:
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==0 || (abs(dividend)<abs(divisor))){
            return 0;
        }
        if(dividend>0 && divisor>0){
            int i=0;
            while((dividend-divisor)>=divisor){
                dividend -= divisor;
                i++;
            }
            return i+1;
        }
        if(dividend>0 && divisor<0){
            int i=0;
            while((dividend+divisor)>=abs(divisor)){
                dividend+=divisor;
                i++;
            }
            return -(i+1);
        }
        if(dividend<0 && divisor>0){
            int i=0;
            while(abs(dividend+divisor)>=divisor){
                dividend+=divisor;
                i++;
            }
            return -(i+1);
        }
        if(dividend<0 && divisor<0){
            int i=0;
            while((abs(dividend)-abs(divisor))>=abs(divisor)){
                dividend+=abs(divisor);
                i++;
            }
            return i+1;
        }
        return 0;
    }
};

Time Complexity: O(log n)
Space Complexity: O(1)

Learning: Use of different int datatypes like long, unsigned int, etc. Use of conditionals. Need to learn the C++ syntax properly.
*/

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;

        long dvd = abs((long)dividend);
        long dvs = abs((long)divisor);
        int sign = (dividend > 0) == (divisor > 0) ? 1 : -1;
        long result = 0;

        while(dvd >= dvs){
            long temp = dvs;
            long multiple = 1;
            while(dvd >= (temp << 1)){
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            result += multiple;
        }

        return sign * result;
    }
}; 

int main(){
    long int dividend, divisor;
    cout<<"Dividend: ";
    cin>>dividend;
    cout<<"Divisor: ";
    cin>>divisor;
    Solution sol;
    cout<<sol.divide(dividend,divisor)<<endl;
}
