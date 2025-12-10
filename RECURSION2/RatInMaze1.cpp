// /* Rat at (0, 0) in an n x n mat[][].Rat's goal reach(n-1, n-1).
// 4 direction to move :U, D, L, R ; '0'->blocked ,1->free  Find all possible paths
// Input: mat[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
/*1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1*/
// Output: ["DDRDRR", "DRDDRR"]*/

// #include<iostream>
// #include<vector>
// using namespace std;
//     void getAns(vector<vector<int> > &maze,int i, int j, int n, string s, vector<string> &res ){
//         if(i<0 ||j<0|| i>=n||j>=n || maze[i][j] == 0){return ;}
//         if(i == n-1 && j== n-1){// Destination cell
//             res.push_back(s) ;
//             return ;
//         }
            
//         if(maze[i][j] == 1){
//                 maze[i][j]= 0;     // mark cell as visited only once

//                 getAns(maze, i+1, j, n , s+'D', res );//Explore all 4 Directions for next move
//                 getAns(maze, i, j-1, n , s+'L', res);
//                 getAns(maze, i, j+1, n , s+'R', res);
//                 getAns(maze, i-1, j, n , s+'U', res);

//                 maze[i][j]= 1; // Backtrack , Free it

//         }
//     }

//     vector<string> ratInMaze(vector<vector<int> > & maze,vector<string> &res) {
//         string s;
//         if(maze.empty() ||maze[0][0] == 0){
//             return res ;
//         }
//         getAns(maze, 0, 0, maze.size(), s, res);
//         return res ;

//     }
// int main(){
//     int n; cout<<"Enter Maze size : "; cin>> n;
    
//     vector<vector<int> > maze(n,vector<int>(n));
//     cout<<"enter elemnets : " ;
//     for(int i=0;i<n ;i++){
//         for(int j=0;j<n;j++){
//         cin>>maze[i][j] ;
//         }
//     }

//     cout<<"paths are : " ;
//     vector<string> res;
//     ratInMaze(maze, res);
//     for(int i=0;i<res.size();i++){
//         cout<< res[i]<<"  " ;
//     }
//     return 0;
// }

/*** M-2 printing solution matrix of all possible answers****/
// #include<iostream>
// #include<vector>
// using namespace std;

// void ratInMaze(vector<vector<int>> &maze , int i, int j,int n , vector<vector<int>> &sol){
    
//     if(i<0 || i>=n || j<0||j>=n || maze[i][j]== 0 ) return ;

//     if(i== n-1 && j== n-1 ) {
//         sol[i][j]=1;
//         for(auto x: sol){
//             for(auto y: x){
//                 cout<< y<<" " ;
//             }
//             cout<<endl;
//         }
//         cout<<endl ;
//         return ;
//     }

//     maze[i][j] =0 ; // Mark visited
//     sol[i][j] = 1 ;

//     if(i+1 <n)  { ratInMaze(maze, i+1, j,n, sol); }  // Down

//     if(j-1 >=0 ){ ratInMaze(maze, i, j-1,n, sol); } // Left

//     if(j+1 <n) {  ratInMaze(maze, i, j+1,n, sol); } // Right

//     if(i-1 >=0) { ratInMaze(maze, i-1, j,n, sol); } // Up
    
//     maze[i][j] = 1 ; // Backtrack
//     sol[i][j] = 0 ;

// }

// int main(){
//     int n ; cout<<"Enter n : " ; cin>>n ;

//     vector<vector<int>>maze(n,vector<int>(n)) ;
//     cout<<"Fill MAZE : " ;
//     for(int i=0;i<n ;i++){
//         for(int j=0;j<n ;j++){
//             cin>>maze[i][j];
//         }
//     }
//     vector<vector<int>> sol(n,vector<int>(n,0)) ; // sol[][]

//     cout<<"Paths for RAT to move : \n" ;
//     ratInMaze(maze, 0,0,n, sol);
//     cout<<"hello "<<" ";

//     return 0;
// }

/*** M-3 printing solution matrix all sol  using bool datatype func****/
#include<iostream>
#include<vector>
using namespace std;

bool solve(vector<vector<int>>&maze,int i,int j,int n,vector<vector<int>>&sol ){

    if(i<0 ||i>=n ||j<0 ||j>=n ||maze[i][j]==0)
        return false ;

    if(i== n-1 && j== n-1) {
        sol[i][j]=1 ;
        for(auto x:sol){
            for(auto y: x){
                cout<<y<<" " ;
            }
            cout<<endl ;
        }
        cout<<endl ;
      return false ;  // FOOL the recursion To print all possible sol,Recursion will keep asking for more sol
    }

    maze[i][j] = 0; // mark current cell visited
    sol[i][j] =1;

    if(solve(maze,i,j+1,n,sol)) // Right
        return true ;

    if(solve(maze, i+1, j, n, sol)) // Down
        return true ;
    
    if(solve(maze, i,j-1, n, sol)) //Left
        return true ;

    if(solve(maze, i-1,j,n , sol)) //Up
        return true ;

    maze[i][j]= 1;
    sol[i][j]= 0 ;
    return false ;
    
}


int main(){
    int n ;cout<<"Enter n : " ; cin>>n ;

    vector<vector<int>> maze (n, vector<int>(n)) , sol(n,vector<int>(n,0));
    for(int i=0;i<n ;i++){
        for(int j=0;j<n ;j++){
            cin>>maze[i][j];
        }
    }

    cout<<"Path for RAT IS : \n";
    solve(maze,0,0,n,sol);
    return 0;
}