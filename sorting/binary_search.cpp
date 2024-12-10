#include <iostream>
using namespace std;

int binary_search(int A[],int n,int key){
    int LB=0;
    int UB=n-1;
    while(LB<=UB){
        int mid=(LB+UB)/2;
        if(A[mid]==key){
            return mid;
        }
        else if(A[mid]<key){
            LB=mid+1;
        }
        else{
            UB=mid-1;
        }
    }
    return -1;

}

int main(){
    int n;
    cout<<"Enter Number of Elements :";
    cin>>n;
    int A[n];
    cout<<"Enter Elements :";
    for(int i=0;i<n;i++)
        cin>>A[i];
    int key;
    cout<<"Enter Key :";
    cin>>key;
    int index = binary_search(A,n,key);
    (index == -1) ? cout<<"Element is not Present in Array"<<endl : cout<<"Element is present at index : "<<index<<endl;
    return 0;
}