#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string abc;
    cin >> abc;
    //This is for removal of longest same lettered string
    for(int i=1;i<abc.length();i++){
        int counter = 1,j=i;
        while(abc[j]==abc[j-1]){
            counter++;j++;
        }
        if(counter>2){
            abc.erase(i,counter-2);
        }
    }
    for(int i=2;i<abc.length();i++){
        if(abc[i]==abc[i-1] && abc[i]==abc[i-2]){
            abc.erase(i-2,1);
            i--;
        }
        else if(i>2 && abc[i]==abc[i-1] && abc[i-2]==abc[i-3]){
            abc.erase(i-1,1); i--;
        }
    }
    cout << abc;
}
