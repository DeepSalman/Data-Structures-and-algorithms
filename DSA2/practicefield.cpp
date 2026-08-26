#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;



int main(){
    int coins[]= {1,2,5,10,20,50,100,200,500,1000};
    int n = sizeof(coins)/sizeof(coins[0]);

    int TargetAmount = 1260;
    int coinCount = 0;

    sort(coins,coins+n,greater<int>());

    cout<<"Coins Selected: ";
    for(int i=0;i<n;i++){
        while(TargetAmount>=coins[i]){
            cout<<coins[i]<<" ";
            TargetAmount-=coins[i];
            coinCount++;
        }
    }

    cout<<endl;
    cout<<"Total Coins: "<<coinCount<<endl;

    return 0;

}