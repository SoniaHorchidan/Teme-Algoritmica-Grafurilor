#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream in("flux.in");
vector <int> G[100];
queue <int> Q;
int f[100][100], c[100][100], tata[100],viz[100],flux, fluxtotal;
int n,m,d,s;


bool BFS()
{
    int x,y,i;
    while(!Q.empty())
        Q.pop();
    for(i=1; i<=n; i++)
        tata[i]=0 ;
    tata[1]=-1;
    Q.push(s);
    while(!Q.empty())
    {
        x=Q.front();
        Q.pop();
        if(x==d)
            return 1;

        for(i=0; i<G[x].size(); i++)
        {
            y=G[x][i];
            if(!tata[y] && c[x][y]>f[x][y])
            {
                tata[y]=x;
                Q.push(y);
            }
        }
    }
    return 0;

}

int main()
{
     int i,j,x,y,z,a;
    in>>n>>m;
    for(i=1; i<=m; i++)
    {
        in>>x>>y>>z;
        G[x].push_back(y);
        G[y].push_back(x);
        c[x][y]=z;
    }
    d=n;
    s=1;
    while(BFS())
    {
        for(i=0; i<G[n].size(); i++)
        {
            a=G[n][i];
            if(tata[a] && c[a][n]>f[a][n])
            {
                tata[n]=a;
                flux=10000000000;
                for(j=n; j!=1; j=tata[j])
                    if(flux>c[tata[j]][j]-f[tata[j]][j])
                        flux=c[tata[j]][j]-f[tata[j]][j];
                for(j=n; j!=1; j=tata[j])
                {
                    f[tata[j]][j]+=flux;
                    f[j][tata[j]]-=flux;
                }
                fluxtotal+=flux;
            }
        }
    }
    cout<<fluxtotal;
    return 0;
}
