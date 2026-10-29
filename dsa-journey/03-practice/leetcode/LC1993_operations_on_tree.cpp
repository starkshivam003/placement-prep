class LockingTree {
    vector<int> locked;
    vector<vector<int>> child;
    vector<int> par;
    int n;
public:
    LockingTree(vector<int>& parent) {
        n=(int)parent.size();
        par=parent;
        locked.assign(n,-1);
        child.resize(n);
        for(int i=1;i<n;i++){
            child[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if(locked[num]==-1){
            locked[num]=user;
            return true;
        }
        return false;
    }
    
    bool unlock(int num, int user) {
        if(locked[num]==user){
            locked[num]=-1;
            return true;
        }
        return false;
    }
    
    bool upgrade(int num, int user) {
        if(locked[num]!=-1) return false;
        int i=par[num];
        while(i!=-1){
            if(locked[i]!=-1) return false;
            i=par[i];
        }
        queue<int> q;
        q.push(num);
        int lockcount=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int& c:child[x]){
                if(locked[c]!=-1){
                    lockcount++;
                    locked[c]=-1;
                }
                q.push(c);
            }
        }
        if(lockcount>0) locked[num]=user;
        return lockcount>0;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
