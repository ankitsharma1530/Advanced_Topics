class trie{
    public:
        bool isend ;
        trie* child[26];
        trie(){
            isend = false;
            for(int i=0;i<26;i++){
                child[i] = NULL;
            }
        }
};
    trie* root;
    void insert(string s){
        trie* curr = root;
        for(int i=0;i<s.length();i++){
            int ind = s[i]-'a';
            if(curr->child[ind]==NULL){
                curr->child[ind] = new trie();
            }
            curr = curr->child[ind];
        }
        if(curr!=root) curr->isend = true;
    }


    bool search(string s){
        trie* curr = root;
        // int c = 0;
        for(int i=0;i<s.length();i++){
            int ind = s[i]-'a';
            if(curr->child[ind]==NULL){
                return false;
            }
            curr = curr->child[ind];
        }
        return (curr->isend);
    }

    bool helper(string s,int count){
        if(count>1 and search(s)){
            return true;
        }
        for(int i=0;i<s.length();i++){
            string left = s.substr(0,i+1);
            string right = s.substr(i+1);
            if(search(left) and helper(right,count+1)){
                return true;
            }
        }
        return false;
    }

    int solve(vector<string>& words) {
        //insert all strings
        root = new trie();
        for(auto x:words){
            insert(x);
        }
        int count = 0;
        for(auto x:words){
            if(helper(x,1)){
                count++;
            }
        }
        return count;
    }
