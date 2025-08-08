#include "ISubscriber.h"
class IChannel{
    public:
        virtual void subscribe(ISubscriber* subscriber) =0;
        virtual void unsubscribe(ISubscriber* subscriber) = 0;
        virtual void notify() = 0;
        virtual ~IChannel(){}
};