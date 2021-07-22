class MapSum {
public:
    class trie{
      public:
        bool isend;
        int num;
        trie* child[26];
        trie(){
            num = 0;
            isend = false;
            for(int i=0;i<26;i++){
                child[i] = NULL;
            }
        }
    };
    /** Initialize your data structure here. */
    
    trie* root;
    MapSum() {
        root = new trie();
    }
    
    void insert(string key, int val) {
        trie* curr = root;
        for(int i=0;i<key.length();i++){
            int ind = key[i] - 'a';
            if(curr->child[ind]==NULL){
                curr->child[ind] = new trie();
            }
            curr = curr->child[ind];
            // cout<<curr->num<<endl;
            
        }
        curr->isend =  true;
        curr->num = val;
    }
    
    int dfs(trie* curr){
        // defination of the question
        int res = 0;
        if(curr->isend==true){
            res+=curr->num;
        }
        for(int i=0;i<26;i++){
            if(curr->child[i]){
                res+=dfs(curr->child[i]);
            }
        }
        return res;
    }
    int sum(string prefix) {
        trie* curr = root;
        for(int i=0;i<prefix.length();i++){
            int ind = prefix[i]-'a';
            if(curr->child[ind]==NULL){
                return 0;
            }
            curr = curr->child[ind];
        }
        return dfs(curr);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
