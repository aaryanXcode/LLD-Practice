class ISubscriber{
    public:
        virtual void update()=0;
        virtual ~ISubscriber(){}
};