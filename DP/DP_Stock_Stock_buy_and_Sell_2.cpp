#include<bits/stdc++.h>
using namespace std;

//recursion, TC=O(2^n),SC=O(n)
//buy variable tells us if we currently hold a stock or not
int helper(int ind,vector<int> &prices,bool buy){
if(ind==prices.size())
return 0;
int profit=0;
if(buy){
    profit=max((-prices[ind]+helper(ind+1,prices,false)),0+helper(ind+1,prices,true));  //we have an option to buy a stock if not already bought; or if we already have a stock, we cant buy it,depends on buy variable
}
else{
    profit=max(prices[ind]+helper(ind+1,prices,true),(0+helper(ind+1,prices,false))); //we can sell a stock if we already have a stock, or can keep it and move ahead,depends on buy variable
}
return profit;
}

int maxProfit(vector<int>& prices) {
        return helper(0,prices,true);
    }


//memoisation
int helper2(int ind,vector<int> &prices,int buy,vector<vector<int>> &dp){
if(ind==prices.size())
return 0;
int profit=0;

if(dp[ind][buy]!=-1)
return dp[ind][buy];

if(buy){
    profit=max((-prices[ind]+helper2(ind+1,prices,0,dp)),0+helper2(ind+1,prices,1,dp));  //we have an option to buy a stock if not already bought; or if we already have a stock, we cant buy it,depends on buy variable
}
else{
    profit=max(prices[ind]+helper2(ind+1,prices,1,dp),(0+helper2(ind+1,prices,0,dp))); //we can sell a stock if we already have a stock, or can keep it and move ahead,depends on buy variable
}
return dp[ind][buy]=profit;
}

int maxProfit2(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return helper2(0,prices,1,dp);
    }


//tabulation
int maxProfit3(vector<int> &prices){
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    dp[n][0]=0;
    dp[n][1]=0;
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<2;buy++){
            int profit=0;
if(buy){
    profit=max(-prices[ind]+dp[ind+1][0],0+dp[ind+1][1]);  //we have an option to buy a stock if not already bought; or if we already have a stock, we cant buy it,depends on buy variable
}
else{
    profit=max(prices[ind]+dp[ind+1][1],0+dp[ind+1][0]); //we can sell a stock if we already have a stock, or can keep it and move ahead,depends on buy variable
}
dp[ind][buy]= profit;
        }
    }
    return dp[0][1];   //recursion mein calls started from 0 till n-1, tabulation mein ulta hogaa usska
}

//tabulation mein humesha check karo ki kitne previous states ko use karke answer nikal rhe ho,uske basis pe code optimse karo
//space optimisation
int maxProfit4(vector<int> &prices){
    int n=prices.size();
    vector<int> ahead(2,0),curr(2,0);
    ahead[0]=0;
    ahead[1]=0;
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<2;buy++){
            int profit=0;
if(buy){
    profit=max(-prices[ind]+ahead[0],0+ahead[1]);  //we have an option to buy a stock if not already bought; or if we already have a stock, we cant buy it,depends on buy variable
}
else{
    profit=max(prices[ind]+ahead[1],0+ahead[0]); //we can sell a stock if we already have a stock, or can keep it and move ahead,depends on buy variable
}
curr[buy]= profit;
        }
        ahead=curr;
    }
    return ahead[1];   //recursion mein calls started from 0 till n-1, tabulation mein ulta hogaa usska
}

//single loop
int maxProfit5(vector<int> &prices){
    int aheadnotbuy,aheadbuy,currnotbuy,currbuy;
    int n=prices.size();
    aheadnotbuy=0;
    aheadbuy=0;
    for(int ind=n-1;ind>=0;ind--){
        

    currbuy=max(-prices[ind]+aheadnotbuy,0+aheadbuy);  //we have an option to buy a stock if not already bought; or if we already have a stock, we cant buy it,depends on buy variable

    currnotbuy=max(prices[ind]+aheadbuy,0+aheadnotbuy); //we can sell a stock if we already have a stock, or can keep it and move ahead,depends on buy variable
    aheadnotbuy= currnotbuy;
aheadbuy=currbuy;
}
    return aheadbuy;
}
