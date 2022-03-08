#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
vector<pair<int,char> > gr[100001];
bool nfa_alg(const string &cuv,int curent,int kekw[],int nr)
{   queue<pair<int,int> >q;
    ///pair.first = pozitia curenta
    ///pair.second = indicele pozitiei
    ///in relatie cu cuvantul dat
    q.push(make_pair(curent,0));
    int curr_node;
    while(!q.empty())
    {   bool lit_flag = false;
        curr_node = q.front().first;
        int index = q.front().second;
        q.pop();
        char lit = cuv[index];
        for(int i=0;i<gr[curr_node].size();i++)
        {   if(gr[curr_node][i].second == lit)
            {   lit_flag = true;
                curr_node = gr[curr_node][i].first;
                q.push(make_pair(curr_node,index+1));
                if(index+1 == cuv.size())
                {   for(int i=0;i<nr;i++)
                        if(curr_node==kekw[i]) return true;
                }
            }
        }
        if(!lit_flag) return false;
    }
    for(int i=0;i<nr;i++)
        if(curr_node==kekw[i]) return true;
    ///yup, fac doua verificari chiar daca complexitatea sucks
    return false;
}
int main()
{   int N,M,S,nrF,nrCuv;
    int nodes[100001],stf[100001];
    fin>>N;
    for(int i=0;i<N;i++)
        fin>>nodes[i];
    fin>>M;
    for(int i=0;i<M;i++)
    {   int x,y; char lit;
        fin>>x>>y>>lit;
        gr[x].push_back(make_pair(y,lit));
    }
    fin>>S>>nrF;
    for(int i=0;i<nrF;i++)
        fin>>stf[i]; ///starile finale
    fin>>nrCuv;
    for(int i=0;i<nrCuv;i++)
    {   string cuv;
        fin>>cuv;
        if(nfa_alg(cuv,S,stf,nrF)) fout<<"DA"<<'\n';
        else fout<<"NU"<<'\n';
    }
    fout.close();
    ///pentru cin si cout merge, dar oare pe fin si fout merge?
    return 0;
}
