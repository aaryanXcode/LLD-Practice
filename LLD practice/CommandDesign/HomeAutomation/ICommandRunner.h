#pragma once
class ICommandRunner{
    public:
        virtual void execute() = 0;
        virtual void undo() = 0;
        virtual ~ICommandRunner(){}
};