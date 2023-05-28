#include<bits/stdc++.h>
void dfs(int node,stack<int>&st,unordered_map<int,bool>&vis,unordered_map<int,list<int>>&adj)
{
	vis[node] = true;
	for(auto i: adj[node])
	{
		if(!vis[i])
		{
			dfs(i, st, vis, adj);
		}
	}
	st.push(node);
}
void revdfs(int node,unordered_map<int,bool>&vis,unordered_map<int,list<int>>&adj)
{
	vis[node] = true;
	for(auto i:adj[node])
	{
		if(!vis[i])
		{
			revdfs(i,vis,adj);
		}
	}
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Write your code here.
	unordered_map<int,list<int>>adj;
	for(int i =0; i< edges.size();i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
	}
	stack<int>st;
	unordered_map<int,bool>vis;
	for(int i =0;i<v;i++)
	{
		if(!vis[i])
		{
			dfs(i,st,vis,adj);
		}
	}
	unordered_map<int,list<int>>transpose;
	for(int i =0;i<v;i++)
	{
		vis[i] = 0;
		for(auto nbr:adj[i])
		{
			transpose[nbr].push_back(i);
		}
	}

	int count = 0;
	while(!st.empty())
	{
		int top = st.top();
		st.pop();
		if(!vis[top])
		{
			count++;
			revdfs(top,vis,transpose);
		}
	}
	return count;
}