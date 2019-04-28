#ifndef ITEMS_H_INCLUDED
#define ITEMS_H_INCLUDED

#include "robot.h"
#include "map.h"

class Items
{
protected:
    char code;
public:
    Items(): code('0'){}
    ~Items();
    virtual void use_special_item(Robot *,Map &)=0;//folosim itemul special
    friend class Robot;
};
class Item_view:public Items
{
    char code;
public:
    Item_view(): code('v'){};
    void use_special_item(Robot *,Map &);
};

class Item_move:public Items
{
    char code;
public:
    Item_move(): code('m'){};
    void use_special_item(Robot *,Map &);
};

class Item_break:public Items
{
    char code;
public:
    Item_break(): code('b'){};
    void use_special_item(Robot *,Map &);
};
#endif // ITEMS_H_INCLUDED
