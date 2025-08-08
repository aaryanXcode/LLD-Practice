#include "VegPizza.h"
#include "NonVegPizza.h"
#include "CornDecorator.h"
#include "CapsicumDecorator.h"

int main() {
    Pizza* order = new CapsicumDecorator(
                        new CornDecorator(
                            new VegPizza()
                        )
                    );

    order->prepare();
    order->getPrice();

    delete order;
    return 0;
}