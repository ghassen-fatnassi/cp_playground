#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TC while(t--)
 
const int MOD =1e9+7;
 
int main(){
    int n;
    cin>>n;
    vector<int> x;
    int in;
    for(int i=0;i<n;++i){
        cin>>in;
        x.push_back(in);
    }
    sort(x.begin(),x.end());
    ll sum=0;
    for(int i=0;i<n;++i){
        if(x[i]-sum>1){cout << sum+1;return 0;}
        sum=sum+x[i];
    }
    cout << sum+1;
    return 0;
}