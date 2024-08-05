
#include<bits/stdc++.h>

using namespace std;

//brute force
int main(){

    vector<int> arr={1,2,3,6,3,6,1,5,5,8,9};
    unordered_map<int,int> mpp;
    vector<int> ans;

    for(int it : arr){
        mpp[it]++;
    }

    for(auto it : mpp){
        if(it.second>1){
            ans.push_back(it.first);
        }
    }

    for(int i :ans){
        cout<< i <<" ";
    }
}