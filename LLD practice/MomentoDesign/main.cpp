#include "Database.h"
#include "Transactionmanager.h"
#include "DatabaseMemento.h"

int main(){
    
    Database db;
    TransactionManager txManager;
   
    //success scenario
    txManager.beginTransaction(db);
    db.insert("user1", "Aditya");
    db.insert("user2", "Rohit");
    txManager.commitTransaction();

    db.displayRecords();

    // Failed scenario
    txManager.beginTransaction(db);
    db.insert("user3", "Saurav");
    db.insert("user4", "Manish");

    db.displayRecords();
    
    // Some error -> Rollback
    cout << "ERROR: Something went wrong during transaction!" << endl;
    txManager.rollBack(db);
    
    db.displayRecords();
    
    return 0;

}