class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1==0){
            if(n2%2==0){
                return double((double(nums2[(n2/2)-1])+double(nums2[(n2/2)]))/2);
            }
            else{
                return double(nums2[(n2-1)/2]);
            }
        }
        if(n2==0){
            if(n1%2==0){
                return double((double(nums1[(n1/2)-1])+double(nums1[(n1/2)]))/2);
            }
            else{
                return double(nums1[(n1-1)/2]);
            }
        }
        int i=0,j=0,k=0;
        int s=(n1+n2);
        double current = 0.0, prev=0.0;
        if(s%2!=0){
            while(k<=s/2){
                if(i<n1){
                    if(j>=n2 || nums1[i]<=nums2[j]){
                        current=double(nums1[i++]);
                    }
                    else{
                        current=double(nums2[j++]);
                    }
                }
                else{
                    current=double(nums2[j++]);
                }
                k++;
            }
            return current;
        }
        else{
            while(k<=s/2){
                prev=current;
                if(i<n1){
                    if(j>=n2 || nums1[i]<=nums2[j]){
                        current=double(nums1[i++]);
                    }
                    else{
                        current=double(nums2[j++]);
                    }
                }
                else{
                    current=double(nums2[j++]);
                }
                k++;
            }
            return (current+prev)/2.0;
        }
    }
};
