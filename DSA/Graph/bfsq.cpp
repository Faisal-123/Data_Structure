#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAXN=2e5;
vector<int> adj[MAXN];
int parent[MAXN];
bool vis[MAXN];

void bfs(int a)
{
	queue<int> q;
	q.push(a);
	while(q.size())
	{
		int x=q.front();
		q.pop();
		if(!vis[x])
		{
			for(auto y:adj[x])
			{
				if(!vis[y])
				{
					parent[y]=x;
					q.push(y);
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
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int cc=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			bfs(i);
			cc++;
			parent[i]=i;
		}
	}
	cout<<"#CC "<<cc<<endl;
	for(int i=1;i<=n;i++)
		cout<<"parent["<<i<<"] is "<<parent[i]<<endl;
	return 0;
}