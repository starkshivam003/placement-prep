//attempt 1: using monotonic stack, time-O(n) and space-O(n), idea: there should be a leftwall and a dip on the left of the current wall for water to be trapped
/*

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int water=0;
        for(int i=0;i<(int)height.size();i++){
            while(!stk.empty()&&height[i]>height[stk.top()]){
                int bot=stk.top();
                stk.pop();
                if(stk.empty()) break;
                int leftwall=stk.top();
                int w=i-leftwall-1;
                int h=min(height[i],height[leftwall])-height[bot];
                water+=(w*h);
            }
            stk.push(i);
        }
        return water;
    }
};
*/
//attempt 2: using two pointers, time-O(n) and space-O(1), idea: water trapped above the block
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = (int)height.size() - 1;
        int maxLeft = 0, maxRight = 0;
        int water = 0;
        while (left < right) {
            if (height[left] <= height[right]) {
                maxLeft = max(maxLeft, height[left]);
                water += maxLeft - height[left];
                left++;
            } else {
                maxRight = max(maxRight, height[right]);
                water += maxRight - height[right];
                right--;
            }
        }
        return water;
    }
};
