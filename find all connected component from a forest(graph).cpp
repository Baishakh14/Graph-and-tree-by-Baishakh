#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5; ///const number for maximum size can hold
vector<int>g[mx];  ///2d vector to store adjacency list
bool visit[mx];  ///check which is visited or not
vector<int>com;  ///store to connected node;
vector<vector<int>>ab; ///store all connected node in 2d vector vector
void reset()
{
   for(int i = 0;i<mx;i++)  ///make reset function for reset the store
   {
      //visit[i] = false;
      com.clear();
      //ab[i].clear();
     // g[i].clear();
   }
}

void dfs(int v)   ///dfs using recursive function
{
   com.push_back(v);  ///store unvisited node in com vector
   visit[v] = true;
   for(auto it : g[v])
   {
      if(visit[it] == false)
      {
         dfs(it);  ///recursively calling dfs for each unvisited node;
      }
   }
}
int main()
{
 int v,e;
 cin>>v>>e; ///vertex and edges;
 for(int i = 0;i<e;i++)
 {
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);  ///store using adjacency list
    g[b].push_back(a);
 }
 for(int i = 1;i<=v;i++)
 {
   if(!visit[i])
   {
      //com.clear();
      reset();
      dfs(i);
      ab.push_back(com); ///store all connected component in ab vectr;
   }
 }
 cout<<"total connected component is "<<ab.size()<<endl; //total connected component using vector size;
 for(auto it : ab)
 {
   for(auto x : it)
   {
       cout<<x<<" "; ///printing the connected component;
   }
   cout<<endl;
 }
   return 0;
}
