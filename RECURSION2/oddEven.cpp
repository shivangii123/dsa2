/* take input "N", Print odd numbers in decreasing order and even numbers in
increasing order using recursion // Example: Input: 5 Output: 5 3 1 2 4 */

#include<iostream>
using namespace std ;

void oddEven(int n ){
	if ( n<=0){ return ;}

	if(n %2 != 0){ //if odd
		cout<< n<< endl ; // Prints before the recursive call
	}
	oddEven(n-1); // when this reaches last index it moves down

	if(n%2 == 0){
		cout<<n<<endl;  // Prints even no. after... (increasing)
	}


}


int main() {
	int n ; cin>> n ;
	oddEven(n);
	return 0;
}