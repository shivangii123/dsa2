/*Given an integer 'n'. Print all the possible pairs of 'n' balanced parentheses.
The output strings should be printed in the sorted order considering '(' has
higher value than ')'.*/
#include<iostream>
using namespace std ;

void generate(int n,int op,int cl, string ans){
	if(cl == 0 && op == 0){ // base case
		cout<< ans <<endl ;
		return ;
	}
	
	if(cl> op){
		ans.push_back(')');
		generate(n,op,cl-1,ans);
		ans.pop_back();
	}

	if(op > 0){
		ans.push_back('(');
		generate(n,op-1,cl,ans) ;
		ans.pop_back();
	}
	
}

int main() {
	int n; cout<<"Enter n: "; cin>>n ;
	int op= n, cl= n ;
	string ans ="" ;

	generate(n , op,cl, ans);
	return 0;
}