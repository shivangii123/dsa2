#include<iostream>
#include<vector>
using namespace std ;

bool solve(int n1, int n2, int i, int j,int cnt, string ans ){
	// base case ;
	if(i== n1-1 && j== n2-1){
		cnt++ ;
		for(auto x: ans){
			cout<< x ;
		}
		cout<<" ";
		return true ;}

	if(i>=n1 || j>=n2){ return false ;}

	// vertical
	if(solve(n1, n2, i, j+1,cnt, ans +'V' )){
		return true ;
	}
	// horizontal
	if(solve(n1,n2,i+1,j,cnt, ans+'H')){
		return true ;
	}
	return false ;

}

int main(){
	int n1 ,n2 ;
	string ans="" ;
	solve(n1,n2,0,0,0,ans);


	return 0;
}