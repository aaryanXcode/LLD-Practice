#include "ChatMediator.h"
#include "User.h"

int main() {
    ChatMediator* mediator = new ChatMediator();

    User* alice = new User("Alice", mediator);
    User* bob = new User("Bob", mediator);
    User* charlie = new User("Charlie", mediator);

    alice->send("Hello everyone!");
    bob->sendPrivate("Charlie", "Hey Charlie, secret message.");
    
    vector<IColleague*> allUser =  mediator->getAllUsers();
    for(auto user : allUser){
        cout<<user->getName()<<",";
    }
    cout<<endl;
    delete alice;
    delete bob;
    delete charlie;
    delete mediator;

    return 0;
}
