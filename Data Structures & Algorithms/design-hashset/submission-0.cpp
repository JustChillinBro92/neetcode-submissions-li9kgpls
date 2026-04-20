class MyHashSet {
private:
    vector<bool> hashSet;
public:
    MyHashSet() {
        hashSet = vector<bool> (1000001, false);
    }
    
    void add(int key) {
        hashSet[key] = true;
    }
    
    void remove(int key) {
        if(hashSet[key]) hashSet[key] = false;
    }
    
    bool contains(int key) {
        return hashSet[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */