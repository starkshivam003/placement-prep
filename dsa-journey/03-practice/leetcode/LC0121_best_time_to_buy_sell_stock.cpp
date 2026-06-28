/*
LC0121: Best time to buy and sell stock
Difficulty: Easy
*/

/*
My First Code:-

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2){
            return 0;
        }
        int max_profit=prices[1]-prices[0];
        for(int i=0;i<prices.size();i++){
            for(int j=i+1;j<prices.size();i++){
                if((prices[j]-prices[i])>=max_profit){
                    max_profit=(prices[j]-prices[i]);
                }
            }
        }
        if(max_profit>0){
            return max_profit;
        }
        else{
            return 0;
        }
    }
};

Time Complexity: O(n^2)
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2){
            return 0;
        }
        int min_price=prices[0];
        int max_profit=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<min_price){
                min_price=prices[i];
            }
            else if((prices[i]-min_price)>max_profit){
                max_profit=(prices[i]-min_price);
            }
        }
        return max_profit;
    }
};

int main(){
    int n;
    Solution sol;
    cout<<"Number of Days: ";
    cin>>n;
    vector<int> A(n);
    cout<<"Give the prices: \n";
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cout<<"Max Profit: "<<sol.maxProfit(A)<<endl;
    return sol.maxProfit(A);
    
}