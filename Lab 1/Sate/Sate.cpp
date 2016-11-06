#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream in("sate.in");
ofstream out("sate.out");

vector < pair <int,int> > G[30005];
queue <int> C;
int d[30005];
int n,m,x,y;


int main()
{
    int a,b,c,k,i;
    in>>n>>m>>x>>y;
    while(in>>a>>b>>c)
    {
        G[a].push_back(make_pair(b,c));
        G[b].push_back(make_pair(a,c));
    }
    d[x]=0;
    C.push(x);
    while(!C.empty())
    {
        k=C.front();
        C.pop();
        for(i=0; i<G[k].size(); i++)
        {
            if(!d[G[k][i].first])
                if(G[k][i].first>k)
                {
                    d[G[k][i].first]=d[k]+G[k][i].second;
                    C.push(G[k][i].first);
                }
                else
                    if(G[k][i].first<k)
                    {
                        d[G[k][i].first]=d[k]-G[k][i].second;
                        C.push(G[k][i].first);
                    }
        }
    }
    out<<d[y];


    return 0;
}
