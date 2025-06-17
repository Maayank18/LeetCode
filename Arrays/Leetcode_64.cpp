// MINIMUM PATH SUM

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int finding( vector<vector<int>> &arr, int n, int m){

    // base case
    if( n < 0 || m < 0){
        return 1e9;
    }

    // base case 
    if( n == 0 && m == 0){
        return arr[n][m];
    }

    int up = arr[n][m] + finding(arr,n-1,m);
    int left = arr[n][m] + finding(arr,n,m-1);

    return min(up,left);
}

int main(){
    vector<vector<int>> arr = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    int n = arr.size();
    int m = arr[0].size();
    int minimumPathSum = finding(arr,n-1,m-1);
    cout<<" the minimum path sum is : "<<minimumPathSum<<endl;
    return 0;
}