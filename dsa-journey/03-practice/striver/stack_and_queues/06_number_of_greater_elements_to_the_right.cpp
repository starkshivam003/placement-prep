class Solution {
public:
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        vector<int> ans;
        for(int i=0;i<(int)indices.size();i++){
            int count=0;
            for(int j=indices[i]+1;j<(int)arr.size();j++){
                if(arr[j]>arr[indices[i]]){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
/*
class Fenwick {
    vector<int> tree;
    int n;
public:
    Fenwick(int size){ n = size; tree.assign(n+1, 0); }
    void update(int i, int delta){
        for(; i<=n; i += i & (-i)) tree[i] += delta;
    }
    int query(int i){ // prefix sum of [1..i]
        int s = 0;
        for(; i>0; i -= i & (-i)) s += tree[i];
        return s;
    }
};

class Solution {
public:
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        int n = arr.size();
        vector<int> sorted_vals = arr;
        sort(sorted_vals.begin(), sorted_vals.end());
        sorted_vals.erase(unique(sorted_vals.begin(), sorted_vals.end()), sorted_vals.end());
        auto rank = [&](int v){
            return (int)(lower_bound(sorted_vals.begin(), sorted_vals.end(), v) - sorted_vals.begin()) + 1;
        };
        int m = sorted_vals.size();

        Fenwick fen(m);
        vector<int> countGreater(n);

        for(int i = n-1; i >= 0; i--){
            int r = rank(arr[i]);
            int totalInserted = fen.query(m);
            int lessOrEqual = fen.query(r);
            countGreater[i] = totalInserted - lessOrEqual;
            fen.update(r, 1);
        }

        vector<int> ans;
        for(int idx : indices) ans.push_back(countGreater[idx]);
        return ans;
    }
};
*/
