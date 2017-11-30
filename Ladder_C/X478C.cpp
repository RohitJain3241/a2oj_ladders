#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define REP(i,n) for(int i=0; i<n; i++)
typedef long long int ll;

int main(){
    ll arr[3];
    REP(i,3){
       cin>>arr[i];
    }
    sort(arr,arr+3);
    if(arr[0]+arr[1]<=arr[2]/2){
        cout<<arr[0]+arr[1];
    }
    else{
        //Unusual at first!!
        cout<<((arr[0]+arr[1]+arr[2])/3);
    }
}        