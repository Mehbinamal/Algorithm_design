#include<iostream>
#include <cstdint>
using namespace std;
void change_making(int D[],int m,int n){
    int F[n+1];
    int coinUsed[n+1];
    F[0]=0;
    for(int i=1;i<=n;i++){
        int temp = INT16_MAX;
        int coin = -1;
        for(int j = 0; j < m; j++){
            if(i >= D[j] && F[i - D[j]] < temp) {
                temp = F[i - D[j]];
                coin = D[j]; // Track the coin used
            }
        }
        F[i]=temp+1;
        coinUsed[i]=coin;
    }
    cout<<"Minimum number of coins: "<<F[n]<<endl;
    int amount = n;
    cout<<"Coins Used:";
    while(amount>0){
        cout<<coinUsed[amount]<<" ";
        amount -=coinUsed[amount];
    }
    cout<<endl;
}
int main(){
    cout<<"Enter Amount:";
    int n;
    cin>>n;
    cout<<"Number of Denominations:";
    int m;
    cin>>m;
    int D[m];
    cout<<"Enter Denominations:";
    for(int i=0;i<m;i++){
        cin>>D[i];
        }
    change_making(D,m,n);
    return 0;
}