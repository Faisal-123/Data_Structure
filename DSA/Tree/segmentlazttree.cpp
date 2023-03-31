#include <iostream>
#include <vector>

using namespace std;
#define int long long
const int MAXN=1e6+42069;
int st[MAXN];
int a[MAXN];
int lazy[MAXN];
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
// range addition
void Update(int j,int s,int e,int l,int r,int val)
{
	if(l>e || r<s or s>e)
	{
		return;
	}
	if(lazy[j]!=0)
	{
		// cout<<"Adding to "<<j<<endl;
		st[j]+=(e-s+1)*lazy[j];
		if(s!=e)
		{
            lazy[(j*2)+1] += lazy[j]; 
            lazy[(j*2)+2] += lazy[j]; 
		}
		lazy[j]=0;
	}
	if(l<=s and e<=r)
	{
		// cout<<"Adding to ";
		// cout<<" Range "<<s<<' '<<e<<endl;
		st[j]+=(e-s+1)*val;
		if(s!=e)
		{
            lazy[(j*2)+1] += val; 
            lazy[(j*2)+2] += val; 
		}
		return;
	}
	int mid=(e+s)/2;
	Update((2*j)+1,s,mid,l,r,val);
	Update((2*j)+2,mid+1,e,l,r,val);
	st[j]=st[(2*j)+1]+st[(2*j)+2];
}

int Sum(int j,int s,int e,int l,int r)
{
	if(lazy[j]!=0)
	{
		st[j]+=(e-s+1)*lazy[j];
		if(s!=e)
		{
            lazy[(j*2)+1] += lazy[j]; 
            lazy[(j*2)+2] += lazy[j]; 
		}
		lazy[j]=0;
	}
	int ans=0;
	if(l==s && e==r)
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
	// for(int i=0;i<n;i++)
	// {
	// 	cin>>a[i];
	// }
	// Make(0,0,n-1);
	int t,l,r;
	int v;
	for(int i=0;i<m;i++)
	{
		cin>>t>>l;
		if(t==1)
		{
			cin>>r>>v;
			// cout<<l<<' '<<r-1<<endl;
			Update(0,0,n-1,l,r-1,v);
		}
		else
		{
			// cout<<"sum id ";
			cout<<Sum(0,0,n-1,l,l)<<'\n';
		}
		// cout<<endl<<"array ";
		// for(int i=0;i<n;i++)
		// {
		// 	cout<<Sum(0,0,n-1,i,i)<<' ';
		// }
		// cout<<endl;
	}
	return 0;
}