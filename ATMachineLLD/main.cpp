#include "CashDispenser.h"
#include "ATM.h"
#include "Card.h"
#include "Account.h"
#include "IATMState.h"
#include <iostream>

int main() {
    std::cout << "========== ATM MACHINE LLD SYSTEM ==========\n\n";

    // Initialize Cash Dispenser with initial cash
    std::cout << "[SETUP] Initializing ATM with cash...\n";
    CashDispenser* dispenser = new CashDispenser(
        10, // ₹2000 notes (10 notes)
        20, // ₹500 notes (20 notes)
        50  // ₹100 notes (50 notes)
    );
    std::cout << "Total ATM Balance: ₹" << dispenser->getTotalCash() << "\n\n";

    // Initialize ATM with the dispenser
    std::cout << "[SETUP] Initializing ATM machine...\n";
    ATM atm(dispenser);
    std::cout << "ATM initialized successfully!\n\n";

    // Create user accounts
    std::cout << "[SETUP] Creating user accounts...\n";
    Account acc1(25000);
    Account acc2(50000);
    std::cout << "Account 1 Balance: ₹25000\n";
    std::cout << "Account 2 Balance: ₹50000\n\n";

    // Create cards
    Card card1(&acc1);
    Card card2(&acc2);

    // ========== SESSION 1: User 1 - Withdraw Cash ==========
    std::cout << "============ SESSION 1: User 1 ============\n\n";

    std::cout << "[USER 1] Step 1: Inserting card...\n";
    atm.insertCard(&card1);

    std::cout << "\n[USER 1] Step 2: Entering PIN...\n";
    atm.getCurrentState()->enterPin(&atm, 1234);

    std::cout << "\n[USER 1] Step 3: Selecting Withdraw option (option: 1)...\n";
    atm.getCurrentState()->selectOption(&atm, 1);

    std::cout << "\n[USER 1] Step 4: Withdrawing ₹5000...\n";
    atm.getCurrentState()->withdrawAmount(&atm, 5000);

    std::cout << "\n[USER 1] Step 5: Ejecting card...\n";
    atm.getCurrentState()->ejectCard(&atm);

    std::cout << "\n";

    // ========== SESSION 2: User 2 - Check Balance ==========
    std::cout << "============ SESSION 2: User 2 ============\n\n";

    std::cout << "[USER 2] Step 1: Inserting card...\n";
    atm.insertCard(&card2);

    std::cout << "\n[USER 2] Step 2: Entering PIN...\n";
    atm.getCurrentState()->enterPin(&atm, 5678);

    std::cout << "\n[USER 2] Step 3: Selecting Balance Check option (option: 2)...\n";
    atm.getCurrentState()->selectOption(&atm, 2);

    std::cout << "\n[USER 2] Step 4: Checking balance...\n";
    atm.getCurrentState()->checkBalance(&atm);

    std::cout << "\n[USER 2] Step 5: Ejecting card...\n";
    atm.getCurrentState()->ejectCard(&atm);

    std::cout << "\n";

    // ========== SESSION 3: Invalid operation sequence ==========
    std::cout << "============ SESSION 3: Invalid Operations ============\n\n";

    std::cout << "[USER 3] Attempting to withdraw without inserting card...\n";
    atm.getCurrentState()->withdrawAmount(&atm, 2000);

    std::cout << "\n[USER 3] Attempting to check balance without card...\n";
    atm.getCurrentState()->checkBalance(&atm);

    std::cout << "\n";

    // Cleanup
    std::cout << "========== SESSION SUMMARY ==========\n";
    std::cout << "Final ATM Balance: ₹" << dispenser->getTotalCash() << "\n";
    std::cout << "Account 1 Balance: ₹" << acc1.getBalance() << "\n";
    std::cout << "Account 2 Balance: ₹" << acc2.getBalance() << "\n";

    delete dispenser;

    return 0;
}
