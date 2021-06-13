class RandomizedSet {
public:
    vector<int>nums;
    unordered_map<int,int>ump;
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(ump.find(val)!=ump.end()){
            return false;
        }
        
        ump[val]=nums.size();
        nums.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(ump.find(val)==ump.end()){
            return false;
        }
        int num = nums.back();
        nums[ump[val]] = num;
        ump[num] = ump[val];
        nums.pop_back();
        ump.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
