// You are given an array of integers nums and an integer target.

// Return the number of non-empty subsequences of nums such that the sum of the 
// minimum and maximum element on it is less or equal to target. Since the
// answer may be too large, return it modulo 109 + 7.


#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

const int MOD = 1000000007;
int countSub = 0;

void finding(int idx,vector<int> &nums,vector<int>& curr,int target){
    if(idx == nums.size()){
        if(!curr.empty()){
            int maxi = *max_element(curr.begin(),curr.end());
            int mini = *min_element(curr.begin(),curr.end());
            if( maxi + mini <= target){
                countSub = (countSub+1)%MOD;
            }
        }
        return;
    }


    // take
    curr.push_back(nums[idx]);
    finding(idx+1,nums,curr,target);

    curr.pop_back();

    // not take case 
    finding(idx+1,nums,curr,target);
}

int main(){
    vector<int> nums = {3,5,6,7};
    int target = 9;
    vector<int> curr;
    finding(0,nums,curr,target);
    cout<<"the num of possible subsequence are : "<<countSub<<endl;
    return 0;
}






// BETTER CODE 

#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> nums = {3,5,6,7};
    int n = nums.size();
    int target = 9;
    const int MOD = 1000000007;
    int countSub = 0;

    vector<int> power2(n+1,1);
    for(int i = 1; i<=n; i++){
        power2[i] = (power2[i-1] * 2)%MOD;
    }

    int low = 0;
    int high = n-1;

    while( low <= high ){
        if(nums[low] + nums[high] <= target){
            countSub = (countSub + power2[high-low])%MOD;
            low++;
        }else{
            high--;
        }
    }

    cout<<countSub;
    return 0;
}