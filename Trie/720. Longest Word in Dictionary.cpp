class Solution {
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
    Solution(){
        // constructor of solution class made by me
        root = new trie();
    }
    void insert(string s){
        // start from root
        trie* curr = root;
        for(int i=0;i<s.length();i++){
            int ind = s[i]-'a';
            if(curr->child[ind]==NULL){
                curr->child[ind] = new trie();
            }
            curr = curr->child[ind];
        }
        curr->isend = true;
    }
    
    bool search(string s){
        trie* curr = root;
        int count = 0;
        for(int i=0;i<s.length();i++){
            int ind = s[i]-'a';
            if(curr->child[ind]==NULL){
                return false;
            }
            if(curr->child[ind]->isend){
                count++;
            }
            curr = curr->child[ind];
        }
        return count==s.length();
    }
    
    string longestWord(vector<string>& words) {
        // first of all we will insert all these strings in trie
        for(auto x:words){
            insert(x);
        }
        
        // now we will search for string 
        string res= "";
        for(auto x:words){
            if(res.length()>x.length()){
                continue;
            }
            else if(search(x)){
                // case for lexographically order output
                if(res.length()==x.length())
                    res = min(res,x);
                else
                    res = x;
            }
        }
        return res;
    }
};
