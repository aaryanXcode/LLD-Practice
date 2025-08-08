    #include<bits/stdc++.h>
    using namespace std;

    class Parent {
    public:
        Parent(int x) {
            cout << "Parent constructor: x = " << x << endl;
        }
    };

    class Child : public Parent {
    public:
        Child(int x) : Parent(x) {
            cout << "Child constructor" << endl;
        }
    };

    int main(){
        Child* c = new Child(10);

    }