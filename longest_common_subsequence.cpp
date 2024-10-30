#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
void longestCommonSubsequence(string X,string Y){
    int n = X.length()+1;
    int m = Y.length()+1;
    vector<vector<int>> C(n,vector<int>(m,0));
    vector<vector<int>> B(n,vector<int>(m,0));

    
    for(int i = 0;i<n;i++){
        C[0][i] = 0;
        B[0][i] = 0;
    }

    for(int i = 0;i<m;i++){
        C[i][0] = 0;
        B[i][0] = 0;
    }
    /* 1=Up
       2=Diagonally Up
       3= Left*/

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(X[i-1]==Y[j-1]){
                C[i][j] = C[i-1][j-1] + 1;
                B[i][j] = 2;

            }
            else if (C[i-1][j]>=C[i][j-1])
            {
                C[i][j] = C[i-1][j];
                B[i][j] = 1;
            }
            else{
                C[i][j] = C[i][j-1];
                B[i][j] = 3;
            }
            
        }
    }
    cout<<"Length of LCS is "<<C[n-1][m-1]<<endl;
    int i=n-1;
    int j=m-1;
    string s;
    while(i!=0 && j!=0){
        if(B[i][j] == 2){
            s+=X[i-1];
            i = i-1;
            j = j-1;
        }
        else if (B[i][j] == 1)
        {
            i = i-1;
        }
        else{
            j = j-1;
        }
    }
    reverse(s.begin(),s.end());
    cout<<"Sub String = "<<s;
    
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