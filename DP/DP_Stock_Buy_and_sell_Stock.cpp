#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &input){
    int n=input.size();
    int profit=0;
    int mini=input[0];
    int tprofit=0;
    for(int i=1;i<n;i++){
        tprofit=input[i]-mini;
        profit=max(profit,tprofit);
        mini=min(mini,input[i]);
    }
    return profit;
}