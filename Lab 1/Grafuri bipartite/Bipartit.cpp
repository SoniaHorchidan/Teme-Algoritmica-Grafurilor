#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream in("graf.in");

vector <int> G[100];
queue <int> C;
int viz[100];
int n, m;

int BFS(int x)
{
    int i;
    viz[x]=1;
    C.push(x);
    while(!C.empty())
    {
        x=C.front();
        C.pop();
        for(i=0; i< G[x].size(); i++)
            if(!viz[G[x][i]])
            {
                viz[G[x][i]]=3-viz[x];
                C.push(G[x][i]);
            }
            else
                if(viz[G[x][i]]==viz[x])
                    return 0;
    }
    return 1;

}

int main()
{
    int x, y, nr1=0, nr2=0;
    in>>n>>m;
    while(in>>x>>y)
    {
        G[x].push_back(y);
        G[y].push_back(x);
    }
    y=1;
    for(x=1; x<=n; x++)
        if(!viz[x])
            if(!BFS(x))
                y=0;
    if(y)
    {
        cout<<"Graful este bipartit";
        cout<<"\nO bipartitie este:\n";
        for(x=1; x<=n; x++)
            if(viz[x]==1)
            {
                cout<<x<<' ';
                nr1++;
            }
        cout<<endl;
        for(x=1; x<=n; x++)
            if(viz[x]==2)
                cout<<x<<' ';
        nr2=n-nr1;
        if(m==nr1*nr2)
            cout<<"\nGrafu este bipartit complet";
        else
            cout<<"\nGraful NU este bipartit complet";
    }

    else
        cout<<"Graful nu este bipartit";



    return 0;
}
