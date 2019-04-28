#include <iostream>
#include "map.h"
#include "robot.h"
#include "items.h"

using namespace std;
Items::~Items()
{
    cout<<"Item used";
}
void Item_view::use_special_item(Robot *R,Map &M)
{
    R->view=(R->view)*2;//acest item dubleaza vizibilitatea
    cout<<"View dubbled!!";
    cout<<endl;
}
void Item_move::use_special_item(Robot *R, Map &M)
{
    R->movement=R->movement+1;//creste numarul de pasi cu care poate inainta
    cout<<"Movement increased!!";
    cout<<endl;
}

void Item_break::use_special_item(Robot *R, Map &M)
{
    int i,j;//elimina toate capcanele din aria lui vizuala
    for(i=R->currenti-R->view;i<=R->currenti+R->view;i++)
        for(j=R->currentj-R->view;j<=R->currentj+R->view;j++)
            if(M.m[i][j]-'0'<0) M.m[i][j]='0';
    cout<<"Traps eliminated!!";
    cout<<endl;
}
