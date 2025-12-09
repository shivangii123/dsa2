#include<iostream>
#include<cmath>
#include<vector>
using namespace std ;

bool isSafe(vector<vector<char>> &board, int i , int j , int n , int dig){
    for(int r=0;r<n;r++){ //check vertically for all n rows
        if(board[r][j]== dig + '0'){ return false ;}
    }

    for(int c=0;c<n;c++){   // check horizontally
        if(board[i][c]==dig + '0'){
            return false ;}
    }

    int temp = sqrt(n) ;
    int start_i= (i/temp)*temp , start_j = (j/temp)*temp;
    for(int i= start_i; i<start_i+temp ; i++ ){ // check grid
        for(int j=start_j; j<start_j+temp ;j++){
            if(board[i][j]==dig +'0' ){return false ;}
        }
    }
    return true ;
}

bool  sudokuSolver(vector<vector<char>>&board, int i , int j , int n ){
    // base case
    if(i== n){ 
        for(auto x: board){
            for(auto y: x){
                cout<<y <<" ";
            }
            cout<<endl ;
        }
        return true ;
    }

    if(j==n){
        return sudokuSolver(board,i+1, 0,n) ;
    }

    if(board[i][j] !='.'){
        return sudokuSolver(board, i, j+1,n);
    }

    // recursive case

        for(char dig=1; dig<=9; dig++){
            if(isSafe(board, i , j , n, dig)){
                board[i][j]= dig +'0' ;

                bool ans = sudokuSolver(board, i,j+1, n);
                if(ans== true){ return true ;}

                board[i][j]= '.'; // backtrack
            }
        }
    return false;
}

int main(){
    // int n ;cout<<"Enter n : " ; cin>> n;
int n =9;
    cout<<"----SUDOKU GAME ----\n " ;

    vector<vector<char>> board = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},

    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},

    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
};

    sudokuSolver(board, 0,0,n);

    return 0;
}

