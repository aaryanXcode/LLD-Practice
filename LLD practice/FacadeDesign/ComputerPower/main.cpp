#include "Computer.h"
#include "ComputerFacade.h"
int main(){
    Computer* computer = new Computer(new ComputerFacade());
    computer->execute();
    return 0;
    
}