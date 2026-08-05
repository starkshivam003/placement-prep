/*class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=(int)nums.size();
        k=k%n;
        if(k<n){
            vector<int> A(n);
            int j=0;
            for(int i=(n-k);i<n;i++){
                A[j++]=nums[i];
            }
            for(int i=0;i<(n-k);i++){
                A[j++]=nums[i];
            }
            for(int i=0;i<n;i++){
                nums[i]=A[i];
            }
        }        
    }
};*/
/*class Solution {
public:
    void rotate(vector<int>& nums, int k){
        int n=(int)nums.size();
        k=k%n;
        if(k<n){
            if(n>1){
                for(int i=0;i<k;i++){
                    int carry=nums[n-1];
                    for(int j=n-1;j>0;j--){
                        nums[j]=nums[j-1];
                    }
                    nums[0]=carry;
                }
            }
        }
    }
};*/
class Solution{
public:
    void rotate(vector<int>& nums, int k){
        int n=(int)nums.size();
        k=k%n;
        if(k<n){
            int i=0,j=n-1;
            while(i<j){
                int temp=nums[j];
                nums[j--]=nums[i];
                nums[i++]=temp;
            }
            i=0;
            j=k-1;
            while(i<j){
                int temp=nums[j];
                nums[j--]=nums[i];
                nums[i++]=temp;
            }
            i=k;
            j=n-1;
            while(i<j){
                int temp=nums[j];
                nums[j--]=nums[i];
                nums[i++]=temp;
            }
        }
    }
};
/*class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    void rotate(vector<int>& nums, int k) {
        int n = (int)nums.size();
        k = k % n;
        if (k == 0) return;

        int cycles = gcd(n, k);
        for (int start = 0; start < cycles; start++) {
            int current = start;
            int prevValue = nums[start];
            do {
                int next = (current + k) % n;
                int temp = nums[next];
                nums[next] = prevValue;
                prevValue = temp;
                current = next;
            } while (current != start);
        }
    }
};*/
