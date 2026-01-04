class ElevatorController {
private:
    IScheduler* scheduler;
    std::list<Request*> pendingRequests;
    Elevator* elevator;

public:
    ElevatorController(IScheduler* sched, Elevator* elev) : scheduler(sched), elevator(elev) {}

    void addRequest(Request* request) {
        pendingRequests.push_back(request);
    }

    void processNextRequest() {
        Request* req = scheduler->getNextRequest(pendingRequests, elevator);
        if (!req) return;

        // movement decision
        if (req->floor > elevator->getCurrentFloor()) {
            elevator->moveUp(req->floor);
        } else {
            elevator->moveDown(req->floor);
        }

        pendingRequests.remove(req);
    }
};
