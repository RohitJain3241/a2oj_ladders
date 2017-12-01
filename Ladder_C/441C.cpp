#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define REP(i,n) for(int i=0; i<n; i++)
typedef long long int ll;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    //Making grid of directions
    //This has 2 if going down,0 for left,1 for right
    int grid[n][m],dir=1;
    for(int i=0;i<n;i++){
        //Defining direction for each row
        dir = (dir)%2;
        for(int j=0;j<m;j++){
            if(j==0 || j==m-1)
                grid[i][j] = 2;
            else
                grid[i][j] = dir;
        }
        //Change in direction!
        dir++;
    }
    //putting the direction for the last column or 0 th column
    for(int i=0;i<n;i++){
        if(i%2==0)
            grid[i][0] = 1;
        else
            grid[i][m-1] = 0;
    }

    //This is the x,y coordinate of the present place!
    int x=0,y=0,counter=0;
    //This is for assigning and printing cells for k-1 pipes
    for(int i=0;i<k-1;i++){
        cout << "2 ";
        //This is being updated for the last pipe!
        counter += 2;
        //We will find 3 steps and print those in each line
        for(int j=0;j<2;j++){
            cout << x+1 << " " << y+1 << " ";
            if(grid[x][y]==0)
                y--;
            else if(grid[x][y]==1)
                y++;
            else
                x++;
        }
        cout << endl;
    }

    //This is for the last pipe
    //We will start from present place and then go until we reach end
    cout << n*m-counter << " ";
    while(x<n){
        cout << x+1 << " " << y+1 << " ";
        if(grid[x][y]==0)
            y--;
        else if(grid[x][y]==1)
            y++;
        else
            x++;
    }
    cout << endl;

}
