class LRUCache {
public:
int cap;
list<int> dll;
map<int,pair<list<int>::iterator,int>> cache;

    LRUCache(int capacity) {
    cap=capacity;
    }
    void mostRecentlyUsed(int key){
        dll.erase(cache[key].first);

        dll.push_front(key);

        cache[key].first=dll.begin();
    }

    int get(int key) {
        if(cache.find(key)==cache.end()) return -1;

        mostRecentlyUsed(key);

        return cache[key].second;

    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            cache[key].second=value;
            mostRecentlyUsed(key);
        }
        else{
            dll.push_front(key);

            cache[key]={dll.begin(),value};
            cap--;
        }

        if(cap<0){
            int key_for_deleting=dll.back();
            cache.erase(key_for_deleting);
            dll.pop_back();
            cap++;

        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */