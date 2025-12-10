#include<iostream>
#include<vector>
using namespace std;

bool isSorted(vector<int> arr , int n ){
    if(n<=1 ) return true ;
    if(arr[n-1] > arr[n-2] && isSorted(arr, n-1)){
        return true ;
    }
    return false ;
}

int main(){
    int n ;
    cout<< "Enter size n : "; cin >> n ;

    vector<int> arr(n);
    cout<<"Enter elements : " ;
    for(int i=0;i<n; i++){
        cin>> arr[i] ;
    }
    // int arr[]= {1,3,5,64} ;


    if(isSorted(arr, n) ){
    cout<<"Sorted "; }
    else{ 
        cout <<"Not Sorted " ; }
    return 0;
}