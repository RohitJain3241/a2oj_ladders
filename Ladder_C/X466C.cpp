#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
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
using namespace std;
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,st,end) for(int i=st;i<end;i++)
#define db(x) cout << (#x) << " = " << x << endl;
#define mp make_pair
#define pb push_back
#define MAX 10000005
typedef long long int ll;
int arr[1000005];
int count1[1000005];
int main(){
	int n;
	cin>>n;
	ll s=0;
	REP(i,n){
		cin>>arr[i];
		s+=arr[i];
	}
	if(s%3!=0){
		cout<<"0";
		return 0;
	}
	ll sum=s/3;
	ll temp=0;
	for(int i=n-1;i>=0;i--){
		temp+=arr[i];
		if(temp==sum){
			count1[i]+=1;
		}
	}
	for(int i=n-2;i>=0;i--){
		count1[i]+=count1[i+1];
	}
	temp=0;
	ll ans=0;
	for(int i=0;i+2<n;i++){
		temp+=arr[i];
		if(temp==sum){
			ans+=count1[i+2];
		}
	}
	cout<<ans;
}
