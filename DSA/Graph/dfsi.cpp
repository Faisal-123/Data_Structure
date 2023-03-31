#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAXN=2e5+10;

vector<int> adj[MAXN];
bool vis[MAXN];
int parent[MAXN];

void dfs(int a)
{
	stack<int> q;
	q.push(a);
	while(q.size())
	{
		int x=q.top();
		q.pop();
		if(!vis[x])
		{
			for(auto i:adj[x])
			{
				if(!vis[i])
				{
					parent[i]=x;
					q.push(i);
				}
			}
			vis[x]=1;
		}
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int c=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			// cout<<"JJR"<<endl;
			dfs(i);
			parent[i]=i;
			c++;
		}
	}
	cout<<"Number of Connected Component is "<<c<<endl;
	for(int i=1;i<=n;i++){
		cout<<"parent["<<i<<"] is "<<parent[i]<<endl;
	}
}