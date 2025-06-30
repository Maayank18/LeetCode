#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int finding(int n) {

        if( n == 0 || n == 1){
            return 1;
        }

        int oneStair = finding(n-1);
        int twoStair = finding(n-2);

        return oneStair+twoStair;
    }

int main(){
    int n = 3; // number of stairs
    int ways = finding(n);
    cout<<" the number of unique ways are : "<<ways<<endl;
    return 0;
}