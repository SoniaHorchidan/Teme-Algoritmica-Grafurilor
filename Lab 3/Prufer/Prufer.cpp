#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream in("prufer.in");

vector <int> Prufer;
priority_queue <int, vector<int>, greater<int> > Q;
int tata[100], grad[100];
bool adaugat[100];
int n,m,r;

int main()
{
   in>>n>>m>>r;                //n- nr de noduri; m-nr de muchii
   int i, a, b, contor=0;
   for(i=0; i<m; i++)
   {
       in>>a>>b;            //muchie (a,b) cu semnificatia a e tatal lui b
       tata[b]=a;
       grad[a]++;
       grad[b]++;
   }
   while(contor!=n-2)
   {
       for(i=1; i<=n; i++)
            if(grad[i]==1 && !adaugat[i]  && i!=r)
            {
                Q.push(i);
                adaugat[i]=1;
            }
        a=Q.top();
        Q.pop();
        Prufer.push_back(tata[a]);
        grad[tata[a]]--;
        grad[a]=0;
        contor++;
   }

   for(i=0; i<Prufer.size(); i++)
        cout<<Prufer[i];


    return 0;
}
