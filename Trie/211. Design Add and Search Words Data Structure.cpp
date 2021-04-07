class WordDictionary {
public:
    /** Initialize your data structure here. */
    struct trienode{
        bool isend;
        trienode* child[26];
    };
    trienode* root;
    WordDictionary() {
        //initiliaze
        root = new trienode();
        for(int i=0;i<26;i++)
        {
            root->child[i]=NULL;
        }
        root->isend = false;
    }
    
    void addWord(string word) {
        trienode* curr = root;
        for(int i=0;i<word.length();i++)
        {
            int ind = word[i]-'a';
            if(curr->child[ind]==NULL)
            {
                curr->child[ind] = new trienode();
            }
            curr=curr->child[ind]; // for moving forward
        }
        // after the insertion of the string
        curr->isend = true; 
    }
    bool dfs(string word, int ind , trienode* curr)
    {
        if(ind==word.length())
        {
            return curr->isend;
        }
        char ch = word[ind];
        if(ch!='.')
        {
            if(curr->child[ch-'a']!=NULL)
            {
                return dfs(word,ind+1,curr->child[ch-'a']);
            }
        }
        else
        {
            // as we don not know what the . will represent 
            // hence we try for all characters present after the curr node
            // and check for the answer from every child node
            for(int i=0;i<26;i++)
            {
                if(curr->child[i]!=NULL)
                {
                    // checking ans from every child node
                    if(dfs(word,ind+1,curr->child[i])==true)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool search(string word) {
        trienode* curr = root;
        // we will search that word with dfs
        return dfs(word,0,curr);
    }
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
