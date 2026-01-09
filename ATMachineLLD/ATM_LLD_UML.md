# ATM Machine LLD - System Design

## UML Class Diagram

```mermaid
classDiagram
    %% State Pattern
    class IATMState {
        <<interface>>
        +insertCard(ATM)* void
        +enterPin(ATM, int)* void
        +selectOption(ATM, int)* void
        +withdrawAmount(ATM, int)* void
        +checkBalance(ATM)* void
        +ejectCard(ATM)* void
        +balanceCheckState(ATM)* void
    }

    class IdleState {
        +insertCard(ATM) void
        +enterPin(ATM, int) void
        +selectOption(ATM, int) void
        +withdrawAmount(ATM, int) void
        +checkBalance(ATM) void
        +ejectCard(ATM) void
        +balanceCheckState(ATM) void
    }

    class CardInsertedState {
        +insertCard(ATM) void
        +enterPin(ATM, int) void
        +selectOption(ATM, int) void
        +withdrawAmount(ATM, int) void
        +checkBalance(ATM) void
        +ejectCard(ATM) void
        +balanceCheckState(ATM) void
    }

    class PinInsertedState {
        +selectOption(ATM, int) void
        +insertCard(ATM) void
        +enterPin(ATM, int) void
        +withdrawAmount(ATM, int) void
        +checkBalance(ATM) void
        +ejectCard(ATM) void
        +balanceCheckState(ATM) void
    }

    class MenuState {
        -menu: Menu*
        +selectOption(ATM, int) void
        +insertCard(ATM) void
        +enterPin(ATM, int) void
        +withdrawAmount(ATM, int) void
        +checkBalance(ATM) void
        +ejectCard(ATM) void
        +balanceCheckState(ATM) void
    }

    class WithdrawState {
        +withdrawAmount(ATM, int) void
        +insertCard(ATM) void
        +enterPin(ATM, int) void
        +selectOption(ATM, int) void
        +checkBalance(ATM) void
        +ejectCard(ATM) void
        +balanceCheckState(ATM) void
    }

    class BalanceCheckState {
        +checkBalance(ATM) void
        +insertCard(ATM) void
        +enterPin(ATM, int) void
        +selectOption(ATM, int) void
        +withdrawAmount(ATM, int) void
        +ejectCard(ATM) void
        +balanceCheckState(ATM) void
    }

    class EjectCardState {
        +ejectCard(ATM) void
        +insertCard(ATM) void
        +enterPin(ATM, int) void
        +selectOption(ATM, int) void
        +withdrawAmount(ATM, int) void
        +checkBalance(ATM) void
        +balanceCheckState(ATM) void
    }

    class NoCashState {
        +insertCard(ATM) void
        +enterPin(ATM, int) void
        +selectOption(ATM, int) void
        +withdrawAmount(ATM, int) void
        +checkBalance(ATM) void
        +ejectCard(ATM) void
        +balanceCheckState(ATM) void
    }

    %% Chain of Responsibility Pattern
    class CashHandler {
        <<abstract>>
        #next: CashHandler*
        +dispense(int&, CashDispenser*)* bool
    }

    class TwoThousandHandler {
        +dispense(int&, CashDispenser*) bool
    }

    class FiveHundredHandler {
        +dispense(int&, CashDispenser*) bool
    }

    class HundredHandler {
        +dispense(int&, CashDispenser*) bool
    }

    %% Core Classes
    class ATM {
        -currentState: IATMState*
        -idleState: IATMState*
        -noCashState: IATMState*
        -cardInsertedState: IATMState*
        -pinInsertedState: IATMState*
        -menuState: IATMState*
        -withdrawState: IATMState*
        -balanceCheckState: IATMState*
        -ejectCardState: IATMState*
        -currentCard: Card*
        -cashDispenser: CashDispenser*
        -atmBalance: int
        +ATM(CashDispenser*)
        +setState(IATMState*) void
        +getCurrentState() IATMState*
        +insertCard(Card*) void
        +ejectCard() void
        +getCurrentCard() Card*
        +hasSufficientCash(int) bool
        +deductCash(int) void
        +getATMBalance() int
        +getCashDispenser() CashDispenser*
    }

    class CashDispenser {
        -note2000: int
        -note500: int
        -note100: int
        -chain: CashHandler*
        +CashDispenser(int, int, int)
        +getTotalCash() int
        +canDispense(int) bool
        +useNotes(int, int) bool
        +getAvailableNotes(int) int
        +dispenseCash(int) bool
        +printDispensedNotes(map) void
    }

    class Card {
        -account: Account*
        +Card(Account*)
        +getAccount() Account*
    }

    class Account {
        -accountHolderName: string
        -balance: int
        +Account(int)
        +getBalance() int
        +debit(int) void
    }

    class Menu {
        -items: MenuItem*
        +add(MenuItem*) void
        +display() void
    }

    class MenuItem {
        -id: int
        -description: string
        +MenuItem(int, string)
    }

    %% Relationships
    IATMState <|-- IdleState
    IATMState <|-- CardInsertedState
    IATMState <|-- PinInsertedState
    IATMState <|-- MenuState
    IATMState <|-- WithdrawState
    IATMState <|-- BalanceCheckState
    IATMState <|-- EjectCardState
    IATMState <|-- NoCashState

    CashHandler <|-- TwoThousandHandler
    CashHandler <|-- FiveHundredHandler
    CashHandler <|-- HundredHandler

    ATM --> IATMState: has current state
    ATM --> Card: holds current card
    ATM --> CashDispenser: manages
    ATM --> IdleState
    ATM --> CardInsertedState
    ATM --> PinInsertedState
    ATM --> MenuState
    ATM --> WithdrawState
    ATM --> BalanceCheckState
    ATM --> EjectCardState
    ATM --> NoCashState

    CashDispenser --> CashHandler: starts chain
    Card --> Account: references

    MenuState --> Menu: contains
    Menu --> MenuItem: contains multiple

    WithdrawState --> ATM: interacts with
    BalanceCheckState --> ATM: interacts with
```

## Design Patterns Used

### 1. **State Pattern** 
- **Purpose**: Encapsulate different ATM states and allow state transitions
- **Implementation**: `IATMState` interface with 8 concrete state classes
- **Benefits**: Clear state-specific behavior, easy to add new states

### 2. **Chain of Responsibility Pattern**
- **Purpose**: Handle cash dispensing with different denominations
- **Implementation**: `CashHandler` abstract class with handlers for ₹2000, ₹500, ₹100
- **Benefits**: Flexible, extensible, separation of concerns

### 3. **Composition Pattern**
- **Purpose**: ATM composes multiple state objects and delegates behavior
- **Components**: Menu, MenuItem, Card, Account

## State Transitions

```
START (Idle State)
  ↓
insertCard() → Card Inserted State
  ↓
enterPin() → PIN Inserted State
  ↓
selectOption(1 or 2)
  ├→ Withdraw State → Menu State
  └→ Balance Check State → Menu State
  ↓
ejectCard() → Idle State
```

## Class Responsibilities

| Class | Responsibility |
|-------|-----------------|
| **ATM** | Manages states, holds current card, manages cash balance |
| **IATMState** | Define interface for all state behaviors |
| **IdleState** | Initial state, only accepts card insertion |
| **CardInsertedState** | Waits for PIN entry |
| **PinInsertedState** | Presents menu options |
| **MenuState** | Displays menu and handles option selection |
| **WithdrawState** | Validates and dispenses cash |
| **BalanceCheckState** | Displays account balance |
| **EjectCardState** | Ejects card and returns to idle |
| **NoCashState** | ATM is out of service (no cash) |
| **CashDispenser** | Manages cash inventory and dispensing |
| **CashHandler** | Chain handlers for different denominations |
| **Card** | Represents user's bank card |
| **Account** | Represents user's bank account |
| **Menu** | Displays options to user |

## Key Features

✅ **State Management**: Clear separation of state-specific behaviors  
✅ **Cash Handling**: Chain of Responsibility for denomination flexibility  
✅ **Account Validation**: Before dispensing, validates both ATM and account balance  
✅ **Transaction Recording**: Debits account only after successful cash dispensing  
✅ **User Experience**: Menu-driven interface with proper prompts  
✅ **Error Handling**: Graceful handling of invalid operations per state
