
\#the core of system design has to identify the relations
IS-A = Inherit property → use inheritance
HAS-A = Use behavior → pass pointer (composition)

//
each design has a seperate client
every interface should have a concrete class
differentiate its interface and concrete class

* **==//important==**
  ***principle of least knowledge Rules***
  Take any object, now from any method in that object, principle tells you to invoke only methods that belong to:
  * the object itself
  * the object passed in as a parameter to its method
  * Any object that method creates
  * any object with (HAS_A) relation

    \


