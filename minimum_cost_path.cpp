#include<iostream>
#include<vector>
using namespace std;
void minimum_cost_path(vector<vector<int>> matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> minMatrix(n,vector<int>(m,0));

    minMatrix[0][0] = matrix[0][0];

    for(int i=1;i<n;i++){
        minMatrix[0][i]= minMatrix[0][i-1] + matrix[0][i];
    }

    for(int i=1;i<m;i++){
        minMatrix[i][0] = minMatrix[i-1][0] + matrix[i][0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            minMatrix[i][j] = min(min(minMatrix[i-1][j], minMatrix[i][j-1]),minMatrix[i-1][j-1]) + matrix[i][j];
        }
    }

    cout<<"Minimum Cost Path = "<<minMatrix[n-1][m-1];
}

int main(){
    vector<vector<int>> matrix = {
        {5,3,4,1},
        {4,2,2,4},
        {2,1,5,1},
        {2,1,2,1}
    };
    minimum_cost_path(matrix);
    return 0;
}