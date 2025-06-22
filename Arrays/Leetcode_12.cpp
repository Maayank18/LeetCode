// CONVERT ROMAN ALPHABETS TO THE NUMBER 

#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<vector>
#include<map>
using namespace std;

string finding( int &num){

    string ans = "";

    vector<string> chars = {
        "M", "CM", "D", "CD",
        "C", "XC", "L", "XL",
        "X", "IX", "V", "IV", "I"} ;
    vector<int> nums  = 
        {1000, 900, 500, 400,
         100, 90, 50, 40,
         10, 9, 5, 4, 1};

    int n = nums.size();

    for(int i = 0; i<n; i++){
        while( num >= nums[i]){
            ans += chars[i];
            num -= nums[i];
        }
    }

    return ans;

}


int main(){
    int num = 19;
    string roman = finding(num);
    cout<<"the converted roman number is :"<< roman <<endl;
    return 0;
}