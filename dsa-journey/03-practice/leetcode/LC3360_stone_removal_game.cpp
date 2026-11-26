class Solution {
public:
    bool canAliceWin(int n) {
        int take=10;
        char A=1;
        while(take>0&&n>=take){
            n-=take;
            take-=1;
            A=1-A;
        }
        return !A;
    }
};
