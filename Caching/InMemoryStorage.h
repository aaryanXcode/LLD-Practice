#pragma once
#include<iostream>
#include <unordered_map>
#include "ICacheStorage.h"
#include "IDebugStorage.h"
template<typename K, typename V>
class InMemoryStorage : public ICacheStorage<K, V>, 
                        public IDebugStorage<K, V>{
    private:
        std::unordered_map<K, V> cachemap;
        std::size_t capacity;

    public:
        InMemoryStorage(std::size_t size): capacity(size){}

        V get(K key) override {
            return cachemap.at(key);
        }

        void put(K key, V value) override {
            cachemap[key] = value;
        }

        void remove(K key) override{
            cachemap.erase(key);
        }

        bool contains(K key) override{
            return cachemap.find(key) != cachemap.end();
        }

        bool isFull() override{
            return cachemap.size() >= capacity;
        }

        void show() override {
        std::cout << "---- Storage State ----\n";
        for (auto& [k, v] : cachemap) {
            std::cout << "key: " << k << " value: " << v << std::endl;
        }
        std::cout << "-----------------------\n";
    }
};