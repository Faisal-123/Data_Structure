#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int MN=2e5+5;
int n,m;
vector<pair<int,int>> adj[MN];
bool use[MN];
set<pair<int,int>> d;
long long Prim(int node){
	use[node]=1;
	for(auto i:adj[node])
		d.insert(i);
	while(d.size())
	{
		pair<int,int> k=*(d.begin());
		if(!use[k.second])
			return Prim(k.second)+k.first;
		d.erase(begin(d));
	}
	return 0;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		adj[x].push_back({w,y});
		adj[y].push_back({w,x});
	}
	cout<<Prim(1)<<endl;;
}