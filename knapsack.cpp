#include<iostream>
#include<vector>
using namespace std;
void knapsack(int v[],int w[],int n,int capacity){
    vector<vector<int>> F(n+1,vector<int>(capacity+1,0));
    vector<vector<int>> B(n+1,vector<int>(capacity+1,0));
    F[0][0] = 0;
    B[0][0] = 0;

    for (int i = 1; i < n+1; i++) {
        F[i][0] = 0; // First column
        B[i][0] = 0;
    }
    for (int j = 1; j < capacity+1; j++) {
        F[0][j] = 0; // First row
        B[0][j] = 0;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<capacity+1;j++){
            if(j-w[i]>= 0){
                if(F[i-1][j] > v[i] + F[i-1][j-w[i]]){
                    F[i][j] = F[i-1][j];
                    B[i][j] = 0;
                }else{
                    F[i][j] = v[i] + F[i-1][j-w[i]];
                    B[i][j] = 1;
                }
            }
            else{
                F[i][j] = F[i-1][j];
            }
        }
    }
    cout<<"Maximum value = "<<F[n][capacity]<<endl;
    int i=n;
    int j=capacity;
    int selected[n];
    int k=0;
    while(i!=0 && j!=0){
        if(B[i][j] == 1){
            selected[k++] = i;
            i = i-1;
            j = j- w[i];
        }
        else{
            i= i-1;
        }
    }
    
    while(k>=0){
        cout<<selected[k--]<<" ";
    }
}
int main(){
    int n;
    cout<<"Enter no of items :";
    cin>>n;
    int v[n],w[n];
    for(int i=1;i<=n;i++){
        cout<<"Enter value of "<<i<<" item :";
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
