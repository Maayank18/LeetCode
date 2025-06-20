// // // REMOVE DUPLICATES FROM SORTED ARRAY 

// #include<iostream>
// #include<vector>
// #include<bits/stdc++.h>
// #include<set>
// using namespace std;

// int finding( vector<int> &nums){
//     int n = nums.size();
//     set<int> st;

//     for(int i = 0; i<n; i++){
//         st.insert(nums[i]);
//     }

//     return st.size();

// }

// int main(){
//     vector<int> nums = {0,0,1,1,1,2,2,3,3};
//     int uniqueEle = finding(nums);
//     cout<<" the number of unique elements are : "<<uniqueEle<<endl;
//     return 0;
// }




// // BETTER / OPTIMAL APPRAOCH
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int finding( vector<int> &nums){
    int n = nums.size();
    
    int i = 0;
    for(int j = 1; j<n; j++){
        if(nums[j] != nums[j-1]){
            nums[i] = nums[j];
            j++;
        }
    }
    return i+1;

}

int main(){
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int uniqueEle = finding(nums);
    cout<<" the number of unique elements are : "<<uniqueEle<<endl;
    return 0;
}