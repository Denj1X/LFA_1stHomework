#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
vector < pair <int,char> > gr[100001];
bool workstuff(const string &cuv, int curent, int kekw[], int nr)
{   int curr=0,fnl=cuv.size();
    while(curr<fnl)
    {   char lit=cuv[curr];
        bool lit_flag=false;
        for(int i=0;i<gr[curent].size();i++)  ///1->2(a), 1->3(b) => 1:(2,a),(3,b) - size = 2
        {   if(gr[curent][i].second == lit)
            {   lit_flag=true;
                curent = gr[curent][i].first;
                break;
            }
        }
        if(!lit_flag) return false;
        ++curr;
    }
    for(int i=0;i<nr;i++)
        if(curent==kekw[i]) return true;
    return false;
}
int main()
{   int N,M,S,nrF,nrCuv;
    int nodes[100001],stf[100001];
    bool dfa=0;
    fin>>N;
    for(int i=0;i<N;i++)
        fin>>nodes[i];
    fin>>M;
    for(int i=0;i<M;i++)
    {   int x,y; char lit;
        fin>>x>>y>>lit;
        gr[x].push_back(make_pair(y,lit));
    }
    fin>>S;
    fin>>nrF;
    for(int i=0;i<nrF;i++)
        fin>>stf[i];
    fin>>nrCuv;
    for(int i=1;i<=nrCuv;i++)
    {   string cuv;
        fin>>cuv;
        if(workstuff(cuv,S,stf,nrF)) fout<<"DA"<<'\n';
        else fout<<"NU"<<'\n';
    }
    fout.close();
    return 0;
}
