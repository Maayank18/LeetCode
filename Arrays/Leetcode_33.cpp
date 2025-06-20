// SEARCH IN ROTATED SORTED ARRAY


#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int finding(vector<int> &nums,int target){
    int n = nums.size();

    int low = 0;
    int high = n-1;


    while(low <= high){
        int mid = low + (high-low)/2;

        if(nums[mid] ==  target){
            return mid;
        }

        // checking for left sorted array
        if(nums[low] <= nums[mid] ){
            if(nums[low] <= target && target <= nums[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }else{ // checking for right sorted
            if(nums[mid] <= target && target <= nums[high]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    int indexAns = finding(nums,target);
    cout<<" the target is found at : "<<indexAns<<endl;
    return 0;
}







// #include<iostream>
// #include<vector>
// #include<bits/stdc++.h>
// using namespace std;

// int finding(vector<int> &nums,int target){
    // int n = nums.size();

    // for(int i = 0; i<n; i++){
    //     if(nums[i] == target){
    //         return i;
    //     }
    // }

    // return -1;
}

// int main(){
//     vector<int> nums = {4,5,6,7,0,1,2};
//     int target = 0;
//     int indexAns = finding(nums,target);
//     cout<<" the target is found at : "<<indexAns<<endl;
//     return 0;
// }