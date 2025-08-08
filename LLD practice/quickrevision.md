# ========================
Creational Patterns

## Factory

Creator
\--|> ConcreteCreator
\---> Product (has-a, via factory method)
Product
\--|> ConcreteProduct

## Abstract Factory

AbstractFactory
\--|> ConcreteFactory
\---> AbstractProductA, AbstractProductB (has-a)
AbstractProductA
\--|> ProductA1, ProductA2
AbstractProductB
\--|> ProductB1, ProductB2

## Builder

Director
\---> Builder (has-a)
Builder
\--|> ConcreteBuilder
ConcreteBuilder
\---> Product (has-a)

## Singleton

Singleton
\-- static getInstance()

## Prototype

Prototype
\--|> ConcretePrototype
\-- clone()

# ========================
Structural Patterns

## Adapter

Target
\--|> Adapter (is-a)
Adapter
\---> Adaptee (has-a)

## Bridge

Abstraction
\---> Implementor (has-a)
Abstraction
\--|> RefinedAbstraction
Implementor
\--|> ConcreteImplementorA, ConcreteImplementorB

## Composite

Component
\--|> Leaf
\--|> Composite
Composite
\---> Component\* (has-a, collection)

## Decorator

Component
\--|> ConcreteComponent
\--|> Decorator
Decorator
\---> Component\* (has-a)
\--|> ConcreteDecoratorA, ConcreteDecoratorB

## Facade

Facade
\---> SubsystemA, SubsystemB, ... (has-a)
Client
\---> Facade (has-a)

## Flyweight

FlyweightFactory
\---> Flyweight (has-a, pool)
Flyweight
\--|> ConcreteFlyweight

## Proxy

Subject
\--|> RealSubject
\--|> Proxy
Proxy
\---> RealSubject (has-a)

# ========================
Behavioral Patterns

## Chain of Responsibility

Handler
\--|> ConcreteHandlerA, ConcreteHandlerB
Handler
\---> Handler\* next (has-a)

## Command

Invoker
\---> Command (has-a)
Command
\--|> ConcreteCommand
ConcreteCommand
\---> Receiver (has-a)

## Iterator

Iterable
\---> Iterator (has-a, via getIterator())
Iterator
\--|> ConcreteIterator

## Mediator

Mediator
\--|> ConcreteMediator
Mediator
\---> Colleague (has-a)
Colleague
\--|> ConcreteColleague

## Memento

Originator
\---> Memento (has-a)
Caretaker
\---> Memento (has-a)

## Observer

Subject
\---> Observer (has-a, via attach/detach/notify)
Observer
\--|> ConcreteObserver

## State

Context
\---> State (has-a)
State
\--|> ConcreteStateA, ConcreteStateB

## Strategy

Context
\---> Strategy (has-a)
Strategy
\--|> ConcreteStrategyA, ConcreteStrategyB

## Template Method

AbstractClass
\--|> ConcreteClass
AbstractClass
(templateMethod() calls primitive operations)

## Visitor

Visitor
\--|> ConcreteVisitor
Element
\--|> ConcreteElement
Element
\---> Visitor (has-a, via accept())