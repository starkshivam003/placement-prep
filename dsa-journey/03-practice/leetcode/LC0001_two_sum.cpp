/*
LC0001: Two Sum
Difficulty: Easy
*/

/*
My Code: Use nested loops
Time Complexity: O(n^2)
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};

int main(){
    int n;
    cout<<"Size of the int array: ";
    cin>>n;
    vector<int> A(n);
    cout<<"Elements of Array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int target;
    cout<<"Target Integer: ";
    cin>>target;
    Solution sol;
    vector<int> indices = sol.twoSum(A,target);
    cout<<"Indices: " <<indices[0]<<" "<<indices[1]<<endl;
}