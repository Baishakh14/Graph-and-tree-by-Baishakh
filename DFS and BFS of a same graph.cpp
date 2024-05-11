#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5;
vector<int>g[mx];
bool visit[mx];
queue<int>q;
vector<int>print_BFS;
void dfs(int root)
{
   cout<<root<<" ";
   visit[root] = true;
   for(auto it : g[root])
   {
      if(visit[it] == false)
      {
         dfs(it);
      }
   }
}

void bfs(int root)
{
    q.push(root);
    visit[root] = true;
   while(!q.empty())
   {
     int n = q.front();
     //visit[n] = true;
     print_BFS.push_back(n);
     q.pop();
     for(int i = 0;i<g[n].size();i++)
     {
      if(visit[g[n][i]] == false)
      {
         q.push(g[n][i]);
        visit[g[n][i]] = true;

      }
     }
   }

}
int main()
{
   memset(visit,false,sizeof(visit));
 int v,e; ///vertix and edges;
 cin>>v>>e;
 for(int i = 0;i<e;i++)
 {
   int a,b;
   cin>>a>>b;
   g[a].push_back(b);
   g[b].push_back(a);
 }
 cout<<"DFS traverse of this graph is : ";
 dfs(1);
 cout<<endl;
 memset(visit,false,sizeof(visit));
 bfs(1);
 cout<<"BFS traverse of this graph is : ";
 for(auto it : print_BFS)
 {
   cout<<it<<' ';
 }

   return 0;
}
