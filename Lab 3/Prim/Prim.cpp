#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream in ("apm.in");
ofstream out("apm.out");

struct muchie
{
    int x, y, c;
};

bool operator<(const muchie& a, const muchie& b)
{
    return a.c>b.c;
}

vector <muchie> Graf[400100];
vector <muchie> Arb;
priority_queue <muchie> Q;
int n,m,start, total;
bool viz[400100];

void Prim()
{
    muchie aux;
    int i;
    while(!Q.empty())
    {
        aux=Q.top();
        Q.pop();
        if(!viz[aux.y])
        {
            for(i=0; i<Graf[aux.y].size(); i++)
            {

                if(!viz[Graf[aux.y][i].y])
                    Q.push(Graf[aux.y][i]);
            }
            viz[aux.y]=true;
            total+=aux.c;
            Arb.push_back(aux);

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
        aux.x=b;
        aux.y=a;
        Graf[b].push_back(aux);
    }

    aux.x=start;
    aux.y=start;
    aux.c=0;
    Q.push(aux);
    aux=Q.top();
    Prim();

    out<<total<<'\n'<<Arb.size()-1<<'\n';
    for(i=1; i<Arb.size(); i++)
        out<<Arb[i].x<<' '<<Arb[i].y<<'\n';


    return 0;
}
