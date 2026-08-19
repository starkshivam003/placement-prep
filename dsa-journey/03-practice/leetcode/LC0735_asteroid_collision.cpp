//attempt 1: time-O(n) space-O(n) using two monotonic stacks
/*
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=(int)asteroids.size();
        vector<int> ans;
        stack<int> stk1;
        stack<int> stk2;
        for(int i=0;i<n;i++){
            if(asteroids[i]>0){
                stk1.push(asteroids[i]);
            }
            else{
                if(!stk1.empty()){
                    if(abs(asteroids[i])<stk1.top()){
                        continue;
                    }
                    else if(abs(asteroids[i])==stk1.top()){
                        stk1.pop();
                    }
                    else{
                        int flag=0;
                        while(!stk1.empty()&&stk1.top()<abs(asteroids[i])){
                            stk1.pop();
                            if(!stk1.empty()&&stk1.top()==abs(asteroids[i])){
                                stk1.pop();
                                flag=1;
                                break;
                            }
                        }
                        if(!stk1.empty()&&stk1.top()>abs(asteroids[i])){
                            continue;
                        }
                        if(flag==0){
                            ans.emplace_back(asteroids[i]);
                        }
                    }
                }
                else{
                    ans.emplace_back(asteroids[i]);
                }
            }
        }
        while(!stk1.empty()){
            stk2.push(stk1.top());
            stk1.pop();
        }
        while(!stk2.empty()){
            ans.emplace_back(stk2.top());
            stk2.pop();
        }
        return ans;
    }
};
*/
//attempt 2: time-O(n) space-O(n) using monotonic stack but optimised version
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(int a:asteroids){
            bool alive = true;
            while(alive&&a<0&&!ans.empty()&&ans.back()>0){
                if(ans.back()<-a){
                    ans.pop_back();
                }
                else if(ans.back()==-a){
                    ans.pop_back();
                    alive=false;
                }
                else{
                    alive=false;
                }
            }
            if(alive){
                ans.emplace_back(a);
            }
        }
        return ans;
    }
};
