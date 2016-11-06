#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream in("graf.in");

int n, m, nrpct, start, vfmin=1000000, lmin=1000000;
vector <int> G[100];
vector <int> pct;
queue <int> Q;
int viz[100],lant[100];


void BFS(int x)
{
    viz[x]=-1;
    Q.push(x);
    while(!Q.empty())
    {
        x=Q.front();
        Q.pop();
        for(int i=0; i<G[x].size(); i++)
            if(!viz[G[x][i]])
            {
                viz[G[x][i]]=x;
                lant[G[x][i]]=lant[x]+1;
                Q.push(G[x][i]);
            }
    }
}

int main()
{
    in>>n>>m;
    int i,a,b;
    for(i=0; i<m; i++)
    {
        in>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    in>>start>>nrpct;
    for(i=0; i<nrpct; i++)
    {
        in>>a;
        pct.push_back(a);
    }
    BFS(start);
    for(i=0; i<pct.size(); i++)
        if(lant[pct[i]]<lmin)
        {
            lmin=lant[pct[i]];
            vfmin=pct[i];
        }
    cout<<"Cel mai apropiat punct de control este "<<vfmin<<" aflat la distanta "<<lmin<<endl;
    pct.clear();
    pct.push_back(vfmin);
    for(i=0; i<=lmin; i++)
    {
        a=viz[pct[i]];
        pct.push_back(a);
    }
    cout<<"\nLantul corespunzator: ";
    for(i=lmin; i>=0; i--)
        cout<<pct[i]<<' ';



    return 0;
}
