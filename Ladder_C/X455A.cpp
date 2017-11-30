#include <iostream>

//As the value of n ranges uptil 10e5
//This needs to be done in single variable DP!

using namespace std;
#define MAX 100005
typedef long long int ll;
//This saves the optimum number of points uptil i!
ll dp[MAX];
//This is basically a hash table!
ll count1[MAX];

ll maxi(ll a,ll b){
    return (a>b)? a:b;
}

ll maxpoint(){
    dp[0] = 0;
    dp[1] = 1*count1[1];
    for(int i=2;i<MAX;i++){
        dp[i] = maxi(dp[i-1],dp[i-2]+i*count1[i]);
                        }
    return dp[MAX-1];
}

int main()
{
    int n,a;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        count1[a]++;
                        }
    cout << maxpoint();
}
