#include<bits/stdc++.h>
#include "ICacheStorage.h"
#include "IEvictionPolicy.h"
#include "InMemoryStorage.h"
#include "LRUEvictionPolicyImpl.h"
#include "Cache.h"
using namespace std;

int main(){
    auto* storage = new InMemoryStorage<int, string>(2);
    //ICacheStorage<int, string>* storage = new InMemoryStorage<int, string>(2);
    IEvictionPolicy<int>* policy = new LRUCacheEvictionPolicyImpl<int>();
    Cache<int, string> cache(storage, policy);

    cache.put(1, "A");
    cache.put(2, "B");
    cache.get(1);
    cache.put(3, "C"); // evicts key 2

    storage->show();
    return 0;
}