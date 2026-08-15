class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> A;
        A.push_back(1);
        for(int i=0;i<rowIndex;i++){
            A.push_back(1);
            int n=(int)A.size();
            for(int j=(n-2);j>0;j--){
                A[j]+=A[j-1];
            }
        }
        return A;
    }
};
