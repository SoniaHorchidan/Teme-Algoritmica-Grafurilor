#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("secv.in");

vector < pair <int, int> > s0;              //(grad,eticheta)
vector < pair <int, int> > G;
vector < pair <int, int> > Arb;
vector < pair <int, int> > Gconex;
int n, nrmuchii;

void ordonare()
{
    int i, j;
    pair <int, int> x;
    for(i=1; i<n; i++)
    {
        x=s0[i];
        j=i-1;
        while(j>-1 && x.first>s0[j].first)
        {
            s0[j+1]=s0[j];
            j--;
        }
        s0[j+1]=x;
    }

}

void HavelHakimi1(int &ok)
{
    pair <int, int> p;
    p.first=s0[0].second;
    for(int j=1; j<s0[0].first+1 && ok; j++)
    {
        s0[j].first--;
        if(s0[j].first<0)
            ok=0;
        p.second=s0[j].second;
        G.push_back(p);
        nrmuchii++;
    }

    s0[0].first=0;
}

void HavelHakimi2(int &ok, int i)
{
    pair <int, int> p;
    p.first=s0[i].second;
    for(int j=0; j<s0[i].first && ok; j++)
    {
        s0[j].first--;
        if(s0[j].first<0)
            ok=0;
        p.second=s0[j].second;
        Arb.push_back(p);
        nrmuchii++;
    }

    s0[i].first=0;
}

void HavelHakimi3(int &ok, int i)
{
    pair <int, int> p;
    p.first=s0[i].second;
    for(int j=0; j<s0[i].first && ok; j++)
    {
        s0[j].first--;
        if(s0[j].first<0)
            ok=0;
        p.second=s0[j].second;
        Gconex.push_back(p);
        nrmuchii++;
    }

    s0[i].first=0;
}


int main()
{
    in>>n;
    int i, x, suma=0;
    for(i=0; i<n; i++)
    {
        in>>x;
        pair <int, int> p;
        p.first=x;
        p.second=i+1;
        s0.push_back(p);
        suma+=x;
    }

    ordonare();

    //Graf simplu
    /*if(suma%2==1)
    {
        cout<<"\nSecventa data nu poate reprezenta un graf neorientat\n";
        return 0;
    }
    else
        if(n>=2 && s0[0].first<=n-1 && s0[n-1].first>=0)
        {
            i=0;
            int ok=1;
            while(ok && i<n)
            {

                HavelHakimi1(ok);
                i++;
                ordonare();
            }


            if(ok)
            {
                cout<<"Este graf simplu. Un graf simplu asociat ar putea fi urmatorul:\n";
                for(x=0; x<nrmuchii; x++)
                    cout<<"("<<G[x].first<<","<<G[x].second<<")"<<endl;
            }
            else
                cout<<"\nNu este graf simplu";

        }
        else
            cout<<"\nSecventa data nu poate reprezenta un graf neorientat\n";*/


    //Arbore
   /* if(suma==2*(n-1))
    {
        i=n-1;
        int ok=1;
        while(ok && i>=0)
        {
            HavelHakimi2(ok, i);
            i--;
            ordonare();
        }
        if(ok)
        {
                cout<<"Este arbore. Un arbore asociat ar putea fi urmatorul:\n";
                for(x=0; x<nrmuchii; x++)
                    cout<<"("<<Arb[x].first<<","<<Arb[x].second<<")"<<endl;
        }
    }
    else
        cout<<"\nSecventa data nu poate reprezenta un arbore\n";*/


    //Graf simpu conex
    if(suma%2==1 || suma<2*(n-1))
    {
        cout<<"\nSecventa data nu poate reprezenta un graf simplu conex\n";
        return 0;
    }
    else
        if(n>=2 && s0[0].first<=n-1 && s0[n-1].first>=0)
        {
            i=n-1;
            int ok=1;
            while(ok && i>=0)
            {

                HavelHakimi3(ok,i);
                i--;
                ordonare();
            }

            if(ok)
            {
                cout<<"Este graf simplu conex. Un graf simplu conex asociat ar putea fi urmatorul:\n";
                for(x=0; x<nrmuchii; x++)
                    cout<<"("<<Gconex[x].first<<","<<Gconex[x].second<<")"<<endl;
            }
            else
                cout<<"\nNu este graf simplu conex";

        }
        else
            cout<<"\nSecventa data nu poate reprezenta un graf neorientat\n";


    return 0;
}
