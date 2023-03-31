#include <iostream>
#include <vector>

using namespace std;
#define int long long
const int MAXN=1e6+42069;
int st[MAXN];
int a[MAXN];

/*
Extra 
root 0
left child 2*i+1 s to mid
right child 2*i+2 mid to e
*/
//			0     0      n-1
void Make(int j,int s,int e)
{
	if(s==e){
		st[j]=a[s];
		// cout<<"Sum from "<<s<<" to "<<e<<" is "<<st[j]<<endl;
		return;
	}
	int mid=(s+e)/2;
	Make(2*j+1,s,mid);
	Make(2*j+2,mid+1,e);
	st[j]=st[2*j+1]+st[2*j+2];
	// cout<<"Sum from "<<s<<" to "<<e<<" is "<<st[j]<<endl;
}
//				0     0     n-1
void Update(int j,int s,int e,int i,int val)
{
	if(i>e || i<s)
	{
		return;
	}
	st[j]+=val;
	if(e!=s)
	{
		int mid=(e+s)/2;
		Update((2*j)+1,s,mid,i,val);
		Update((2*j)+2,mid+1,e,i,val);
	}
}

int Sum(int j,int s,int e,int l,int r)
{
	int ans=0;
	if(l<=s && e<=r)
	{
		return st[j];
	}
    if(l>e || r<s)
	{
		return 0;
	}
    if (l>e or s>r){
        return 0;
    }
	int mid=(s+e)/2;
	return Sum((2*j)+1,s,mid,l,r)+Sum((2*j)+2,mid+1,e,l,r);
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	Make(0,0,n-1);
	int t,l,r;
	for(int i=0;i<m;i++)
	{
		cin>>t>>l>>r;
		if(t==1)
		{
			Update(0,0,n-1,l,r-a[l]);
			a[l]=r;
		}
		else
		{
			cout<<Sum(0,0,n-1,l,r-1)<<'\n';
		}
	}
	return 0;
}