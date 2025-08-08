#pragma once
#include "DatabaseMemento.h"
#include "Database.h"
class TransactionManager{
    private:
        DatabaseMemento* backup;
    public:
        TransactionManager() : backup(nullptr){}

        ~TransactionManager(){
            if(backup){
                delete backup;
            }
        }

        //begin transaction
        void beginTransaction(Database& db){
            cout<< "=== begin transaction === "<<endl;
            if(backup){
                delete backup;
            }
            backup = db.createMomento();
        }

        void commitTransaction(){
            cout<< "=== commit transaction ===" << endl;
            if(backup){
                delete backup;
                backup = nullptr;
            }
            cout<<"transaction successfull"<<endl;
        }


        void rollBack(Database& db){
            cout<< "=== Rollback transaction ==="<<endl;
            if(backup){
                db.restoreFromMomento(*backup);
                delete backup;
                backup = nullptr;
                cout<< "transaction rolled back"<< endl;
            }else{
                cout<<"no backup available fo roll back"<<endl;
            }
        }

};