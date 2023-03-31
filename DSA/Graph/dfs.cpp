#include <iostream>
#include <vector>

using namespace std;

const int MAXN=2e5+10;

vector<int> adj[MAXN];
bool vis[MAXN];
int parent[MAXN];

void dfs(int a)
{
	vis[a]=1;
	for(int i:adj[a]){
		if(!vis[i]){
			parent[i]=a;
			dfs(i);
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