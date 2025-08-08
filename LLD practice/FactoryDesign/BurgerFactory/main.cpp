#include<bits/stdc++.h>
#include "BurgerFactory.h"
using namespace std;
int main() {
    string type;
    cout << "Enter type of burger (basic/standard/premium): ";
    cin >> type;

    Burger* burger = BurgerFactory::createBurger(type);
    if (!burger) {
        cout << "Invalid burger type!" << endl;
        return 1;
    }

    burger->prepare();
    delete burger;
    return 0;
}