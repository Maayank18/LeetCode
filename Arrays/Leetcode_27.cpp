// // REMOVE DUPLICATE -> REMOVING ALL THE OCCURENCES


// // brute force / optimal
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int finding( vector<int> &nums, int val){
    int n = nums.size();

    int k = 0;
    for(int j = 0; j<n; j++){
        if(nums[j] != val){
            nums[k] = nums[j];
            k++;
        }
    }

    return k;
}

int main(){
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    int newSize = finding(nums,val);
    cout<<" the new updated size is : "<<newSize<<endl;
    return 0;
}




// best approach

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int finding( vector<int> &nums, int val){

    nums.erase(remove(nums.begin(),nums.end(),val),nums.end());

    return nums.size();
}

int main(){
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    int newSize = finding(nums,val);
    cout<<" the new updated size is : "<<newSize<<endl;
    return 0;
}