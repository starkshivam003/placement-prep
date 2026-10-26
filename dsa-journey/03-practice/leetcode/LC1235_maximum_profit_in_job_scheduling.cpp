class Solution {
public:
    int f(int i,vector<array<int,3>>& jobs,vector<int>& start,vector<int>& memo,int& n){
        if(i==n) return 0;
        if(memo[i]!=-1) return memo[i];
        int skip=f(i+1,jobs,start,memo,n);
        int next=lower_bound(start.begin(),start.end(),jobs[i][1])-start.begin();
        int take=jobs[i][2]+f(next,jobs,start,memo,n);
        memo[i]=max(take,skip);
        return memo[i];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=(int)startTime.size();
        vector<array<int,3>> jobs(n);
        vector<int> start(n);
        vector<int> memo(n,-1);
        for(int i=0;i<n;i++) jobs[i]={startTime[i],endTime[i],profit[i]};
        sort(jobs.begin(),jobs.end());
        for(int i=0;i<n;i++) start[i]=jobs[i][0];
        return f(0,jobs,start,memo,n);
    }
};


class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=(int)startTime.size();
        vector<array<int,3>> jobs(n);
        vector<int> start(n);
        vector<int> dp(n+1,0);
        for(int i=0;i<n;i++) jobs[i]={startTime[i],endTime[i],profit[i]};
        sort(jobs.begin(),jobs.end());
        for(int i=0;i<n;i++) start[i]=jobs[i][0];
        for(int i=n-1;i>=0;i--){
            int skip=dp[i+1];
            int next=lower_bound(start.begin(),start.end(),jobs[i][1])-start.begin();
            int take=jobs[i][2]+dp[next];
            dp[i]=max(take,skip);
        }
        return dp[0];
    }
};
