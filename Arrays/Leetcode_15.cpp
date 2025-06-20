// #include<iostream>
// #include<vector>
// using namespace std;

// vector<vector<int>> finding(vector<int> &nums, int target) {
//     int n = nums.size();
//     vector<vector<int>> result;

//     for(int i = 0; i < n; i++){
//         for(int j = i+1; j < n; j++){
//             for(int k = j+1; k < n; k++){
//                 if (nums[i] + nums[j] + nums[k] == target) {
//                     vector<int> temp;
//                     temp.push_back(nums[i]);
//                     temp.push_back(nums[j]);
//                     temp.push_back(nums[k]);
//                     result.push_back(temp); // store triplet
//                 }
//             }
//         }
//     }
//     return result;
// }

// int main() {
//     vector<int> nums = {-1,0,1,2,-1,-4};
//     int target = 0;
//     vector<vector<int>> ans = finding(nums, target);

//     for(int i = 0; i < ans.size(); i++){
//         for(int j = 0; j < ans[i].size(); j++){
//             cout << ans[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }







#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<vector<int>> finding(vector<int> &nums, int target) {
    int n = nums.size();
    set<vector<int>> st;
    vector<vector<int>> result;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                if (nums[i] + nums[j] + nums[k] == target) {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    st.insert(temp); // store triplet
                }
            }
        }
    }


    for( auto it : st){
        result.push_back(it);
    }

    return result;
}

int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    int target = 0;
    vector<vector<int>> ans = finding(nums, target);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}