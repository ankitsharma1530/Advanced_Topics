class LRUCache {
public:
    deque<int>dq; // this is our cache memory
    // most recently used will be in front and less recently used will be at last
    
    unordered_map<int,int>ump;    // this will tell us the index of our element and also this will tell us wether that element is present in our cache or not
    
    int given_size ; // size of our cache memory
    LRUCache(int capacity) {
        given_size = capacity;
    }
    
    int get(int key) {
        // if our element is not present then return -1
        if(ump.find(key)==ump.end()){
            return -1;
        }
        // If found we erase that element by making sure the relative locations of the other elements are intact.

        
        deque<int>::iterator it = dq.begin();
        while(*it!=key){
            it++;
        }
        dq.erase(it);
        dq.push_front(key);
        return ump[key]; // this will return the value present at the key
    }
    
    void put(int key, int value) {
        /*
1. If the element is found in the cache we erase it and put it back to the front(as         it becomed the most recently used element).
2. If the element is not found there are 2 cases to look for:
    Case 2a: if the cache size if full erase the last element and place the new                 element at the front of the cache.
    Case 2b: if the cache size is not full we simply place the element at the right             location of the previously recently used element.
   */
        if(ump.find(key)==ump.end()){
            if(given_size==dq.size()){
                int last = dq.back();
                dq.pop_back();
                ump.erase(last);
            }
        }
        else{
            deque<int>::iterator it=dq.begin();
            while(*it!=key)it++;
            dq.erase(it);
            ump.erase(key);
        }
        dq.push_front(key);
        ump[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
