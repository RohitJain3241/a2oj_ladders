//This is not correct way to solve problem
//But when in hurry, solved it!

#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    //n is no. of 0's and m is no. of 1's
    int n,m;
    string res("");
    cin >> n >> m;
    if(n==m+1){
        res += "0";
        n--;
    }
    //either n==0 OR m==1|m==0
    while(n>=1 && m>=2){
        if(n==m || n==m+1){
            while(n!=0){
                res += "10";
                n--;m--;
            }
        }
        if(m>=2){
            res += "11";
            m -= 2;
        }
        if(n>=1){
            res += "0";
            n -= 1;
        }
    }
    //We would have got result if both conditions are met
    if(n==0 && m!=0){
        if(m==1){
            res += "1";
            m = 0;
        }
        else if(m==2){
            res += "11";
        }
        else
            res = "X";
    }
    if(m<=2 && n!=0){
        if(n==1){
            if(m==1)
                res += "10";
            else
                res += "110";
        }
        else if(n==2){
            if(m==1)
                res += "X";
            else
                res += "1010";
        }
        else
            res = "X";
    }
    if(res=="X")
        cout << -1;
    else
        cout << res;
}
