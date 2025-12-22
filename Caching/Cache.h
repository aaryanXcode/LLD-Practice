#include <stdexcept>
template<typename K, typename V>
class Cache {
    private:
        ICacheStorage<K, V>* storage;
        IEvictionPolicy<K>* evictionPolicy;

    public:
        Cache(ICacheStorage<K, V>* s, IEvictionPolicy<K>* e): storage(s), evictionPolicy(e) {}

        V get(K key) {
            if (!storage->contains(key)) {
                throw std::runtime_error("Key not found");
            }
            evictionPolicy->keyAccessed(key);
            return storage->get(key);
        }

        void put(K key, V value) {
            if (storage->contains(key)) {
                storage->put(key, value);
                evictionPolicy->keyAccessed(key);
                return;
            }
            if (storage->isFull()) {
                K evict = evictionPolicy->evictKey();
                storage->remove(evict);
            }
            storage->put(key, value);
            evictionPolicy->keyAccessed(key);
        }
        
};