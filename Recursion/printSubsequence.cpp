#include <iostream>
#include <vector>
using namespace std;

void subsets(int ind,int arr[],vector<int>& ans){

    if(ind>=5){
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }

    //take 
    ans.push_back(arr[ind]);
    subsets(ind+1,arr,ans);
    ans.pop_back();
    subsets(ind+1,arr,ans);

}



int main(){

    int arr[5]={3,1,2,8,9};
    vector<int> ans;
    subsets(0,arr,ans);
}
