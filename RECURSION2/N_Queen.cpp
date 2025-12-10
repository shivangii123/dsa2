#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<string>&board ,int i, int j ){
    for(int r=i-1;r>=0 ;r--){ // check vertically
        if(board[r][j]=='Q')
            return false ; // if already queen-> "CLASH..""
    }
    for(int r=i-1 ,c=j-1 ; r>=0 && c>=0 ;r--,c--){// left upper diagonal
        if(board[r][c]=='Q')
            return false ;
    }
    for(int r=i-1,c=j+1 ; r>=0 && c<board.size() ;r--,c++){//right diagonal
        if(board[r][c]=='Q')
            return false ;
    }
    return true ;
}

void nQueen(vector<string>&board ,int i,int n, vector<vector<string>>&res ){
    // base case
    if(i==n){
        res.push_back(board);
        return ;
    }

    //recursive case
    for(int j=0;j<n ;j++){
        if (isSafe(board,i,j)){
            board[i][j]= 'Q'; //Make a choice

            nQueen(board, i+1,n,res); //Recursion for smaller problem

            board[i][j] ='.' ;  // UNDO
        }
    }
}

int main(){

    int n; cout<<"Enter n : " ; cin>>n ;
    vector<string>board (n,string(n,'.'));
    vector<vector<string>>res ;

    cout<<"So placing " <<n << " Queens on the board : \n";
    nQueen(board,0,n, res);


    for(auto x: res){
        cout<<"[" ;
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<"] \n\n" ;
    }

    return 0;
}