class Solution{
    public:
    int leafNode(trie_node_t *pNode)
    {
        return (pNode->value != 0);
    }
     
    int isItFreeNode(trie_node_t *pNode)
    {
        int i;
        for(i = 0; i < ALPHABET_SIZE; i++)
        {
            if( pNode->children[i] )
                return 0;
        }
     
        return 1;
    }
    
    void remove(trie_node_t *root,char key[], int level,int len)
    {
        // If tree is empty
        if (!root)
            return;
      
        // If last character of key is being processed
        if (level == len) {
      
            // This node is no more end of word after
            // removal of given key
            if (root->value)
                root->value = 0;
      
            // If given is not prefix of any other word
            if (isItFreeNode(root)) {
                 
                root = NULL;
            }
            return;
        }
      
        // If not last character, recur for the child
        // obtained using ASCII value
        int index =INDEX( key[level+1] );
        remove(root->children[index], key, level + 1, len);
      
        // If root does not have any child (its only child got
        // deleted), and it is not end of another word.
        if (isItFreeNode(root) && root->value == false) {
            
            root = NULL;
        }
    }
      
    
     
    void deleteKey(trie_node_t *root, char key[])
    {
        int len = strlen(key);
     
        if( len > 0 )
        {
            remove(root->children[INDEX(key[0])], key, 0, len-1);
        }
    }
};
