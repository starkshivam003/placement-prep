class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> stt(wordList.begin(),wordList.end());
        if(stt.find(endWord)==stt.end()) return 0;
        queue<string> q;
        q.push(beginWord);
        stt.erase(beginWord);
        int steps=1;
        while(!q.empty()){
            int sz=(int)q.size();
            for(int i=0;i<sz;i++){
                string w=q.front();
                q.pop();
                for(int j=0;j<(int)w.size();j++){
                    char orig=w[j];
                    for(char c='a';c<='z';c++){
                        if(c==orig) continue;
                        w[j]=c;
                        if(w==endWord) return steps+1;
                        if(stt.count(w)){
                            stt.erase(w);
                            q.push(w);
                        }
                    }
                    w[j]=orig;
                }
            }
            steps++;
        }
        return 0;
    }
};
