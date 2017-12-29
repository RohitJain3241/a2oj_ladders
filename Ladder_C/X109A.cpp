#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,mini=INT_MAX;
    cin >> n;
    pair<int,int > coeffs;
    coeffs.first = 1000000;
    coeffs.second = 1000000;
    //We will use the eqn as a*4 + b*7 = n
    //We will first find a value of 'b'
    for(int b=0;n-7*b>=0;b++){
        int a = (n-b*7)/4;
        if( (n-b*7)%4==0){
            if(a+b<mini){
            //We will take the a,b for which we have a+b minimum
            coeffs.first = a; coeffs.second = b; mini = a+b;
            }
            else if(a+b==mini && b<coeffs.second){
                coeffs.first = a; coeffs.second = b;
            }
        }
    }
    if(coeffs.first==1000000){
        cout << "-1";
        return 0;
    }
    for(int i=0;i<coeffs.first;i++) cout << "4";
    for(int i=0;i<coeffs.second;i++) cout << "7";
}
