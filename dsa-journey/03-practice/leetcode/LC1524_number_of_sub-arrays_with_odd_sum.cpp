class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int e=1;
        int o=0;
        int n=(int)arr.size();
        /*for(int i=0;i<n;i++){
            if(arr[i]%2) o++;
            else e++;
        }*/
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum%2) o++;
            else e++;
        }
        long long ans=(long long)e*o;
        ans=ans%((long long)(1e9+7));
        return (int)ans;
    }
};
