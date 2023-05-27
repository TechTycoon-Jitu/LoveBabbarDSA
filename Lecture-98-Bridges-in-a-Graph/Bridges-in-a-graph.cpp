#include<bits/stdc++.h>
void dfs(int node,int parent,int timer,vector<int>&disc,vector<int>&low,
unordered_map<int,bool>&visited, vector<vector<int>>&result,unordered_map<int,list<int>>&adj)
{
    visited[node] = true;
    disc[node] = low[node] = timer++;
    for(auto i:adj[node])
    {
        if(i==parent)
        
            continue;
        
        if(!visited[i])
        {
            dfs(i,node,timer,disc,low,visited,result,adj);
            low[node] = min(low[node],low[i]);
            if (low[i] > disc[node]) {
                       vector<int>ans;
              ans.push_back(node);
              ans.push_back(i);
              result.push_back(ans);
            }
        }
        else
        {
            low[node] = min(low[node],disc[i]);
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int,list<int>>adj;
    for(int i= 0; i< edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int timer = 0;
    vector<int>disc(v);
    vector<int>low(v);
    int parent = -1;
    unordered_map<int,bool>visited;
    vector<vector<int>>result;
    for(int i =0; i< v;i++)
    {
        disc[i] =-1;
        low[i] =-1;
    }
    for(int i =0; i<v; i++)
    {
        if(!visited[i])
        {
            dfs(i,parent,timer,disc,low,visited,result,adj);
        }
    }
   return result;
}