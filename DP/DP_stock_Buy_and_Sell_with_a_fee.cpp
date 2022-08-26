#include <bits/stdc++.h>
using namespace std;

//jitne baar trancsanction complete hoga utne baar fees deduct hoga,toh either subtract it while selling/buying the stock,apne aap handle ho jaayega
int maximumProfit(int n, int fee, vector<int> &prices) { 
        int aheadnotbuy,aheadbuy,currnotbuy,currbuy;
    aheadnotbuy=0;
    aheadbuy=0;
    for(int ind=n-1;ind>=0;ind--){
        

    currbuy=max(-prices[ind]+aheadnotbuy,0+aheadbuy);  //we have an option to buy a stock if not already bought; or if we already have a stock, we cant buy it,depends on buy variable

    currnotbuy=max(prices[ind]-fee+aheadbuy,0+aheadnotbuy); //we can sell a stock if we already have a stock, or can keep it and move ahead,depends on buy variable
    aheadnotbuy= currnotbuy;
aheadbuy=currbuy;
}
   return aheadbuy;
}
