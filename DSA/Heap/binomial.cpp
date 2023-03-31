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
struct heap{
	long long degree=0;
	long long data=-LLONG_MAX;
	heap* parent=NULL;
	vector<heap*> child;
};
/*
To do Binomial heap:
(1) insert(x) check
(2) max() doing
(3) delete_max()
(4) increase_key
(5) decrease_key
(6) make_heap
*/
vector<heap*> h(10,NULL);
ll last=10;
// extra
void printheap(heap* a){
	if(a==NULL){
		return ;
	}
	cout<<a->data<<endl;
	for(auto i:a->child){
		printheap(i);
	}
}
void printfullheap(){
	for(int i=0;i<last;i++){
		printheap(h[i]);
		cout<<endl;
	}
}
// finish extra 
heap* manu=new heap;
// O(1) for merge
heap* merge(heap* a,heap* b){
	if(a->data < b->data){
		swap(a,b);
	}
	b->parent=a;
	a->degree+=1;
	a->child.pb(b);
	return a;
}
///O(lg n)
void mergefull(heap* a){
	if(a==NULL){
		return;
	}
	int i=a->degree;
	while(h[i]!=NULL){
		a=merge(a,h[i]);
		h[i]=NULL;
		i++;
	}
	h[i]=a;
}
//O(lg n)
void insert(heap* fd){
	if(fd->data>manu->data){
		manu=fd;
	}
	mergefull(fd);
}
//O(1)
int ma(){
	return manu->data
	// cout<<manu->data<<endl;
}
// void delete_max(){
//O(lg n)
void delete_max(){
	// manu should be root
		// delete manu;
	manu=new heap;
	for(int i=0;i<last;i++){
		if(h[i]!=NULL){
			if(manu->data < h[i]->data){
				manu=h[i];
			}
		}
	}
	vector<heap*> g=manu->child;
	h[manu->degree]=NULL;
	for(auto i:g){
		mergefull(i);
	}
	delete manu;
	manu=new heap;
	manu->data=-LLONG_MAX;
	for(int i=0;i<last;i++){
		if(h[i]!=NULL){
			if(manu->data < h[i]->data){
				manu=h[i];
			}
		}
	}
}
// void mergeheap(vector<heap*> a,vector<heap*> b){

// }
// }
int main(){
	Code By Faisal
	while(1){
		string com;
		cin>>com;
		if(com=="insert"){
			long long x;
			cin>>x;
			heap* j=new heap;
			j->data=x;
			insert(j);
		}
		else if(com=="max"){
			ma();
		}
		else if(com=="delete_max"){
			delete_max();
		}
		else if(com=="increase_key"){
			
		}
		else if(com=="decrease_key"){

		}
		else if(com=="make_heap"){
			ll n;
			cin>>n;
			manu=new heap;
			for(int i=0;i<last;i++){
				h[i]=NULL;
			}
			last=n;
			for(int i=0;i<n;i++){
				ll a;
				cin>>a;
				heap* f=new heap;
				f->data=a;
				if(manu->data<a){
					manu=f;
				}
				insert(f);	
			}
		}
		else{
			printfullheap();
			// break;
		}
	}
	return 0;
}