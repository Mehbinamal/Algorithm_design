#include<iostream>
using namespace std;
void Fibinocci(int n){
    int F[n-1];
    F[0]=0;
    F[1]=1;
    for(int i=2;i<n;i++){
        F[i]=F[i-1]+F[i-2];
    }
    cout<<F[n-1]<<endl;
}
int main(){
    int n;
    cout<<"Enter the number of terms in the sequence: ";
    cin>>n;
    Fibinocci(n);
    return 0;
}
