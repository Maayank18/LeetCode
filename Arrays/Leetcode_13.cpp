// CONVERT ROMAN ALPHABETS TO THE NUMBER 

#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<map>
using namespace std;

int finding( string &s){
    int n = s.size();

    map<char,int> mpp = { {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };

    int ans = 0;

    for(int i = 0; i<n; i++){
        int currentEle = mpp[s[i]];
        int nextEle = s[i+1] ? mpp[s[i+1]] : 0; 

        if(currentEle < nextEle){
            ans -= currentEle;
        }else{
            ans += currentEle;
        }
    }

    return ans;
}


int main(){
    string s = "XIX";
    int number = finding(s);
    cout<<"the converted roman number is :"<< number<<endl;
    return 0;
}