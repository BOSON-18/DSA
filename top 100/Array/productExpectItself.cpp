#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums={-1,1,0,-3,3};
    int n=nums.size();
    vector<int>prefix(n,1),suffix(n,1);
    vector<int> ans;

    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]*nums[i-1];
        suffix[(n-1)-i]=suffix[(n-1)-i+1]*nums[(n-1)-i+1];
    }    

    for(int i=0;i<n;i++){
        ans.push_back(prefix[i]*suffix[i]);
        cout<<prefix[i]*suffix[i]<<" ";
    }
}