#include <bits/stdc++.h>
using namespace std;

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
    profit=max(prices[ind]+helper2(ind+2,prices,1,dp),(0+helper2(ind+1,prices,0,dp))); //we can sell a stock if we already have a stock, or can keep it and move ahead,depends on buy variable
}
return dp[ind][buy]=profit;
}

int maxProfit2(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return helper2(0,prices,1,dp);
    }


//tabulation, size n+2 karna pada table ka taaki ind+2 out of bounds na chalajaye last call pe
int maxProfit3(vector<int>& prices) {
        int n=prices.size();
    vector<vector<int>> dp(n+2,vector<int>(2,0));//size n+2 kara taaki last call pe index+2 invalid jagan na jaye
    dp[n][0]=0;
    dp[n][1]=0;
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<2;buy++){
            int profit=0;
if(buy){
    profit=max(-prices[ind]+dp[ind+1][0],0+dp[ind+1][1]);  //we have an option to buy a stock if not already bought; or if we already have a stock, we cant buy it,depends on buy variable
}
else{
    profit=max(prices[ind]+dp[ind+2][1],0+dp[ind+1][0]); //we can sell a stock if we already have a stock, or can keep it and move ahead,depends on buy variable
}
dp[ind][buy]= profit;
        }
    }
    return dp[0][1];
    }
