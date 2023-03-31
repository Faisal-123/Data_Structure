#include <iostream>
#include <vector>

using namespace std;
#define int long long
const int MAXN=1e6+10;
int bit[MAXN];
int n;
int Sum(int i)
{
	i++;
	int ans=0;
	while(i>0){
		ans+=bit[i];
		i-=(i&(-i));
	}
	return ans;
}
void Update(int i,int x)
{
	int j=0;
	i++;
	while(i<=n)
	{
		bit[i]+=x;
		i+=(i&(-i));
	}
}
 main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int m,b;
	cin>>n>>m;
	vector<int> a;
	for(int i=0;i<=n;i++){
		bit[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		cin>>b;
		a.push_back(b);
		Update(i,b);
	}
	int t,l,r;
	for(int i=0;i<m;i++)
	{
		cin>>t>>l>>r;
		if(t==1)
		{
			Update(l,r-a[l]);
			a[l]=r;
		}
		else
		{
			cout<<Sum(r-1)-Sum(l-1)<<'\n';
		}
	}
	return 0;
}