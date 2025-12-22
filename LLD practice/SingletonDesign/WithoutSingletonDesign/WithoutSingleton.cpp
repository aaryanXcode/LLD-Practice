#include<bits/stdc++.h>
using namespace std;

class WithoutSingleton{
    public:
        WithoutSingleton(){
            cout<<"without singleton obj created"<<endl;
        }
};

int main(){
    WithoutSingleton* obj1 = new WithoutSingleton();
    WithoutSingleton* obj2 = new WithoutSingleton();
    cout<<(obj1==obj2)<<endl;
    return 0;
}