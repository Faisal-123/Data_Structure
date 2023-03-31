#include <iostream>
#include <string>
#include <cmath>
#include <assert.h>
#include <cstdlib>
#include <random>
#include <fstream>
#include <iomanip>
#include <vector>
#include <array>
#include <set>
// #include <bits/stdc++.h>
#include <limits>
#include <map>
#include <algorithm>
#include <ios>
#include <bitset>
using namespace std;
#define vvll vector<vll>
#define str to_string
#define in binary_search
#define vll vector<ll>
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
#define elif else if
#define rindex(a,e) find(rall(a),e)-rbegin(a);
#define replace(a,m,t) replace(a.begin(), a.end(), m, t)
#define rec(a,x)    reverse_copy (all(a), x.begin());
#define sortr(a) sort(rall(a))
#define mp make_pair
#define ff first
#define ss second
#define debug(a) cerr<<#a<<" == "<<a<<endl;
#define killer     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);iostream::sync_with_stdio(false);cin.tie(0);ios_base::sync_with_stdio(false); cout.tie(0); 
ll mod=(ll)pow(10,9)+7;
ll max_query=10000;
ll dp[10001][10001];
void init(ll n,ll r){
	for(int i=0;i<=n;i++){
		dp[i][0]=1;
	}
	for(int i=1;i<=r;i++){
		dp[0][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=r;j++){
			dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
			dp[i][j]%=mod;
		}
	}
}
ll nCr(ll n,ll r){return dp[n][r];}
int main(){
	init(max_query,max_query);
	ll q;
	cin>>q;
	while(q--){
		ll n,r;
		cin>>n>>r;
		cout<<nCr(n,r)<<endl;
	}
	return 0;
}