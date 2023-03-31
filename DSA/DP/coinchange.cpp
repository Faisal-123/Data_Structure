#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define str to_string
#define in binary_search
#define vll vector<ll>
#define sll set<ll>
#define vstr vector<string>
#define ll long long
#define ld long double
#define pb push_back
#define add insert
#define rall(x) rbegin(x),rend(x)
#define all(x) (x).begin(),(x).end()
#define sum(a) accumulate(all(a),0)
#define index(a,e) find(all(a),e)-begin(a);
#define rotr(a,s) rotate(a.begin(),a.begin()+a.size()-s,a.end());
#define rotl(a,s) rotate(a.begin(),a.begin()+s,a.end());
#define rindex(a,e) find(rall(a),e)-rbegin(a);
#define replace(a,m,t) replace(a.begin(), a.end(), m, t)
#define rec(a,x)    reverse_copy (all(a), x.begin());
#define sortr(a) sort(rall(a))
#define mp make_pair
#define ff first
#define ss second
#define debug(a) cerr<<#a<<" == "<<a<<endl;
#define Code  ios_base::sync_with_stdio(false); 
#define Faisal cout.tie(NULL);
#define By cin.tie(NULL);
template<typename T1> inline ostream& operator << (ostream& out, vector<T1> a) { for(auto i:a){out<<i<<" ";};; return out; }

template<typename T1> inline istream& operator >> (istream& in, vector<T1>& a){ for(auto& i:a){in>>i;};return in;}

vstr split(string s, char del){
	stringstream ss(s);
	string word;
	vstr b;
	while (!ss.eof()) {
		getline(ss, word, del);
		b.pb(word);
	}
	return b;
}

bool Prime(ll n){
    if (n <= 1)
        return false;
    for (ll i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
}

void co(ll fg){
	cout<<"Case #"<<fg<<':'<<" ";
}
ll powmod(ll a,ll b,ll modulo)
{
	if(b==0){
		return 1;
	}
	ll temp=powmod(a,b/2,modulo);
	if(b%2==0){
		return (temp*temp)%modulo;
	}
	else{
		return (a*((temp*temp)%modulo))%modulo;
	}
}
const ll MAXN=1e5;
const ll INF=LLONG_MAX-100;
ll n,k;
vector<ll> ans[MAXN];
ll c[MAXN];
vll coins;
ll solve(int n)
{
	if(n==0)
	{
		c[n]=0;
		return 0;
	}
	if(n<0)
	{
		return INF;
	}
	c[n]=INF;
	for(auto i:coins)
	{
		ll x=solve(n-i)+1;
		if(x<c[n])
		{
			ans[n].clear();
			ans[n].pb(i);
			for(auto j:ans[n-i])
			{
				ans[n].pb(j);
			}
			c[n]=x;
		}
	}
	return c[n];
}
int main(){
	Code By Faisal
	cin>>n>>k;
	for(int i=0;i<k;i++)
	{
		ll y;
		cin>>y;
		coins.pb(y);
	}
	solve(n);
	if(c[n]==INF)
	{
		cout<<"not possible"<<endl;
	}
	else{
		map<ll,ll> cnt;
		for(auto i:ans[n])
		{
			cnt[i]++;
			// cout<<i<<' ';
		}
		for(int i=0;i<k;i++)
		{
			cout<<cnt[coins[i]]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
//1 sec 10^7
//debug use g++ -g I.cpp
//gdb ./a.out