# Basic def

used to donot expose the direct object

**Proxy** is a structural design pattern that lets you provide a substitute or placeholder for another object. A proxy controls access to the original object, allowing you to perform something either before or after the request gets through to the original object.

TYPES

* virtual proxy(to load any high processing time)
* protected proxy(to protect anything from client) like subscription model
* remote proxy( connecting to remote server)

proxy(){

     if(has==null){

       new has();

     }

     return has;

}

so the observation is it is not going to give direct access to the concrete class

the proxy has the concrete class then based on null check it will return the object or do the specified work




