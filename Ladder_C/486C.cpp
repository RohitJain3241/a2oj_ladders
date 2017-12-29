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
int main(){
	int n,p;
	string str;
	scanf("%d%d",&n,&p);
	p--;
	cin>>str;
	int firstr;
	firstr=n/2-1;
	
	int diff=0;
	//maxi - index of the rightmost character that needs to be changed in the first half of the string
	//mini - index of the leftmost character that needs to be changed in the first half of the string
	int mini=99999,maxi=-1;
	if(p>firstr){
		reverse(str.begin(),str.end());
		p=n-1-p;
	}
	REP(i,firstr+1){
		if(str[i]!=str[n-1-i]){
			
			diff+=min((abs(str[i]-str[n-1-i])),abs(('z'-max(str[i],str[n-1-i]))+min(str[i],str[n-1-i])-'a'+1));
			mini=min(mini,i);
			maxi=max(maxi,i);
		}
	}
	if(maxi>p&&mini<p){
		if(abs(p-maxi)<abs(p-mini)){
			diff+=abs(p-maxi)*2;
			diff+=abs(p-mini);
		}
		else{
			diff+=abs(p-mini)*2;
			diff+=abs(p-maxi);
		}
	}
	else if(maxi>p)
		diff+=abs(p-maxi);
	else if(mini<p)
		diff+=abs(p-mini);
	
	cout<<diff;
	

}