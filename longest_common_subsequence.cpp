#include<iostream>
#include<vector>
using namespace std;
void longestCommonSubsequence(string X,string Y){
    int n = X.length()+1;
    int m = Y.length()+1;
    vector<vector<int>> C(n,vector<int>(m,0));
    for(int i = 0;i<n;i++){
        C[0][i] = 0;
    }

    for(int i = 0;i<m;i++){
        C[i][0] = 0;
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(X[i-1]==Y[j-1]){
                C[i][j] = C[i-1][j-1] + 1;
            }
            else if (C[i-1][j]>=C[i][j-1])
            {
                C[i][j] = C[i-1][j];
            }
            else{
                C[i][j] = C[i][j-1];
            }
            
        }
    }
    cout<<"Length of LCS is "<<C[n-1][m-1]<<endl;
}

int main(){
    string x,y;
    cout<<"Enter the first string: ";
    cin>>x;
    cout<<"Enter the Second string: ";
    cin>>y;
    longestCommonSubsequence(x,y);
    return 0;
}