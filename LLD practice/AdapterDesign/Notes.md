**Adapter Design Pattern**

* Adapter design - it is a structural design pattern that allows objects with the incompatible interfaces to collaborate
* simply we can understand it with basic life adapters(like if we have to connect hdmi to macbook but macbook doesnot have a connecter of type hdmi so we use adapter to make support of hdmi)

same if we move to other country the pin/port size can be different so we carry a extra adapter for that country so that our appliances get **compatible to use their resources**

in development to make (**compatible to use other resources**) or using other resources we use adapter design pattern so that we can adapt other resources. eg. Payment gateway, Notification system etc.




Always think like hierarchy

if a class doing or need multiple implementation then break into hierarchy leader →subleader

here i have report which can be be only responsible for printing report, what if i have to print report from different formats like, xml,csv,xlsx etc?

so we have reportadapter which connectes with the data source , a reportadapter has data provider and that data provider returning data to our report client