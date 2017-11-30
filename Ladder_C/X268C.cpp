#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int n, m;
    scanf("%d%d", &n, &m);
    int k = min(n,m);
    //As we can choose only one index from each 'm' coordinate 
    //Or 'n' coordiante whichever is minimum 
    //as if we choose same coordinate then it reduces to integer inside root.
    printf("%d\n",k+1);
    for(int i=0;i<=k;i++){
    	 printf("%d %d\n", i, k - i);
    }
}