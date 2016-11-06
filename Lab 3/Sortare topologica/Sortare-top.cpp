#include <iostream>
#include <fstream>
#include <vector>
#define inf 1000

using namespace std;

ifstream in("graf.in");

struct muchie
{
    int nod1, nod2, cost;
};

vector <muchie> G[100];
int d[100], viz[100];
int n,m;

void SortareTopologica(int x)
{
    viz[x]=1;
    for(int i=0; i<G[x].size(); i++)
        if(!viz[G[x][i].nod2])
        {
            if( d[G[x][i].nod2]>d[x]+G[x][i].cost)
                d[G[x][i].nod2]=d[x]+G[x][i].cost;
            SortareTopologica(G[x][i].nod2);
        }

}

int main()
{
    int i,x,y,z,start;
    muchie aux;

    in>>n>>m>>start;

    for(i=1; i<=n; i++)
        d[i]=inf;
    d[start]=0;

    for(i=0; i<m; i++)
    {
        in>>x>>y>>z;
        aux.nod1=x;
        aux.nod2=y;
        aux.cost=z;
        G[x].push_back(aux);
    }

    SortareTopologica(start);

    for(i=1; i<=n; i++)
        cout<<d[i]<<' ';

    return 0;
}
