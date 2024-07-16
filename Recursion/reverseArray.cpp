#include<iostream>
using namespace std;

void reverse(int arr[],int left,int right){

    if(left>right){
        return ;
    }

    swap(arr[left],arr[right]);

    reverse(arr,left+1,right-1);

}

void reverseArr(int arr[],int left,int size){

    if(left>=size/2){
        return ;
    }

    swap(arr[left],arr[size-left-1]);

    reverse(arr,left+1,size);

}



void print(int arr[]){
    cout<<"Printing arr-> ";

    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    int arr[6]={1,2,3,4,5,6};

    print(arr);

    reverse(arr,0,5);

    print(arr);

    
    reverse(arr,0,5);

    print(arr);


}
