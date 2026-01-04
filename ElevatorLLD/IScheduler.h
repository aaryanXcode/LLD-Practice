#include <list>

class IScheduler {
public:
    virtual Request* getNextRequest(
        std::list<Request*>& pendingRequests,
        Elevator* elevator
    ) = 0;

    virtual ~IScheduler() = default;
};
