#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

ifstream in("rj.in");
ofstream out("rj.out");

char mm[150][150];
int R[150][150],J[150][150];
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};
int n,m;
int xR, yR, xJ, yJ, tmin=1000000, a, b;

struct Element
{
    int l,c,d;
};

Element x,y;
queue <Element> Q;

void Romeo(int x0, int y0)
{
    x.l=xR;
    x.c=yR;
    R[x0][y0]=0;
    Q.push(x);
    while(!Q.empty())
    {
        x=Q.front();
        Q.pop();
        for(int k=0;k<8;k++)
        {
            y.l=x.l+dx[k];
            y.c=x.c+dy[k];
            if(R[y.l][y.c]==-2 && y.l<n && y.l>=0 && y.c<m && y.c>=0)
            {
                y.d=x.d+1;
                R[y.l][y.c]=y.d;
                Q.push(y);
            }
        }
    }
}

void Julieta(int x0, int y0)
{
    while(!Q.empty())
        Q.pop();
    x.l=x.c=x.d=0;
    y.l=y.c=y.d=0;
    x.l=xJ;
    x.c=yJ;
    J[x0][y0]=0;
    Q.push(x);
    while(!Q.empty())
    {
        x=Q.front();
        Q.pop();
        for(int k=0;k<8;k++)
        {
            y.l=x.l+dx[k];
            y.c=x.c+dy[k];
            if(J[y.l][y.c]==-2 &&  y.l<n && y.l>=0 && y.c<m && y.c>=0)
            {
                y.d=x.d+1;
                J[y.l][y.c]=y.d;
                Q.push(y);
            }
        }
    }
}



int main()
{

    in>>n>>m;
    int i,j;
    in.get();
    for(i=0;i<=n;i++)
        in.getline(mm[i],101);

    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            R[i][j]=J[i][j]=-2;

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)

            if(mm[i][j]=='X')
            {
                J[i][j]=-1;
                R[i][j]=-1;
            }
            else
            {
                if(mm[i][j]=='R')
                {
                    xR=i;
                    yR=j;
                    J[i][j]=-2;
                    R[i][j]=0;
                }
                else
                    if(mm[i][j]=='J')
                    {
                        xJ=i;
                        yJ=j;
                        J[i][j]=0;
                        R[i][j]=-2;
                    }
            }


    Romeo(xR, yR);
    Julieta(xJ,yJ);

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if (R[i][j]==J[i][j] && R[i][j]>0)
                if(R[i][j]<tmin)
                {
                    tmin=R[i][j];
                    a=i;
                    b=j;
                }
    out<<tmin+1<<' '<<a+1<<' '<<b+1;



    return 0;
}
