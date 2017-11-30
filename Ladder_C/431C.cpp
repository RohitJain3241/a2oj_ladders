#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define REP(i,n) for(int i=0; i<n; i++)
typedef long long int ll;
#define mod 1000000007

vector<ll> combdp(102,-1);
vector<ll> fdp(102,-1);

//embed modulo and dp

ll comb(int n,int k){
    if(n==0) return 1;
    if(n<0) return 0;
    if(combdp[n]!=-1) return combdp[n];
    ll cnt = 0;
    for(int i=1;i<=k;i++){
        cnt = (cnt + comb(n-i,k))%mod;
    }
    return combdp[n] = cnt;
}

ll f(int n,int k,int d){
    if(n==0)
        return 0;
    if(fdp[n]!=-1)
        return fdp[n];
    ll cnt = 0;
    //This is our choice of branch
    for(int i=1;i<=k;i++){
        if(i<=n){
            //If we had chosen atleast 1 element greater than or equal to 'd' 
            if(i>=d)
                cnt = (cnt + comb(n-i,k))%mod;
            else
                cnt = (cnt + f(n-i,k,d))%mod;
        }
        //If we have branch value greater than sum we can't choose it!
        else
            break;
    }
    return fdp[n] = cnt;
}


int main(){
    int n,k,d;
    cin >> n >> k >> d;
    cout << f(n,k,d);
}        