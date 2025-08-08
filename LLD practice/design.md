# Design Pattern UML Trees


---

## 1. Iterator Pattern

```
Iterable
   |
   |-- getIterator() --> Iterator
                           |-- hasNext()
                           |-- next()
```


---

## 2. Adapter Pattern

```
Client
   |
   |-- uses --> IReport (Target Interface)
                      ^
                      |
                Report (Client Implementation)
                      |
                      v
                IReportAdapter (Adapter Interface)
                      ^
                      |
                XamlReportAdapter (Concrete Adapter)
                      |
                      v
                XamlDataProvider (Adaptee)
```


---

## 3. Bridge Pattern

```
Car (Abstraction)
   |
   |-- HAS-A --> Engine (Implementor)
   |                   |
   |                   |-- start()
   |
   |-- Sedan, SUV (Refined Abstractions)
   |
   |-- PetrolEngine, DieselEngine (Concrete Implementors)
```


---

## 4. Builder Pattern

```
Director
   |
   |-- uses --> Builder (Abstract)
                      |
                      |-- ConcreteBuilder
                      |
                      |-- Product
```


---

## 5. Step Builder Pattern

```
UrlStep
   |
   |-- withUrl() --> MethodStep
                          |
                          |-- withMethod() --> HeaderStep
                                                    |
                                                    |-- withHeader() --> OptionalStep
                                                                                 |
                                                                                 |-- withBody()
                                                                                 |-- withTimeout()
                                                                                 |-- build() --> HttpRequest
```


---

## 6. Chain of Responsibility Pattern

```
Handler (Abstract)
   |
   |-- setNext(Handler)
   |-- handle(request)
   |
   |-- ConcreteHandler1
   |-- ConcreteHandler2
   |-- ...
```


---

## 7. Command Pattern

```
Invoker
   |
   |-- setCommand(Command)
   |-- executeCommand()
   |
   |-- Command (Abstract)
           |
           |-- ConcreteCommand
           |
           |-- Receiver
```


---

## 8. Composite Pattern

```
FileSystem (Component)
   |
   |-- File (Leaf)
   |-- Folder (Composite)
           |
           |-- HAS-A --> vector<FileSystem*>
```


---

## 9. Decorator Pattern

```
Beverage (Component)
   |
   |-- Coffee (Concrete Component)
   |-- BeverageDecorator (Decorator)
           |
           |-- MilkDecorator
           |-- SugarDecorator
           |-- CornDecorator
           |
           |-- HAS-A --> Beverage*
```


---

## 10. Facade Pattern

```
Client
   |
   |-- Facade
           |
           |-- Subsystem1
           |-- Subsystem2
           |-- ...
```


---

## 11. Factory Pattern

```
VehicleFactory (Abstract)
   |
   |-- Maruti (Concrete Factory)
   |-- Honda (Concrete Factory)
   |
   |-- createBasicCar()
   |-- createLuxuryCar()
   |-- ...
   |
   |-- Vehicle (Product)
           |
           |-- Car, Bike, Truck (Concrete Products)
```


---

## 12. Observer Pattern

```
Channel (Subject)
   |
   |-- subscribe(Subscriber)
   |-- unsubscribe(Subscriber)
   |-- notify()
   |
   |-- Subscriber (Observer)
```


---

## 13. Proxy Pattern

```
Subject (Interface)
   |
   |-- RealSubject
   |-- Proxy
```


---

## 14. Strategy Pattern

```
Context
   |
   |-- setStrategy(Strategy)
   |-- execute()
   |
   |-- Strategy (Interface)
           |
           |-- ConcreteStrategyA
           |-- ConcreteStrategyB
```


---

## 15. Template Method Pattern

```
ModelTrainer (Abstract)
   |
   |-- templatepipeline()
   |-- load()
   |-- filter() (abstract)
   |-- preprocessing() (abstract)
   |-- train() (abstract)
   |-- evaluate() (abstract)
   |-- save()
   |
   |-- ConcreteTrainer (implements abstract methods)
```


---


