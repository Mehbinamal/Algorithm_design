#include <iostream>
#include <vector>
using namespace std;
void coin_collecting(vector<vector<int>> C,int n,int m){
    int n = n+1;
    int m = m+1;
    vector<vector<int>> F;
    for(int i=0;i<m;i++){
        F[0][i] = 0;
    }
    for(int i=0;i<n;i++){
        F[i][0] = 0; 
    }
    F[1,1] = C[1,1];
    for(int i=2;i<m;i++){
        F[1,i] = F[1,i-1] + C[1,i];
    }

}