#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,st,end) for(int i=st;i<end;i++)
#define db(x) cout << (#x) << " = " << x << endl;
#define mp make_pair
#define pb push_back
#define MAX 10000005
typedef long long int ll;

int main()
{
    string abc;
    cin >> abc;
    ll a,b,n=abc.length();
    cin >> a >> b;
    if(n==1){
        cout << "NO"; return 0;
    }
    //This saves if the number ending with i is divisible at a
    vector<bool> first(n,false);
    ll a_div=0;
    for(int i=0;i<n;i++){
        a_div = ( 10*a_div + (abc[i]-'0') )%a;
        if( a_div == 0 ){
            first[i] = true;
        }
    }
    //This saves if the number starting with i is divisible at b
    vector<bool> last(n,false);
    ll p = 1,b_div=0;
    for(int i=n-1;i>=0;i--){
        b_div = (p*(abc[i]-'0') + b_div)%b;
        p = (p*10)%b;
        if( b_div == 0 ){
            last[i] = true;
        }
    }
    bool flag = false;
    //This checks if there is any i for which both are divisible
    for(int i=0;i<n;i++){
        if(first[i] && last[i+1] && abc[i+1]!='0'){
            cout << "YES" << endl;
            cout << abc.substr(0,i+1) << endl;
            cout << abc.substr(i+1,n-i-1);
            flag = true;
            break;
        }
    }
    if(!flag)
        cout << "NO";
}
