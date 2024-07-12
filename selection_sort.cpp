#include<iostream>
using namespace std;
void selection_sort(int A[],int n){
    
    for(int i=0;i<n;i++){
        int min = i;
        for(int j = i;j<n;j++){
            if(A[min] > A[j]){
                min = j;
            }
        }
        if (min!=i){
            int temp=A[i];
            A[i]=A[min];
            A[min]=temp;
        }
    }
}
int main(){
    int n;
    cout<<"Enter Number of Elements :";
    cin>>n;
    int A[n];
    cout<<"Enter Elements :";
    for(int i=0;i<n;i++)
        cin>>A[i];
    selection_sort(A,n);
    for (int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}