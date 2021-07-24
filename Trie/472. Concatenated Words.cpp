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
        root= new trie();
    }
    void insert(string s){
        trie* curr = root;
        for(int i=0;i<s.length();i++){
            int ind = s[i] - 'a';
            if(curr->child[ind]==NULL){
                curr->child[ind] = new trie();
            }
            curr = curr->child[ind];
        }
        curr->isend = true;
    }
    
    bool help(string s){
        trie* curr = root;
        for(int i=0;i<s.length();i++){
            int ind = s[i]-'a';
            if(curr->child[ind]==NULL){
                return false;
            }
            curr=curr->child[ind];
        }
        return curr->isend;
    }
    bool search(string s,int count){
        // A concatenated word is defined as a string that is comprised entirely            of at least two shorter words in the given array.
        if(count>1 and help(s)){
            return true;
        }
        for(int i=0;i<s.length()-1;i++){
            string l = s.substr(0,i+1);
            string r = s.substr(i+1);
            if(help(l)){
                if(search(r,count+1))
                    return true;
            }
        }
        return false;
        
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string>res;
        for(auto x:words){
            if(x.length()!=0)
                insert(x);
        }
        for(auto x:words){
            if(x.length()!=0){
                if(search(x,1)){
                    res.push_back(x);
                }
            }
        }
        return res;
    }
};
