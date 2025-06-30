// #include<iostream>
// #include<map>
// #include<bits/stdc++.h>
// using namespace std;

// size_t maxlen = 0;

// void finding( int idx, vector<int> &ans, vector<int> &nums){
//     // base case
//     if(idx == nums.size()){
//         if(!ans.empty()){
//             int maxi = *max_element(ans.begin(),ans.end());
//             int mini = *min_element(ans.begin(),ans.end());

//             if( maxi - mini == 1){
//                 maxlen = max(maxlen, ans.size());
//             }
//         }
//         return;
//     }


//     // take case
//     ans.push_back(nums[idx]);
//     finding(idx+1,ans,nums);

//     ans.pop_back();
//     // not take
//     finding(idx+1,ans,nums);
// }

// int main(){
//     vector<int> nums = {1,3,2,2,5,2,3,7};  // 1 2 2 2  = 4, // 3 2 2 2 3 = 5
//     vector<int> ans;
//     finding(0,ans,nums); // 0 represents the index
//     cout<<maxlen;
//     return 0;
// }





#include<iostream>
#include<map>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {1,3,2,2,5,2,3,7};
    unordered_map<int,int> mpp;

    for(auto num : nums){
        mpp[num]++;
    }

    int maxlen = 0;

    for(auto it : mpp){

        int num = it.first;
        int count = it.second;
        
        if(mpp.find(num+1) != mpp.end()){
            maxlen = max(maxlen, count + mpp[num+1]);
        }
    }

    cout<<maxlen;

    return 0;
}