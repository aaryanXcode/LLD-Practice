#include <list>
#include <unordered_map>
#include "IEvictionPolicy.h"

template<typename K>
class LRUCacheEvictionPolicyImpl : public IEvictionPolicy<K>{
    private:
        std::list<K> dll;
        std::unordered_map<K, typename std::list<K>::iterator> mp;

    public:
        void keyAccessed(K key) override {
            if (mp.find(key) != mp.end()) {
                dll.erase(mp[key]);
            }
            dll.push_front(key);
            mp[key] = dll.begin();
        }

        K evictKey() override {
            K key = dll.back();
            dll.pop_back();
            mp.erase(key);
            return key;
        }
};