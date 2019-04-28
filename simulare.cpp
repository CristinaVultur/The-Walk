#include "simulare.h"
#include "robot.h"
#include "items.h"
#include "map.h"
#include<iostream>
#include <cstdlib>

using namespace std;

void plasare_itemi_speciali(char c,Map &Harta)
{
     int i,j;
     i=rand()%15;//plasam itemii speciali
     j=rand()%15;
     while(Harta.m[i][j]!='0')
    {
        i=rand()%15;
        j=rand()%15;
    }
    Harta.m[i][j]=c;
}
Simulare::Simulare()
{
    gasit=false;
    Harta.m[0][0]='r';//creare harta
    int xi,xj;
    xi=rand()%15;
    xj=rand()%15;
    Harta.m[xi][xj]='x';//punctul in care trebuie sa ajunga
    plasare_itemi_speciali('m',Harta);
    plasare_itemi_speciali('b',Harta);
    plasare_itemi_speciali('v',Harta);//plasare itemi speciali
    for(int i=-15;i<=15;i++)//plasare itemi obisnuiti
    {
        if(i==0) continue;
        //unii itemi si toate capcanele vor fi sub forma de simboluri(reprezentatre de nr lor reprezentativ plus codul ascii al nr 0)
        //pe ecren se va afisa un vector de caractere care reprezinta sirul de itemi si sub fieacare capcana care poate fi trecuta de itemul respectiv
        int m=rand()%7+1,ci,cj;//va fi un nr aleatoriu de itemi si capcane plasate pe harta
        for(int j=0;j<m;j++)
        {
            ci=rand()%15;
            cj=rand()%15;
            if(Harta.m[ci][cj]=='0') Harta.m[ci][cj]=i+'0';//harta se umple unde sunt spatii goale
        else j--;
        }

    }
    int r;
    cout<<"Robot options:\n1)Movement=1, view=4, poate sa mearga sus,dreapta, jos, stanga.\n 2)Movement=1, view=4, poate sa mearga doar in diagonala \n 3)Movement=1, view=2, poate sa mearga in orice directie";
    cout<<endl;
    cout<<"Choose Robot:";//alegem robotul
    cin>>r;
    switch(r)
    {
        case 1:{R=new Robot1; break;}
        case 2:{R=new Robot2; break;}
        case 3:{R=new Robot3; break;}
    }

    cout<<"Itemii si capcanele corespunzatoare: ";
    cout<<endl;
    char *itemi=new char[16];
    for(int i=1;i<=15;i++){
        itemi[i]=i+'0';
        cout<<itemi[i]<<" ";}
    cout<<endl;
    for(int i=-1;i>=-15;i--){
        itemi[-i]=i+'0';
        cout<<itemi[-i]<<" ";}
    cout<<endl;
}
std::ostream & operator<<(std::ostream &out,const Simulare &S)
{

    out<<endl;
    out<<S.Harta;
    out<<endl;
    return out;
}
void Simulare::operator++(int )//++ va reprezenta o runda
{

    int poz,oldi,oldj;
    oldi=R->currenti;//tinem minte pozita curenta in caz ca va trebui sa ne intoarcem
    oldj=R->currentj;
    bool ok=true;
    cout<<"  ";
    for(int j=R->currentj-R->view;j<=R->currentj+R->view&&j<=14;j++)
        if(j>=0) cout<<" "<<j;
    cout<<endl;
    for(int i=R->currenti-R->view;i<=R->currenti+R->view&&i<=14;i++)//afisam cee ce vede robotul pentru a alege unde sa mergem
        {
            if(i>=0) cout<<i<<"  ";
            for(int j=R->currentj-R->view;j<=R->currentj+R->view&&j<=14;j++)
                    if(i>=0&&j>=0) cout<<Harta.m[i][j]<<" ";
            cout<<endl;
        }
    cout<<endl;
    cout<<"A prins itemii:";//afisam itemii prinsi pentru a sti daca putem trece de capcane
    for(int i=1;i<16;i++)
        if(R->items_catched[i]>0) {
        char item;
        item=i+'0';
        cout<<item<<" ";}
    cout<<endl;
    cout<<"Itemii si capcanele corespunzatoare: ";
    cout<<endl;
    char *itemi=new char[16];
    for(int i=1;i<=15;i++){
        itemi[i]=i+'0';
        cout<<itemi[i]<<" ";}
    cout<<endl;
    for(int i=-1;i>=-15;i--){
        itemi[-i]=i+'0';
        cout<<itemi[-i]<<" ";}
    cout<<endl;
    cout<<"Itemii si capcanele corespunzatoare robotului: ";
    cout<<endl;
    //char *itemi=new char[16]; //item<type*5&&(type-1)*5+1<=item
    for(int i=(R->type-1)*5+1;i<=(R->type)*5;i++){
        itemi[i]=i+'0';
        cout<<itemi[i]<<" ";}
    cout<<endl;
    for(int i=-((R->type-1)*5+1);i>=-(R->type)*5;i--){
        itemi[-i]=i+'0';
        cout<<itemi[-i]<<" ";}
    cout<<endl;
    cout<<"Poate inainta cu "<<R->movement<<" pasi";
    cout<<endl;
    R->walk(Harta);//deplasam robotul
    poz=Harta.m[R->currenti][R->currentj]-'0';//verificam ce se afla pe pozitia noua
    if(poz!=0)
        {
            if(poz=='x'-'0') gasit=true;
            else{
                if(poz>0&&poz<=15)//daca se afla item il prindem
                    R->catch_basic_item(Harta);
                else
                {
                if(poz<0&&poz>=-15)//daca se afla capcana
                    R->catch_trap(Harta,ok);
                else {R->catch_special_item(Harta);//daca se afla item special;
                cout<<"SPECIAL ITEM CACHED!";
                }
                }
        }
        }
    if(ok==false)//daca nu am putut sa trecem de capcana revenim pe pozitia initiala
    {
        R->currenti=oldi;
        R->currentj=oldj;
        cout<<"BLOCARE!Pozitia nu s-a schimbat!";
    }
    Harta.m[R->currenti][R->currentj]='r';
    cout<<endl;


}


