#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    //n is the number of exams
    int n;
    cin >> n;
    vector<pair<int,int > > exam(n,make_pair(0,0));
    for(int i=0;i<n;i++)
        cin >> exam[i].first >> exam[i].second;
    //Sorts the vector of pairs on the basis of 1st element
    //and in case of same 1st element, we sort according to the 2nd element
    sort(exam.begin(),exam.end());
    int last = exam[0].second;
    for(int i=1;i<n;i++){
        if(exam[i].second >= last)
            last = exam[i].second;
        else
            last = exam[i].first;
    }
    cout << last;
}
