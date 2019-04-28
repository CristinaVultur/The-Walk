#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED
#include "map.h"
#include "items.h"
class Simulare;
class Items;

class Robot{
protected:
    int currenti,currentj,type,view,movement;
    int *items_catched;
    Items *special;

public:
    Robot(): currenti(0),currentj(0){};
    ~Robot();
    virtual void walk(Map &)=0;
    void catch_basic_item(Map &);
    void catch_special_item(Map &);
    void catch_trap(Map &,bool &);
    friend class Simulare;
    friend class Items;
    friend class Item_break;
    friend class Item_move;
    friend class Item_view;
};

class Robot1:public Robot
{
public:
    Robot1();
    void walk(Map &);
};

class Robot2:public Robot
{
public:
    Robot2();
    void walk(Map &);
};

class Robot3:public Robot
{
public:
    Robot3();
    void walk(Map &);
};
#endif // ROBOT_H_INCLUDED
