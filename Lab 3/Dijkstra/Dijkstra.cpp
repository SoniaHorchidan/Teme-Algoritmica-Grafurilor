#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define inf 100000

using namespace std;

ifstream in ("dijkstra.in");
ofstream out("dijkstra.out");

struct muchie
{
    int x, y, c;
};

bool operator<(const muchie& a, const muchie& b)
{
    return a.c>b.c;
}

vector <muchie> Graf[250050];
priority_queue <muchie> Q;
int d[50050];
int n,m,start;

void Dijkstra()
{
    muchie aux;
    int i;
    while(!Q.empty())
    {
        aux=Q.top();
        Q.pop();
        for(i=0; i<Graf[aux.y].size(); i++)
            if(d[Graf[aux.y][i].y]>d[aux.y]+Graf[aux.y][i].c)
            {
                d[Graf[aux.y][i].y]=d[aux.y]+Graf[aux.y][i].c;
                Q.push(Graf[aux.y][i]);

            }
    }

}

int main()
{

    in>>n>>m;
    start=1;
    int i,a,b,cost;
    muchie aux;
    for(i=0; i<m; i++)
    {
        in>>a>>b>>cost;
        aux.x=a;
        aux.y=b;
        aux.c=cost;
        Graf[a].push_back(aux);
    }

    aux.x=start;
    aux.y=start;
    aux.c=0;
    Q.push(aux);

    for (i=1; i<=n; i++)
        d[i]=inf;
    d[start]=0;

    Dijkstra();

    for(i=2; i<=n; i++)
        if(d[i]!=inf)
            out<<d[i]<<' ';
        else
            out<<0<<' ';


    return 0;
}
