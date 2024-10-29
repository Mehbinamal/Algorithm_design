#include<iostream>
#include<vector>
using namespace std;
void knapsack(int v[],int w[],int n,int capacity){
    vector<vector<int>> F(n+1,vector<int>(capacity+1,0));
    F[0][0] = 0;
    for (int i = 1; i < n+1; i++) {
        F[i][0] = 0; // First column
    }
    for (int j = 1; j < capacity+1; j++) {
        F[0][j] = 0; // First row
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<capacity+1;j++){
            if(j-w[i]>= 0){
                F[i][j] = max(F[i-1][j],v[i] + F[i-1][j-w[i]]);
            }
            else{
                F[i][j] = F[i-1][j];
            }
        }
    }

    cout<<"Maximum value = "<<F[n][capacity];
}
int main(){
    int n;
    cout<<"Enter no of items :";
    cin>>n;
    int v[n],w[n];
    for(int i=1;i<=n;i++){
        cout<<"Enter valur of "<<i<<" item :";
        cin>>v[i];
        cout<<"Enter weight of "<<i<<" item :";
        cin>>w[i];
    }
    int capacity;
    cout<<"Enter capacity of knapsack :";
    cin>>capacity;
    knapsack(v,w,n,capacity);
    return 0;
}
