// CONTAINER WITH MAXIMUM WATER PROBLEM 
// BRUTE FROCE APPRAOCH


// #include<iostream>
// #include<vector>
// #include<bits/stdc++.h>
// using namespace std;

// int finding(vector<int> &nums){
//     int n = nums.size();
//     int maxWater = 0;
//     for(int i = 0; i<n; i++){
//         for(int j = i+1; j<n; j++){
//             int minheight = min(nums[i],nums[j]);
//             maxWater = max(maxWater,(minheight*(j-i)));
//         }
//     }

//     return maxWater;
// }

// int main(){
//     vector<int> arr = {2,4,1,6,3,2,5,2,1};
//     int maxWater = finding(arr);
//     cout<<" the max amount of water that could be stored is : "<<maxWater<<endl;
//     return 0;
// }



// OPTIMAL APPROACH 

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int finding(vector<int> &height){
    int n = height.size();
    int maxWater = 0;
    int low = 0;
    int high = n-1;

    while(low < high){
        int minHeight = min(height[low],height[high]);
        int area = minHeight * (high-low);
        maxWater = max(maxWater,area);

        if(height[low] < height[high]){
            low++;
        }else{
            high--;
        }
    }

    return maxWater;
}

int main(){
    vector<int> arr = {2,4,1,6,3,2,5,2,1};
    int maxWater = finding(arr);
    cout<<" the max amount of water that could be stored is : "<<maxWater<<endl;
    return 0;
}