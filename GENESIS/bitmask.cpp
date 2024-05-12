#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define ll long long
#define TC while(t--);

const ll inf=1e9+5;

int main()
{
    FAST;
    int t;
    cin>>t;
    int n,l,r,x;
    cin>>n>>l>>r>>x;
    vector<int> c(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    int nb=0;
    for(int i=0;i<(1<<n);i++){
        int maxi=0,a=0,mini=inf,somme=0;
        for(int j=0;j<n;j++){
            int bitmask=1<<j;
            int cal=i&bitmask;
            /*if(cal!=0){
                somme+=c[n-j-1];
                maxi=max(maxi,c[n-j-1]);
                mini=min(mini,c[n-j-1]);
                a++;
            }*/
        }
        if( /*(a>1 )&& (somme<=r) && (somme>=l) && ((maxi-mini)>=x)*/){nb++;}
    }

    cout<<nb<<endl;

    return 0;
}