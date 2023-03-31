#include <bits/stdc++.h>
using namespace std;
#define str to_string
#define in binary_search
#define vll vector<ll>
#define sll set<ll>
#define vstr vector<string>
#define ll long long
#define ld long double
#define mll map<ll,ll>
#define mlb map<ll,bool>
#define pb push_back
#define add insert
#define rall(x) rbegin(x),rend(x)
#define all(x) (x).begin(),(x).end()
#define sum(a) accumulate(all(a),0)
#define index(a,e) find(all(a),e)-begin(a);
#define rotr(a,s) rotate(a.begin(),a.begin()+a.size()-s,a.end());
#define rotl(a,s) rotate(a.begin(),a.begin()+s,a.end());
#define elif else if
#define rindex(a,e) find(rall(a),e)-rbegin(a);
#define replace(a,m,t) replace(a.begin(), a.end(), m, t)
#define rec(a,x)    reverse_copy (all(a), x.begin());
#define sortr(a) sort(rall(a))
#define mp make_pair
#define ff first
#define ss second
#define debug(a) cerr<<#a<<" == "<<a<<endl;
#define Code ios_base::sync_with_stdio(false); 
#define By cin.tie(NULL);
#define Faisal cout.tie(NULL);
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
int main(){
	Code By Faisal
	ll n=100001;
	// cin>>n;
	int sieve[n+1];
	// memset(sieve,0,sizeof(sieve));
	for (int x = 2; x <= n; x++) {
		if (sieve[x]) continue;
		for (int u = 2*x; u <= n; u += x) {
			sieve[u] = x;
		}
	}
	ll a,b;
	cin>>a>>b;
	for(;a<=b;a++)
	{
		if(!sieve[a])
		{
			cout<<a<<' ';
		}
	}
	return 0;
}