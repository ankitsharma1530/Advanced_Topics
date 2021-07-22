class SearchEngine {
    public:

    class trie{
        public:
        bool isend;
        trie* child[26];
        trie(){
            isend = false;
            for(int i=0;i<26;i++){
                child[i] = NULL;
            }
        }
    };
    trie* root;
    SearchEngine() {
        root = new trie();
    }

    void add(string word) {
        // start from root
        trie* curr = root;
        for(int i=0;i<word.length();i++){
            int ind = word[i]-'a';
            if(curr->child[ind]==NULL){
                curr->child[ind] = new trie();
            }
            curr = curr->child[ind];
        }
        curr->isend = true;
    }
    bool dfs(trie* curr, string& word ,int ind){
        if(ind==word.length()){
            // as we start from root hence we are not checking i==n-1
            // instead of this we are checking i==n
            return curr->isend;
        }
        char ch = word[ind];
        if(ch!='.'){
            // so we have only one option
            if(curr->child[ch-'a']!=NULL){
                return dfs(curr->child[ch-'a'],word,ind+1);
            }
        }
        else{
            // ch == '.'
            // now we have 26 option
            // we can match '.' with any character
            for(int i=0;i<26;i++){
                if(curr->child[i]!=NULL){
                    if(dfs(curr->child[i],word,ind+1)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool exists(string word) {
        // presence of these dots in our word led us to use dfs
        // start from root
        trie* curr = root;
        return dfs(curr,word,0);
    }
};
