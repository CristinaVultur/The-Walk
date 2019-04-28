#include <iostream>
#include "map.h"
#include "items.h"
#include <string.h>
#include "robot.h"
 using namespace std;
Robot::~Robot()//destructor
{
    cout<<"RIP";
}
Robot1::Robot1():Robot()//primul tiop de robot
{
     currenti=currentj=0;
     type=1;
     movement=1;
     view=4;
     items_catched=new int[16];//alocam memorie pt vectorul de itemi
     for(int i=0;i<16;i++) items_catched[i]=0;
 }
Robot2::Robot2():Robot()//al doilea tip
{
     currenti=currentj=0;
     type=2;
     movement=1;
     view=4;
     items_catched=new int[16];
     for(int i=0;i<16;i++) items_catched[i]=0;
 }
 Robot3::Robot3():Robot()//al treilea tip
{
     currenti=currentj=0;
     type=3;
     movement=1;
     view=2;
     items_catched=new int[16];
     for(int i=0;i<16;i++) items_catched[i]=0;
 }
 void Robot::catch_basic_item(Map &M)//functia se apleleaza cand gasim un item basic( numere pozitive intre 1 si 15)
 {
     int item=M.m[currenti][currentj]-'0';
    if(item<type*5&&(type-1)*5+1<=item)//ca itemul sa fie compatibil trebuie sa fie mai mic decat tipul robotului*5 si mai mare decat tipul-1 ori 5 plus 1( pentru tipul 1 va fi intre 1 si 5,pentru 2 intre 6 si 10, si pt 3 intre 11 si 15
     {items_catched[item]++;//daca este compatibil se salveaza in vectorul de itemi prinsi
     cout<<endl<<"Item "<<item<<" catched"<<endl;
     }
}
void Robot::catch_trap(Map &M,bool &ok)
{
    int trap=M.m[currenti][currentj]-'0';
    //capcanele sunt numere negative intre -15 si -1, fiecarei capcane ii corespunde itemul egal cu nr ei in modul
    //pentru a trece de capcana cu nr x trebuie ca robotul sa fi prins itemul |x|
    if(items_catched[-trap]>0) {items_catched[-trap]--; cout<<"Trap passed succesfully"; ok=true;}
    else//daca nu l-a prins
        {
            if(trap%2==0)//daca nr capcanei este para
                {
                    this->view=this->view-1;//vizibilitatea robotului scade
                    ok=true;
                    cout<<"View diminished"<<endl;
                }
            else {ok=false;}//daca nu drumul este blocat si robotul trebuie sa se intoarca
        }
}
void Robot::catch_special_item(Map &M)
{

    char c=M.m[currenti][currentj];
    switch(c)
    {
        case 'm':{special=new Item_move; break;}
        case 'b':{special=new Item_break; break;}
        case 'v':{special=new Item_view; break;}
    }
    special->use_special_item(this,M);
}
 void Robot1::walk(Map &m)
 {
        int newi,newj,i,j;
        i=currenti;
        j=currentj;
        cout<<"Alege noua pozitie,optiuni:";//poate sa mearga sus,jos,stanga,dreapta
        if(i-1>=0&&j>=0)
            cout<<i-1<<" "<<j<<"/";
        if(i>=0&&j+1>=0)
            cout<<i<<" "<<j+1<<"/";
        if(i+1>=0&&j>=0)
            cout<<i+1<<" "<<j<<"/";
        if(i>=0&&j-1>=0)
        cout<<i<<" "<<j-1;
        cout<<endl;
        cin>>newi>>newj;
        m.m[currenti][currentj]='0';
        currenti=newi;
        currentj=newj;
        //m.m[newi][newj]='r';

 }
 void Robot2::walk(Map &m)
 {
     int newi,newj,i,j;
     i=currenti;
     j=currentj;
     cout<<"Alege noua pozitie: optiuni:";//poate sa mearga pe diagonala
     if(i-1>=0)
        {
        if(j-1>=0)
            cout<<i-1<<" "<<j-1<<"/";
        if(j+1>=0)
            cout<<i-1<<" "<<j+1<<"/";
        }
     if(i+1>=0)
     {
         if(j-1>=0)
            cout<<i+1<<" "<<j-1<<"/";
         if(j+1>=0)
            cout<<i+1<<" "<<j+1;
     }
    cout<<endl;

     cin>>newi>>newj;
        m.m[currenti][currentj]='0';
        currenti=newi;
        currentj=newj;
        //m.m[newi][newj]='r';


 }
 void Robot3::walk(Map &m)
 {
     int newi,newj;
     cout<<"Pozitia curenta "<<currenti<<" "<<currentj<<endl;
     cout<<"Alege noua pozitie:";//poate sa mearge in orice directie dar are vizibiliatea 2;
     cin>>newi>>newj;
      m.m[currenti][currentj]='0';
        currenti=newi;
        currentj=newj;
        //m.m[newi][newj]='r';
 }
