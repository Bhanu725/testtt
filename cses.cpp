#include <bits/stdc++.h>
using namespace std;

int N = 2e5+5;
vector<long long> t(4*N);
vector <long long> a(N);
void build(int l,int r,int v){
    if(l==r){ 
        t[v] = a[l];
        return;
    }
    int m = (l+r)/2;
    build(l,m,2*v);
    build(l,m,2*v+1);
}
long long query(int l,int r,int v,int ql,int qr){
    if(ql>r || qr<l) return 0;
    if(ql<=l && r<=qr) return t[v];
    int m = (l+r)/2;
    return query(l,m,2*v,ql,qr)+query(m+1,r,2*v+1,ql,qr);
}
void update(int l,int r,int v,int pos,long long val){
    if(l==r){
        t[v] = val;
        return;
    }
    int m = (l+r)/2;
    if(pos<=m) update(l,m,2*v,pos,val);
    else update(m+1,r,2*v+1,pos,val);
    t[v] = t[2*v]+t[2*v+1];
}
int main() {
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>a[i];
    build(0,n-1,1);
    for(auto it:t) {
        if(it!=0) cout<<it<<" ";
    }
    while(q--){
        int qu;
        cin>>qu;
        if(qu==1){
            int k,u;
            cin>>k>>u;
            update(0,n-1,1,k-1,u);
        }
        else{
            int a,b;
            cin>>a>>b;
            cout<<query(0,n-1,1,a-1,b-1)<<endl;
        }
    }
    
}