class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> A;
        for(int i=0;i<numRows;i++){
            vector<int> B(i+1,1);
            for(int j=1;j<i;j++){
                B[j]=A[i-1][j-1]+A[i-1][j];
            }
            A.push_back(B);
        }
        return A;
    }
};
