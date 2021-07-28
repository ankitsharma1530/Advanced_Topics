class Solution {
public:
    class trie{
      public:
        int isend;
        trie* child[26];
        trie(){
            isend = 0;
            for(int i=0;i<26;i++){
                child[i] = NULL;
            }
        }
    };
    trie* root;
    Solution(){
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
        curr->isend = 1;
    }
    void search(vector<vector<char>>& board,int i,int j,int n,int m,string temp,
                vector<string>& res,trie* curr){
        if(board[i][j]=='.'){
            return;
        }
        temp.push_back(board[i][j]);
        
        if(curr->isend>0){
            //if string found
            res.push_back(temp);
            curr->isend-=1;
        }
        
        char c = board[i][j];
        board[i][j] = '.'; // mark it as visited
        if(i+1<n and board[i+1][j]!='.' and curr->child[board[i+1][j]-'a']!=NULL)
            search(board,i+1,j,n,m,temp,res,curr->child[board[i+1][j]-'a']);
        if(i-1>=0 and board[i-1][j]!='.' and curr->child[board[i-1][j]-'a']!=NULL)
            search(board,i-1,j,n,m,temp,res,curr->child[board[i-1][j]-'a']);
        if(j+1<m and board[i][j+1]!='.' and curr->child[board[i][j+1]-'a']!=NULL)
            search(board,i,j+1,n,m,temp,res,curr->child[board[i][j+1]-'a']);
        if(j-1>=0 and board[i][j-1]!='.' and curr->child[board[i][j-1]-'a']!=NULL)
            search(board,i,j-1,n,m,temp,res,curr->child[board[i][j-1]-'a']);
        board[i][j] = c; // backtrack
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // insert
        for(auto x:words){
            insert(x);
        }
        vector<string>res;
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(root->child[board[i][j]-'a']!=NULL){
                    search(board,i,j,n,m,"",res,root->child[board[i][j]-'a']);
                }
            }
        }
        return res;
    }
};
