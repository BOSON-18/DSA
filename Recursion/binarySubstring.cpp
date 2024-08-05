#include <iostream>
#include <vector>
using namespace std;

void subsets(int ind,int num,vector<char>& ans){
// cout<<"In recursive Call";
 if(ind==num){
    // cout<<"Substring:-";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return ;
 }

//  if(ans.back()=='1'){
//     ans.push_back('0');
//     subsets(ind+1,num,ans);
//     ans.pop_back();
//  }

//  if(ans.back()=='0'){
//     ans.push_back('1');
//     subsets(ind+1,num,ans);
//     ans.pop_back();
//     ans.push_back('0');
//     subsets(ind+1,num,ans);
//     ans.pop_back();
//  }

   ans.push_back('0');
    subsets(ind + 1, num, ans);
    ans.pop_back();

    // Recursive call: add '1' only if the last character is not '1'
    if(ans.empty() || ans.back() != '1'){
        ans.push_back('1');
        subsets(ind + 1, num, ans);
        ans.pop_back();
    }
}



int main(){

    int num=3;
    vector<char> ans;
    subsets(0,num,ans);
}
