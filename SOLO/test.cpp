#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TC while(t--)

const int MOD =1e9+7;

int main(){
    int n;
    cin >>n;
    int a[n];
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    int prefix[n];
    prefix[0]=a[0];
    for(int i=1;i<n;++i){
        prefix[i]=a[i]+prefix[i-1];
    }
    int t;
    cin >>t;
    TC{
        int l,r;
        cin>>l>>r;
        if(l==0){cout << prefix[r]<<"\n";}
        else{cout << prefix[r]-prefix[l-1]<<"\n";}
    }
    return 0;
}