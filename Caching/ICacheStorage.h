#pragma once
template<typename K, typename V>
class ICacheStorage{
    public:
        virtual V get(K key) = 0;
        virtual void put(K key, V value) = 0;
        virtual bool isFull() = 0;
        virtual void remove(K key) = 0;
        virtual bool contains(K key) = 0;
        virtual ~ICacheStorage(){}
};
