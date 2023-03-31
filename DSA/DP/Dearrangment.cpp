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
ll fac[100];
ll fin(ll n){
		ll ans=fac[n];
		for(int k=1;k<=n;k++){
			if(k%2==0){
				ans+=fac[n]/fac[k];
			}
			else{
				ans-=fac[n]/fac[k];
			}
		}
		return ans;
}
int main(){
	Code By Faisal
	ll t=1;
	// cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll dp[n+1];
		dp[0]=1;
		for(int i=1;i<=n;i++){
			if(i%2==0){
				dp[i]=(dp[i-1]*i)+1;
			}
			else{
				dp[i]=(dp[i-1]*i)-1;
			}
		}
	}
	return 0;
}