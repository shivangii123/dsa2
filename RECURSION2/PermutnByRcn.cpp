#include<iostream>
#include<vector>
using namespace std ;

void permt(string  str, int i,int n, vector<string>&res){
    if(i==n){                //When we make a arrangmnt , push to result
        res.push_back(str);
        return ;            //backtrack to create new possibility
    }

    for(int j=i;j<n;j++){
        swap(str[i], str[j]); //TAKE ONE CHOICE
        permt(str, i+1, n,res); // Explore through Recursion
        swap(str[j], str[i]);  // UNDO
    }
}

int main(){

    cout<<"Enter string : ";
    string str ; cin>> str;

    int n= str.size();
    vector<string> res;

    cout<<"All Possible Permutations are : ";

    permt(str,0,n,res);
    // cout<<"All Possible Permutations are : ";

    for(auto x:res){
        cout<<x<<" ";
    }

    return 0;
}