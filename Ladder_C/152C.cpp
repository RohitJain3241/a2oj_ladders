#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main()
{
    long long n,m,res=1;
    cin >> n >> m;
    string arr[n];
    for(int i=0;i<n;i++)  cin >> arr[i];
    for(int j=0;j<m;j++){
        int cnt=0;
        vector<int> alpha(26,0);
        for(int i=0;i<n;i++){
            if(!(alpha[arr[i][j]-'A'])){
                alpha[arr[i][j]-'A'] = 1;
                cnt++;
            }
        }
        res *= cnt; res %= MOD;
    }
    cout << res;
}
