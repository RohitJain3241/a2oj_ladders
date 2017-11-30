#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    //n is the number of digits and
    //s is the sum of digits!
    int n,s;
    string large(""),small(""),temp("");
    cin >> n >> s;
    //No negative sum allowed or no greater sum allowed
    if(s<0 || 9*n<s){
    	cout << "-1 -1";
    	return 0;
    }
    //If sum=0 special case!
    if(s==0){
    	if(n==1)
    		cout << "0 0";
    	else
    		cout << "-1 -1";
    	return 0;
    }
    //We will first generate the largest number
    int s1 = s,digits=0;
    while(s1!=0){
    	if(s1>=9){
    		temp += ('0' + 9);
    		s1 -= 9;
    	}
    	else{
    		temp += ('0' + s1);
    		s1 = 0;
    	}
    	digits++;
    }
    large = temp;
    int dig=digits;
    //Now we will be appending 0's if necessary
    while(dig++!=n)
    	large += '0';
    
    //This is for no trailing zeros case!
    if(digits==n){
    	small = large;
    	reverse(small.begin(),small.end());
    	cout << small << " " << large;
    	return 0; 
    }

    //For trailing zeros case!
    small = "1";
    //no. of zeros in between are n-1-digits
    for(int i=0;i<n-1-digits;i++)
    	small += "0";

    //reversing temp
    reverse(temp.begin(),temp.end());
    //subtracting 1 from first one
    int val = temp[0]-'1'+'0';
    temp[0] = val;
    small += temp;
    cout << small << " " << large;
}
