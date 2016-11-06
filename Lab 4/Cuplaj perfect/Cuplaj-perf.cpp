#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

ifstream in("cuplaj.in");

vector <int> G[100];
int stg[100],dr[100];
bool viz[100],gata;
int n,m,e,dim;      //G=(AUB, E) ; |A|=n; |B|=m; |E|=e

bool este_lant(int x)
{
    if(!viz[x])
    {
       viz[x]=1;
       for(int i=0; i<G[x].size();i++)
          if(!dr[G[x][i]] || este_lant(dr[G[x][i]]))
          {
                stg[x]=G[x][i];
                dr[G[x][i]]=x;
                return 1;
          }
          return 0;
    }
    return 0;
}


int main()
{
    int x,y,i;
    in>>n>>m>>e;
    for(i=0; i<e; i++)
    {
        in>>x>>y;
        G[x].push_back(y);
    }
    gata=0;
    do
    {
        gata=1;
        for(i=1; i<=n+m; i++)
            viz[i]=0;
        for(i=1; i<=n; i++)
            if(!stg[i])
                if(este_lant(i))
                {
                    dim++;
                    gata=0;
                }
    }while(!gata);

    if(dim!=n)
        cout<<"Nu exista cuplaj perfect.\n";
    else
    {
        cout<<dim<<"\n";
        for(i=1; i<=n; i++)
            if(stg[i])
                cout<<i<<' '<<stg[i]<<"\n";
    }

    return 0;
}
