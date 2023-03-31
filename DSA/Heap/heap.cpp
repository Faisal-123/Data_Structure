#include <bits/stdc++.h>
using namespace std;
/*
To do Binary heap:
(1) insert(x) check
(2) max() check
(3) delete_max() check
(4) increase_key
(5) decrease_key
(6) make_heap
(7) merge
*/
// buuble down for first element in make_heap
long long last=1;
long long* heap=new long long[1000010];
void bubble_down(long long c){
	while(c*2<last){
		if((c*2)+1==last){
			swap(heap[c],heap[c*2]);
			c=c*2;
		}
		else{
			if(heap[c*2]>heap[(c*2)+1]){
				swap(heap[c],heap[c*2]);
				c=c*2;
			}
			else{
				swap(heap[c],heap[(c*2)+1]);
				c*=2;
				c++;
			}
		}
	}
}
void bubble_up(long long s){
	long long c;
	while(s/2>=1){
		c=s/2;
		if(heap[c]<heap[s]){
			swap(heap[c],heap[s]);
		}
		s=c;
	}
}
void increase_key(long long a,long long delta){
	heap[a]+=delta;
	bubble_up(a);
}
void decrease_key(long long a,long long delta){
	heap[a]-=delta;
	bubble_down(a);
}
void insert(long long x){
	heap[last]=x;
	bubble_up(last);
	last++;
}
void find_max(){
	cout<<heap[1]<<endl;
}
void delete_max(){
	swap(heap[1],heap[last-1]);
	last--;
	bubble_down(1);
}
int main(){
	// long long q;
	// cin>>q;
	for (int i=0;i<10;i++)
	{
		insert(i);
	}
	for (int i=0;i<10;i++)
	{
		cout<<heap[1]<<' ';
		delete_max();
	}
	// while(q--){
	// 	long long t;
	// 	cin>>t;
	// 	if(t==6){
	// 		long long n;
	// 		cin>>n;
	// 		for(int i=1;i<=n;i++){
	// 			cin>>heap[i];
	// 		}
	// 		last=n+1;
	// 		for(int i=n;i>0;i--){
	// 			bubble_down(i);
	// 		}
	// 	}
	// 	else if(t==5){
	// 		long long a,x;
	// 		cin>>a>>x;
	// 		decrease_key(a,x);
	// 	}
	// 	else if(t==4){
	// 		long long a,x;
	// 		cin>>a>>x;
	// 		increase_key(a,x);
	// 	}
	// 	else if(t==3)
	// 		find_max();
	// 	else if(t==2)
	// 		delete_max();
	// 	else{
	// 		long long x;
	// 		cin>>x;
	// 		insert(x);
	// 	}
	// for(int i=1;i<last;i++){
	// 	cout<<heap[i]<<' ';
	// }
	// cout<<endl;
	// }
	// return 0;
}
// insert 1 x
// delete_max 2
// max 3
// increase_key 4 i x
// decrease_key 5 i x
// make_heap 6 n a1,a2,...