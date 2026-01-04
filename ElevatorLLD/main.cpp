#include <iostream>

#include "Button.h"
#include "Request.h"
#include "Display.h"
#include "Door.h"
#include "Panel.h"
#include "Elevator.h"
#include "IScheduler.h"
#include "FCFSScheduler.h"
#include "ElevatorController.h"

using namespace std;
int main() {
    // Core components
    Display display;
    Door door;
    Panel panel;

    // Elevator
    Elevator elevator(&display, &door, &panel);

    // Scheduler
    IScheduler* scheduler = new FCFSScheduler();

    // Controller
    ElevatorController controller(scheduler, &elevator);

    // Simulate user input
    Request* r1 = panel.pressFloorButton(5);
    Request* r2 = panel.pressFloorButton(2);

    controller.addRequest(r1);
    controller.addRequest(r2);

    controller.processNextRequest();
    controller.processNextRequest();

    delete scheduler;
    return 0;
}