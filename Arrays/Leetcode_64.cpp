// // MINIMUM PATH SUM
// // UP - LEFT APPROACH

// #include<iostream>
// #include<vector>
// #include<bits/stdc++.h>
// using namespace std;

// int finding( vector<vector<int>> &arr, int n, int m){

//     // base case
//     if( n < 0 || m < 0){
//         return 1e9;
//     }

//     // base case 
//     if( n == 0 && m == 0){
//         return arr[n][m];
//     }

//     int up = arr[n][m] + finding(arr,n-1,m);
//     int left = arr[n][m] + finding(arr,n,m-1);

//     return min(up,left);
// }

// int main(){
//     vector<vector<int>> arr = {
//         {1,3,1},
//         {1,5,1},
//         {4,2,1}
//     };
//     int n = arr.size();
//     int m = arr[0].size();
//     int minimumPathSum = finding(arr,n-1,m-1);
//     cout<<" the minimum path sum is : "<<minimumPathSum<<endl;
//     return 0;
// }



// // MINIMUM PATH SUM
// // DOWN - RIGHT APPRAOCH

// #include<iostream>
// #include<vector>
// #include<bits/stdc++.h>
// using namespace std;

// int finding( vector<vector<int>> &arr, int rowIdx, int colIdx){

//     int n = arr.size();
//     int m = arr[0].size();

//     // base case
//     if( rowIdx == n-1 && colIdx == m-1){
//         return arr[rowIdx][colIdx];
//     }

//     // base case 
//     if( rowIdx >= n || colIdx >= m){
//         return 1e9;
//     }

//     int down = arr[rowIdx][colIdx] + finding(arr,rowIdx+1,colIdx);
//     int right = arr[rowIdx][colIdx] + finding(arr,rowIdx,colIdx+1);

//     return min(down,right);
// }

// int main(){
//     vector<vector<int>> arr = {
//         {1,3,1},
//         {1,5,1},
//         {4,2,1}
//     };
//     int minimumPathSum = finding(arr,0,0);
//     cout<<" the minimum path sum is : "<<minimumPathSum<<endl;
//     return 0;
// }





// BETTER APPROACH
// MEMOISATION

// MINIMUM PATH SUM
// DOWN - RIGHT APPRAOCH

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int finding( vector<vector<int>> &arr, int rowIdx, int colIdx,
            vector<vector<int>> &dp){

    int n = arr.size();
    int m = arr[0].size();

    // base case
    if( rowIdx == n-1 && colIdx == m-1){
        return arr[rowIdx][colIdx];
    }

    // base case 
    if( rowIdx >= n || colIdx >= m){
        return 1e9;
    }

    // base case
    if(dp[rowIdx][colIdx] != -1){
        return dp[rowIdx][colIdx];
    }

    int down = arr[rowIdx][colIdx] + finding(arr,rowIdx+1,colIdx,dp);
    int right = arr[rowIdx][colIdx] + finding(arr,rowIdx,colIdx+1,dp);

    return dp[rowIdx][colIdx] = min(down,right);
}

int main(){
    vector<vector<int>> arr = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    int minimumPathSum = finding(arr,0,0,dp);
    cout<<" the minimum path sum is : "<<minimumPathSum<<endl;
    return 0;
}