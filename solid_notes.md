```javascript


// SOLID Principles: Quick Revision with WRONG vs RIGHT Code Examples

/*
 * S - Single Responsibility Principle (SRP)
 * A class should have only one reason to change.

*/

// ❌ WRONG
class OrderManager {
    void placeOrder();
    void sendEmail();
    void generateInyvoice();
};

// ✅ RIGHT
class OrderManager {
    void placeOrder();
};

class EmailService {
    void sendEmail();
};

class InvoiceService {
    void generateInvoice();
};

/*
 * O - Open/Closed Principle (OCP)
 * Classes should be open for extension, closed for modification.
*/

// ❌ WRONG
class PaymentProcessor {
    void process(string method) {
        if (method == "UPI") { /* process upi */ }
        else if (method == "Card") { /* process card */ }
    }
};

// ✅ RIGHT
class PaymentMethod {
public:
    virtual void pay() = 0;
};

class UpiPayment : public PaymentMethod {
public:
    void pay() override { /* process upi */ }
};

class CardPayment : public PaymentMethod {
public:
    void pay() override { /* process card */ }
};

class PaymentProcessor {
public:
    void process(PaymentMethod* method) {
        method->pay();
    }
};

/*
 * L - Liskov Substitution Principle (LSP)
 * Subtypes must be substitutable for their base types.
*/

// ❌ WRONG
class Bird {
public:
    virtual void fly() {}
};

class Ostrich : public Bird {
public:
    void fly() override { throw "Can't fly"; }
};

// ✅ RIGHT
class Bird {};

class FlyingBird : public Bird {
public:
    virtual void fly() = 0;
};

class Sparrow : public FlyingBird {
public:
    void fly() override { /* flying */ }
};

class Ostrich : public Bird {}; // No fly method needed

/*
 * I - Interface Segregation Principle (ISP)
 * Clients should not depend on interfaces they don't use.
*/

// ❌ WRONG
class Restaurant {
public:
    virtual void cook();
    virtual void deliver();
    virtual void manageInventory();
};

class CloudKitchen : public Restaurant {
public:
    void deliver() override {} // Not applicable
};

// ✅ RIGHT
class CookService {
public:
    virtual void cook() = 0;
};

class DeliveryService {
public:
    virtual void deliver() = 0;
};

class Restaurant : public CookService, public DeliveryService {};
class CloudKitchen : public CookService {};

/*
 * D - Dependency Inversion Principle (DIP)
 * High-level modules should not depend on low-level modules. Both should depend on abstractions.
*/

// ❌ WRONG
class MySQLDatabase {
public:
    void connect();
};

class UserService {
    MySQLDatabase db;
};

// ✅ RIGHT
class Database {
public:
    virtual void connect() = 0;
};

class MySQLDatabase : public Database {
public:
    void connect() override { /* connect to MySQL */ }
};

class MongoDatabase : public Database {
public:
    void connect() override { /* connect to Mongo */ }
};

class UserService {
    Database* db;
public:
    UserService(Database* database) : db(database) {}
};
```

## 🧠 Final Summary Table

| Principle | ✅ Do This | ❌ Don’t Do This |
|----|----|----|
| **SRP** | One job per class | Mix unrelated responsibilities |
| **OCP** | Extend via new classes | Modify existing code for every change |
| **LSP** | Subclass respects base | Override methods with broken behavior |
| **ISP** | Interface per role | One giant "do-all" interface |
| **DIP** | Code to interfaces | Code directly to implementations |

## 🧩 Summary Table

| Principle | Meaning | Real-World Benefit |
|----|----|----|
| SRP | One job per class | Focused & maintainable code |
| OCP | Extend, don’t modify | Add features safely |
| LSP | Subclass should behave correctly | Bug-free polymorphism |
| ISP | Small interfaces only | Clean contracts |
| DIP | Depend on abstractions | Flexible & testable |


## 🔴 **S - Single Responsibility Principle (SRP)**

> ✅ A class should have only **one reason to change**.

### 🧠 Why?

* Keeps classes focused and simple.
* Easier to debug, test, and maintain.

### 💡 Analogy:

> A chef cooks, a waiter serves — don't let one person do both.



## 🟠 **O - Open/Closed Principle (OCP)**

> ✅ Software entities should be **open for extension but closed for modification**.

### 🧠 Why?

* Prevents breaking existing code when adding new features.
* Encourages use of interfaces and polymorphism.

### 💡 Analogy:

> A power socket accepts different plugs without changing the wall.



## 🟡 **L - Liskov Substitution Principle (LSP)**

> ✅ Subtypes must be **substitutable** for their base types **without breaking the behavior**.

### 🧠 Why?

* Ensures **polymorphic** behavior doesn’t cause runtime bugs.
* Child classes should be **true extensions**, not limitations.

### 💡 Analogy:

> A square **is not** a rectangle in behavior, even if it “looks like” one.



## 🟢 **I - Interface Segregation Principle (ISP)**

> ✅ No client should be forced to depend on **methods it does not use**.

### 🧠 Why?

* Avoids **fat interfaces**.
* Promotes **modular design** — clients only get what they need.

### 💡 Analogy:

> Don’t force every remote to have Netflix, YouTube, and Amazon buttons if it only needs volume control.



## 🔵 **D - Dependency Inversion Principle (DIP)**

> ✅ High-level modules should **not depend** on low-level modules. \n Both should depend on **abstractions**.

### 🧠 Why?

* Encourages **flexible and testable** code.
* Reduces tight coupling.

### 💡 Analogy:

> Plug in a charger — you don’t care if it's from Samsung or Apple, as long as it follows the standard.


