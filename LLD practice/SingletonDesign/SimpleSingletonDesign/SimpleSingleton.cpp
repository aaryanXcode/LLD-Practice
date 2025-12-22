#include<bits/stdc++.h>
using namespace std;

class SimpleSingleton{
    private: 
        static SimpleSingleton* instance;
        static mutex mtx;
        SimpleSingleton(){
            cout<<"SimpleSingleton new object created"<<endl;
        }
    public:
        
        static SimpleSingleton* getInstance(){
            if(instance==nullptr){
                lock_guard<mutex> lock(mtx);
                if(instance==nullptr){
                    instance = new SimpleSingleton();
                    return instance;
                }
            }
            return instance;
        }
        
};

SimpleSingleton* SimpleSingleton::instance = nullptr;
mutex SimpleSingleton::mtx;
//SimpleSingleton* SimpleSingleton::instance = new SimpleSingleton(); eager initializatio while initializing the main process


int main(){
    SimpleSingleton* obj1 = SimpleSingleton::getInstance();
    SimpleSingleton* obj2 = SimpleSingleton::getInstance();
    cout<<(obj1==obj2)<<endl;
}