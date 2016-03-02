#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("barnrepair.in"); //GRADER TEST 5 HUGE GLITCH
ofstream out("barnrepair.out");
struct package
{
    int content;
    int future_content;
    int dif_future_content;
    int pos;
};
package dif[200];
void connect(int a,int b,int indice)
{
    dif[indice].content=a;
    dif[indice].future_content=b;
    dif[indice].pos=indice;
    dif[indice].dif_future_content=b-a;
}
int main()
{
    freopen("in.txt","r",stdin);
    int maxplaci,tarcuri,vaci;
    in>>maxplaci>>tarcuri;
    in>>vaci;
    int absolmin,absolmax;
    int prezent,trecut;
    in>>prezent;
    absolmin=prezent;
    absolmax=prezent;
    for(register int i=1;i<=vaci-1;i++)
    {
        trecut=prezent;
        in>>prezent;
        if(prezent>absolmax) absolmax=prezent;
        if(prezent<absolmin) absolmin=prezent;
        connect(trecut,prezent,i-1);
    }
    dif[vaci-1].content=prezent;
    dif[vaci-1].pos=vaci-1;
    dif[vaci-1].dif_future_content=0;
    int mini;
    int ret;
    int man;
    for(register int i=0;i<=vaci-2;i++)
    {
        mini=-1;
        for(register int k=i;k<=vaci-1;k++)
        {
            if(dif[k].dif_future_content>mini)
            {
                mini=dif[k].dif_future_content;
                ret=k;
            }
        }
        man=dif[i].content;
        dif[i].content=dif[ret].content;
        dif[ret].content=man;

        man=dif[i].pos;
        dif[i].pos=dif[ret].pos;
        dif[ret].pos=man;

        man=dif[i].dif_future_content;
        dif[i].dif_future_content=dif[ret].dif_future_content;
        dif[ret].dif_future_content=man;

        man=dif[i].future_content;
        dif[i].future_content=dif[ret].future_content;
        dif[ret].future_content=man;
    }

    int ctr=0;
    for(register int i=0;i<=maxplaci-2;i++)
    {
        //cout<<dif[i].content<<" "<<dif[i].future_content<<" "<<dif[i].future_content-dif[i].content-1<<'\n';
        ctr+=dif[i].future_content-dif[i].content-1;
    }
    out<<tarcuri-ctr-(absolmin-1)-(tarcuri-absolmax);
    /*for(register int i=0;i<=vaci-1;i++)
    {
        cout<<dif[i].content<<" "<<dif[i].pos<<" "<<dif[i].dif_future_content<<'\n';
    }*/
}
