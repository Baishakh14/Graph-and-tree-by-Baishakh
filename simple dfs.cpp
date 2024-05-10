#include<bits/stdc++.h>
using namespace std;
#define n 100001
bool visit[n];
void dfs(int root,vector<int>graph[])
{
    cout<<root<<' ';
    visit[root] = true;
    for(int i = 0;i<graph[root].size();i++)
    {
        if(visit[graph[root][i]] == 0)
        {
            dfs(graph[root][i],graph);
        }
    }
}
int main()
{
    memset(visit,false,sizeof(visit));
  vector<int>graph[n];
 int node, edge;
 cin>>node>>edge;
 for(int i = 0;i<edge;i++)
 {
    int v1,v2;
    cin>>v1>>v2;
    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
 }
 dfs(3,graph);

    return 0;
}
