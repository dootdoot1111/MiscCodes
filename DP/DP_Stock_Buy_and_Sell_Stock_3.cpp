#include <bits/stdc++.h>
using namespace std;

//memoised code
int helper(int ind,vector<int> &prices,int buy,int cap,vector<vector<vector<int>>> &dp){
    int n=prices.size();
    if(cap==0)
    return 0;
    if(ind == n)
    return 0;
    int profit=0;
    if(dp[ind][buy][cap]!=-1)
    return dp[ind][buy][cap];
    if(buy){
        profit=max(-prices[ind]+helper(ind+1,prices,0,cap,dp),0+helper(ind+1,prices,1,cap,dp));
    }
    else{
        profit=max(prices[ind]+helper(ind+1,prices,1,cap-1,dp),0+helper(ind+1,prices,0,cap,dp));
    }
    return dp[ind][buy][cap]=profit;

}

int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return helper(0,prices,1,2,dp);
    }


//tabulation
int maxProfit(vector<int> &prices){
    int n=prices.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    //base case 1
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            dp[i][j][0]=0;
        }
    }

    //base case 2
    for(int j=0;j<2;j++){
        for(int k=0;k<3;k++){
            dp[n][j][k]=0;
        }
    }

    int profit=0;
    for(int ind=n-1;ind>=0;ind--){                      //tabulation mein ulta chalta hai
        for(int buy=0;buy<2;buy++){
            for(int cap=1;cap<3;cap++){
                    if(buy){
                        profit=max(-prices[ind]+dp[ind+1][0][cap],0+dp[ind+1][1][cap]);
                    }
                    else{
                        profit=max(prices[ind]+dp[ind+1][1][cap-1],0+dp[ind+1][0][cap]);
                    }
                
             dp[ind][buy][cap]=profit;
            }
        }
    }
    return dp[0][1][2];
}