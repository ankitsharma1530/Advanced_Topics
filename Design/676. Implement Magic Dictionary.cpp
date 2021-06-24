// new thing to learn
// whenever we had to find string that is derived from our current string 
// then we will always iterate for each index of current string and for each index we will check all the 26 characters
// remember this


class MagicDictionary {
public:
    //total complexity -> O(n*sizeof(dictionary)) + O(len(searchWord)*26*n)
    
    unordered_set<string>st;
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        // time complexity -> O(n)
        for(auto& x:dictionary){
            st.insert(x);
        }
    }
    
    bool search(string searchWord) {
        // O(26*len(searchWord))
        for(int i=0;i<searchWord.length();i++){
            string temp = searchWord;
            for(char c='a';c<='z';c++){
                temp[i] = c;
                // if it is same string
                if(temp==searchWord){
                    continue;
                }
                if(st.find(temp)!=st.end()){
                    return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
