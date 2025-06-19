// Median of two sorted array 

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int finding( vector<int> &arr1, vector<int> &arr2){
    vector<int> ans;

    int n = arr1.size();
    int m = arr2.size();

    for(int i = 0; i<n; i++){
        ans.push_back(arr1[i]);
    }

    for(int j = 0; j<m; j++){
        ans.push_back(arr2[j]);
    }
    sort(ans.begin(),ans.end());
    int totalSize = ans.size();

    if(totalSize % 2 == 1){
        return ans[totalSize/2];
    }
    if(totalSize % 2 == 0){
        return (ans[(totalSize-1)/2]+ans[totalSize/2])/2;
    }
}

int main(){
    vector<int> arr1 = {1,3,5};
    vector<int> arr2 = {2,4,6};
    int median = finding(arr1,arr2);
    cout<<" the median of two sorted array is : "<<median<<endl;
    return 0;
}