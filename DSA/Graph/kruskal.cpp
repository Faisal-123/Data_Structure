#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#define int long long
using namespace std;
int ans=0;
int parent[200001];
vector<int> S[200001];
void Union(int i,int j,int c){
	int ci=parent[i],cj=parent[j];
	if(ci==cj)
		return;
	ans+=c;
	if(S[ci].size()>S[cj].size())
		swap(ci,cj);
	for(auto i:S[ci]){
		parent[i]=cj;
		S[cj].push_back(i);
	}
	S[ci].clear();
}
main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		parent[i]=i;
		S[i].push_back(i);
	}
	vector<tuple<int,int,int>> e;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		e.push_back({c,a,b});
	}
	sort(begin(e),end(e));
	for(auto i:e)
		Union(get<1>(i),get<2>(i),get<0>(i));
	cout<<ans<<endl;
	return 0;
}