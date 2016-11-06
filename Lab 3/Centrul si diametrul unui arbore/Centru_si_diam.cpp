#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define inf 1000000

using namespace std;

ifstream in("arb.in");
ofstream out("arb.out");

vector <int> G[100];
vector <int> centru;
queue <int> Q;
int viz[100], d[100];
int dmin=inf,dmax=0;
int n,nrmuchii;

void DFS(int x, int &nr)
{
    viz[x]=1;
    nr++;
    for(int i=0; i<G[x].size(); i++)
        if(!viz[G[x][i]])
            DFS(G[x][i],nr);
}

void BFS(int x)
{
    viz[x]=1;
    Q.push(x);
    dmax=0;
    while(!Q.empty())
    {
        x=Q.front();
        Q.pop();
        for(int i=0; i<G[x].size(); i++)
            if(!viz[G[x][i]])
            {
                viz[G[x][i]]=1;
                d[G[x][i]]=d[x]+1;
                if(dmax<d[G[x][i]])
                    dmax=d[G[x][i]];
                Q.push(G[x][i]);
            }
    }
}


int este_arbore()
{
    int nr=0;
    if(nrmuchii<n-1)
        return 0;
    else
    {
        DFS(1,nr);
        if(nr!=n)           //graful nu este conex
            return 0;
    }
}

void reinit(int x)
{
    for(int i=1; i<=n; i++)
    {
        d[i]=inf;
        viz[i]=0;
    }
    d[x]=0;
    while(!Q.empty()) Q.pop();
}

int main()
{
    int a,b;
    int i,j;
    in>>n;
    while(in>>a>>b)
    {
        nrmuchii++;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    if(!este_arbore())
        cout<<"\nGraful dat nu este arbore";
    else
    {
        for(i=1; i<=n; i++)
        {
            reinit(i);
            BFS(i);
            if(dmax<dmin)
            {
                dmin=dmax;
                centru.clear();
                centru.push_back(i);
            }
            else
                if(dmax==dmin)
                    centru.push_back(i);
        }

        for(i=0; i<centru.size(); i++)
            cout<<centru[i]<<' ';
    }



    return 0;
}
