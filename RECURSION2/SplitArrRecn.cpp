/* given array, Count and Print the number of ways array could be split in two groups,so that
sum of items in both groups is equal.Each number in the array must belong to one of the two groups.
n=6, arr=[1,2,3,3,4,5] */
#include<iostream>
#include<vector>
using namespace std ;

void solve(int n , vector<int>&arr, int index,int &cnt, int sum1, int sum2,vector<int>nums1,vector<int> nums2){
	
	if(index == n){ // base case
		if(sum1 == sum2 ){ // if equal , print the ans
			cnt++ ;
			for(int i=0; i<nums1.size();   i++){ cout<<nums1[i]<<" " ; }
			cout<<"and " ;
			for(int j=0; j<nums2.size(); j++){ cout<<nums2[j]<<" " ;}
			cout<<endl ;
		}
		return ;
	}
		
	nums1.push_back(arr[index]); // choice 1
	solve(n,arr,index+1,cnt, sum1+ arr[index], sum2, nums1,nums2);
	nums1.pop_back();

	nums2.push_back(arr[index]); // choice 2
	solve(n, arr, index+1, cnt, sum1, sum2+arr[index],nums1, nums2);
	nums2.pop_back() ;
}

int main(){
	int n ; cin>> n ;
	vector<int>arr(n) ;
	for(int i=0;i<n ; i++){
		cin>>arr[i];
	}

	int cnt=0;
	vector<int> nums1 , nums2 ;
	solve(n,arr,0, cnt,0, 0,nums1, nums2);
	cout<<cnt ;
	return 0;
}