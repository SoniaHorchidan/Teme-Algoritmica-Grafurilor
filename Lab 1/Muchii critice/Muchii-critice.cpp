#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

ifstream in("graf.in");

vector <int> G[100];
int niv[100], h[100], viz[100], marcat[100];

void MC(int i)
{
    viz[i]=1;
    h[i]=niv[i];
    int j;
    for(j=0; j<G[i].size(); j++)
        if(viz[G[i][j]]==0)
        {
            niv[G[i][j]]=niv[i]+1;
            MC(G[i][j]);
            h[i]=min(h[i],h[G[i][j]]);
            if(h[G[i][j]]>=niv[i])
            {
                if(i!=1)
                    marcat[i]=1;
                if(h[G[i][j]]>niv[i])
                    cout<<i<<' '<<G[i][j]<<endl;
            }
        }
        else
            if(niv[G[i][j]]<niv[i]-1)
                h[i]=min(h[i],niv[G[i][j]]);
}

int main()
{
    int n,x,y,i,nr=0;
    in>>n;
    while(in>>x>>y)
    {
        G[x].push_back(y);
        G[y].push_back(x);
    }
    niv[1]=1;
    cout<<"\nMuchiile critice sunt:\n";
    MC(1);

    cout<<"\nPunctele critice sunt:\n";
    x=0;
    for(i=1; i<=n; i++)
        if(niv[i]==2)
            nr++;
    if(nr>=2)
        marcat[1]=1;
    for(i=1; i<=n; i++)
        if(marcat[i])
            cout<<i<<' ';

    return 0;
}
