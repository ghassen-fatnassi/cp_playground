#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define TC while (t--)
const ll MOD = 998244353;

void solve()
{
    ll n;
    cin>>n;
    multiset<ll> a;
    bool odd=false;
    bool even=false;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        if(x%2==0){even=true;}else{odd=true;}
        if(even && odd){cout<<-1;return;}
        a.insert(x);
    }

    ll count=0;
    vector<ll> ops;
    while(count<=40){
        ll big=*a.rbegin();
        ll small=*a.begin();
        ll mid=(big+small)/2;
        if(mid==0){break;}
        else{
            multiset<ll> new_a;
            for(auto elm:a){
                new_a.insert(abs(elm-mid));
            }
            a = new_a;
            count++;
            ops.push_back(mid);
        }
    }
    cout<<count<<"\n";
    for(auto elm:ops){
        cout<<elm<<" ";
    }
}

int main()
{
    FASTIO
    ll t;
    cin >> t;
    TC
    {
        solve();
        cout<<"\n";
    }
    return 0;
}
