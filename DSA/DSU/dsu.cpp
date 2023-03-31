#include <map>
#include <iostream>
#include <vector>
using namespace std;
int parent[200001];
vector<int> S[200001];
void join(int i,int j){
    int ci=parent[i];
    int cj=parent[j];
    if(ci==cj)
    {
        return;
    }
    if(S[ci].size()>S[cj].size())
        swap(ci,cj);
    for(auto i:S[ci]){
        parent[i]=cj;
        S[cj].push_back(i);
    }
    S[ci].clear();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        parent[i]=i;
        S[i].push_back(i);
    }
    return 0;
}