/*
https://oj.leetcode.com/problems/lru-cache/

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/

struct CacheEntry{
    int key;
    int value;
    CacheEntry(int k, int v) : key(k), value(v) {}
};

class LRUCache_1{
public:
    LRUCache_1(int capacity): capacity(capacity) {
    } 
    
    int get(int key) {
        if (this->cacheHash.find(key) != this->cacheHash.end()) {
            list<CacheEntry>::iterator it = cacheHash[key];
            int v = it->value;
            this->cacheList.erase(it);
            //this->cacheList.push_front(CacheEntry(key, v));
            //this->cacheHash[key] = this->cacheList.begin();
            this->cacheList.push_back(CacheEntry(key, v));
            this->cacheHash[key] = --this->cacheList.end();
            return v;
        } else {
            return -1;
        }
    }
    
    void set(int key, int value) {
        if (this->cacheHash.find(key) != this->cacheHash.end()) {
            list<CacheEntry>::iterator it = this->cacheHash[key];
            this->cacheList.erase(it);
        } else if (this->cacheList.size() == this->capacity) {
            // int k = this->cacheList.back().key;
            // this->cacheList.pop_back();
            int k = this->cacheList.front().key;
            this->cacheList.pop_front();
            this->cacheHash.erase(k);
        }
        // this->cacheList.push_front(CacheEntry(key, value));
        // this->cacheHash[key] = this->cacheList.begin();
        this->cacheList.push_back(CacheEntry(key, value));
        this->cacheHash[key] = --this->cacheList.end();
    }

private:
    list<CacheEntry> cacheList;
    unordered_map<int, list<CacheEntry>::iterator> cacheHash;
    int capacity;    
};

// optimized
class LRUCache{
public:
    LRUCache(int capacity): m_capacity(capacity) {
    } 
    
    int get(int key) {
        if (m_cacheMap.find(key) != m_cacheMap.end()) {
            MoveToHead(key);
            return m_cacheMap[key]->value;
        } else {
            return -1;
        }
    }
    
    void set(int key, int value) {
        if (m_cacheMap.find(key) != m_cacheMap.end()) {
            m_cacheMap[key]->value = value;
            MoveToHead(key);
        } else {
             if (m_cacheList.size() >= m_capacity) {
                 m_cacheMap.erase(m_cacheList.back().key);
                 m_cacheList.pop_back();
             }
             CacheEntry newEntry(key, value);
             m_cacheList.push_front(newEntry);
             m_cacheMap[key] = m_cacheList.begin();
        }
    }

private:
    list<CacheEntry> m_cacheList;
    unordered_map<int, list<CacheEntry>::iterator> m_cacheMap;
    int m_capacity;
    
    void MoveToHead(int key) {
        CacheEntry updateEntry = *m_cacheMap[key];
        m_cacheList.erase(m_cacheMap[key]);
        m_cacheList.push_front(updateEntry);
        m_cacheMap[key] = m_cacheList.begin();
    }
};
