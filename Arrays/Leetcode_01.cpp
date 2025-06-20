#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

vector<int> finding(vector<int> &arr, int target){
    int n = arr.size();
    vector<int> temp;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(arr[i] + arr[j] == target){  // 1 + 2 == 3
                temp.push_back(i);
                temp.push_back(j);
                return temp;
                break;
            }
        }
    }
    return {};
}

int main(){
    vector<int> arr = {1,2,3,0,8};
    int target = 3;
    vector<int> result = finding(arr,target);
    cout<<" the target sum is achieved by index : ";
    for(auto it : result){
        cout<<it<<" ";
    }
    return 0;
}







#include<iostream>
#include<vector>
#include<map>
#include<bits/stdc++.h>
using namespace std;

vector<int> finding(vector<int> &arr, int target){
    map<int,int> mpp;  // value -> index
    int n = arr.size();
    vector<int> temp;

    for(int i = 0; i<n; i++){
        int moreNeed = target - arr[i];
        if(mpp.find(moreNeed) != mpp.end()){ // moreneeded = 1;
            temp.push_back(mpp[moreNeed]); // {1,0}
            temp.push_back(i);
            return temp;
            break;
        }
        mpp[arr[i]] = i;
    }
    return {};
}

int main(){
    vector<int> arr = {1,2,3,0,8};
    int target = 3;
    vector<int> result = finding(arr,target);
    cout<<" the target sum is achieved by index : ";
    for(auto it : result){
        cout<<it<<" ";
    }
    return 0;
}




#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

vector<int> finding(vector<int> &arr, int target){
    int n = arr.size();
    int low = 0;
    int high = n-1;

    vector<int> ans; // return 

    vector<pair<int,int>> temp1;  // storing value -> original index

    for(int i = 0; i<n; i++){
        temp1.push_back({arr[i],i});
    }

    sort(temp1.begin(),temp1.end()); // o(nlogn)

    while(low <= high){ // o(n)                         // o(nlogn) + o(n) = o(nlogn)
        int sum = temp1[low].first + temp1[high].first;

        if( sum == target){
            ans.push_back(temp1[low].second);
            ans.push_back(temp1[high].second);
            return ans;
            break;
        }
        else if(sum > target){
            high--;
        }else{  // sum < target
            low++;
        }
    }
    return {};
}

int main(){
    vector<int> arr = {1,2,3,0,8};
    int target = 3;
    vector<int> result = finding(arr,target);
    cout<<" the target sum is achieved by index : ";
    for(auto it : result){
        cout<<it<<" ";
    }
    return 0;
}
