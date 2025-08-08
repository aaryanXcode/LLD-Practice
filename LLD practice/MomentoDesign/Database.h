#pragma once
#include<bits/stdc++.h>
#include "DatabaseMemento.h"
using namespace std;
class Database{
    private:
        map<string,string> records;
    public:
        void insert(const string& key, const string& value){
            records[key] = value;
            cout<<"Inserted: "<< key << " = " << value <<endl;
       }

       void update(const string& key, const string& value){
            if(records.find(key) != records.end()){
                records[key] = value;
                cout<< "Updates: " << key << " = " << value << endl;
            }else{
                cout << "key not found for update: " << key <<endl;
            }
       }

       void remove(const string& key){
            auto it = records.find(key);
            if(it!=records.end()){
                records.erase(it);
                cout << "Deleted: " << key << endl;
            }
            else{
                cout<< "Key not found for deletion: "<< key <<endl;
            }
       }

       //create momento to create a backup of current state
       DatabaseMemento* createMomento(){
            cout<< "Creating database backup..." <<endl;
            return new DatabaseMemento(records);
       }

       void restoreFromMomento(DatabaseMemento& momento){
            records = momento.getState();
            cout<<"Databse restored fron backup"<<endl;
       }

       void displayRecords(){
            cout<<"\n--- current databse state ---" << endl;
            if(records.empty()){
                cout<<"Databse is empty"<<endl;
            }
            else{
                for(const auto& record : records){
                    cout<< record.first << " = " << record.second <<endl;
                }
            }
            cout<< "----------------------------------\n" << endl;

       }



};