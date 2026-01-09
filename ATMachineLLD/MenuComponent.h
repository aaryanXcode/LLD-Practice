#ifndef MENU_COMPONENT
#define MENU_COMPONENT
class MenuComponent {
public:
    virtual void display() = 0;
    virtual int getId() = 0;
    virtual ~MenuComponent() {}
};

#endif
