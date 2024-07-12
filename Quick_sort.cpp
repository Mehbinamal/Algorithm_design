#include<iostream>
using namespace std;
int Partition(int A[],int LB,int UB){
    int pivot = A[UB];
    int j = LB - 1;
    for(int i = LB;i<UB-1;i++){
        if(A[i]<=pivot){
            j++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = A[i];
        }
        int temp = A[UB];
            A[UB] = A[j+1];
            A[j+1] = A[UB];
    }
    return j+1;

}
void Quick_sort(int A[],int LB,int UB){
   int pivot = Partition(A,LB,UB);
   Quick_sort(A,pivot+1,UB);
   Quick_sort(A,LB,pivot-1);
}

int main(){
    int n;
    cout<<"Enter Number of Elements :";
    cin>>n;
    int A[n];
    cout<<"Enter Elements :";
    for(int i=0;i<n;i++)
        cin>>A[i];
    Quick_sort(A,0,n);
    for (int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}