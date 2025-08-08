#pragma once
#include "IMediator.h"
#include "IColleague.h"
class ChatMediator:public IMediator{
    vector<IColleague*> allUser;

    public:
        ChatMediator(){
            
        }

        void registerColleague(IColleague* user) override {
        // Check if user with same name is already registered
            for (auto existingUser : allUser) {
                if(existingUser->getName() == user->getName()) return;
            }
            allUser.push_back(user);
        }

        void send(const std::string& from, const std::string& msg) override {
            for (auto user : allUser) {
                if (user->getName() != from) {
                    user->receive(from, msg); // Deliver to everyone except sender
                }
            }
        }

        void sendPrivate(const std::string& from, const std::string& to, const std::string& msg) override {
            for (auto user : allUser) {
                if (user->getName() == to) {
                    user->receive(from, msg); // Deliver to intended recipient only
                    break;
                }
            }
        }

        const vector<IColleague*>& getAllUsers() const {
            return allUser;
        }


};