#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TC while(t--)
 
const int MOD =1e9+7;
 
int main(){
    int n;
    cin>>n;
    ll x[n];
    for(int i=0;i<n;++i){
        cin>>x[i];
    }
    ll curr_sum=0,max_sum=0, mx = x[0];
    int l=0;
    while(l<n){
        mx = max(mx, x[l]);
        curr_sum+=x[l++];
        
        if(curr_sum<0){
            curr_sum=0;
        }
        else{
            if(max_sum<curr_sum){max_sum=curr_sum;}
        }
    }
    if(curr_sum>max_sum) max_sum=curr_sum;
    cout << (max_sum == 0 ? mx : max_sum);
    return 0;
}