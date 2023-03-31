#include <iostream>
#include <vector>

using namespace std;

const int MAXN=2e5;
vector<pair<int,int>> ma[MAXN];
bool vis[MAXN];

vector<int> toposort;
void dfs(int a){
	vis[a]=1;
	for(auto i:ma[a]){
		if(!vis[i.first]){
			dfs(i.first);
		}
	}
	toposort.push_back(a);
}

int main()
{
	int n,m;
	cin>>n>>m;
	for (int i = 0; i < m; ++i)
	{
		int u,v,w;
		cin>>u>>v>>w;
		ma[v].push_back({u,w});
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs(i);
		}
	}
	for(auto i:toposort){
		cout<<i<<' ';
	}
	return 0;
}