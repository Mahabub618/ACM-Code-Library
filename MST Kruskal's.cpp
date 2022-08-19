#include<bits/stdc++.h>
using namespace std;

int nod,edg,par[100005];


struct edge
{
    int u,v,w;
   bool operator<(const edge& p) const
    {
         //cout<<w<<endl;
        return w>p.w;

    }

};

priority_queue<edge> pq;

int find(int r)
{
    if(par[r]==r)
        return r;
    return par[r]=find(par[r]);
}
void mst(void)
{
    for(int i=1; i<=nod; i++)
        par[i] = i;
    int cnt=0;
    int  sum = 0;
     vector< pair <int,int> > vec;
    while(!pq.empty())
    {
        edge top = pq.top();
        pq.pop();

        int u = top.u;
        int v = top.v;
      int  w = top.w;
        int a = find(u);
        int b = find(v);
        if(a!=b)
        {   vec.push_back(make_pair(u,v));
            sum+=w;
            cnt++;
            par[b] = par[a];

        }
        if(cnt==nod-1)
            break;
    }
    if(cnt == nod-1){

         cout<<"MST="<<sum<<endl;
        for(int i=0;i<nod-1;i++)
        {
            cout<<vec[i].first<<" "<<vec[i].second<<endl;
        }
    }
    else
        cout<<"-1"<<endl;
    while(!pq.empty())
    {
        pq.pop();
    }
}
int main()
{
    int test;

      cin>>nod>>edg;
        for(int i=0; i<edg; i++)
        {
            int u,v,w;

            cin>>u>>v>>w;
            edge get;
            if(u<v)
            {
                get.u = u;
                get.v  = v;
                get.w = w;
            }
            else
            {
                get.u = v;
                get.v = u;
                get.w = w;
            }
            pq.push(get);
        }
        mst();


    return 0;
}
