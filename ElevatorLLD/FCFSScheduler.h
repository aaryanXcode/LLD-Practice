class FCFSScheduler : public IScheduler {
public:
    Request* getNextRequest(std::list<Request*>& pendingRequests, Elevator* elevator) override {
        if (pendingRequests.empty()) return nullptr;
        return pendingRequests.front();
    }
};
