#include "ApplicationHandler.h"
#include "TeamLeader.h"
#include "Manager.h"
#include "Hr.h"

int main(){
    ApplicationHandler* teamLeader = new TeamLeader(2);
    ApplicationHandler* manager = new Manager(5);
    ApplicationHandler* hr = new Hr(15);
    teamLeader->setNextHandler(manager);
    manager->setNextHandler(hr);

    teamLeader->approvalRequest(2);
    return 0;
}