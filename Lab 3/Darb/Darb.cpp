#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream in("darb.in");
ofstream out("darb.out");

vector <int> G[100005];
queue <int> Q;
int n,m,diam;
int viz[100005], d[100005];

void BFS1(int x, int &nod)
{
    viz[x]=1;
    Q.push(x);
    while(!Q.empty())
    {
        x=Q.front();
        Q.pop();
        for(int i=0; i<G[x].size(); i++)
            if(!viz[G[x][i]])
            {
                viz[G[x][i]]=1;
                nod=G[x][i];
                Q.push(G[x][i]);
            }
    }
}

void BFS2(int x, int &nod)
{
    viz[x]=1;
    Q.push(x);
    while(!Q.empty())
    {
        x=Q.front();
        Q.pop();
        for(int i=0; i<G[x].size(); i++)
            if(!viz[G[x][i]])
            {
                viz[G[x][i]]=1;
                d[G[x][i]]=d[x]+1;
                nod=G[x][i];
                Q.push(G[x][i]);
            }
    }
}


void Reinit()
{
    for(int i=0; i<n; i++)
        viz[i]=0;
    while(!Q.empty()) Q.pop();
}


int main()
{
    int a,b,i, nod1,nod2;
    in>>n;
    while(in>>a>>b)
    {
        G[a].push_back(b);
        G[b].push_back(a);
    }

    BFS1(1,nod1);
    Reinit();
    BFS2(nod1, nod2);

    out<<d[nod2]+1;

    return 0;
}
