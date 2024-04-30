#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TC while(t--)
 
const int MOD =1e9+7;

int main(){
    int t;
    cin>>t;
    int binary_arr[31];
    binary_arr[0]=1;
    for(int i=1;i<31;i++){
        binary_arr[i]=(1<<i)+binary_arr[i-1];
    }
    TC{
        int n;
        cin>>n;
        int a[n];
        int isar_max[n];
        int temp_max=a[0];
        int in;cin>>in;a[0]=in;
        isar_max[0]=in;
        for(int i=1;i<n;++i){
            cin>>in;
            a[i]=in;
            if(in>temp_max){isar_max[i]=in;temp_max=in;}
        }

        cout <<endl;
    }
    return 0;
}