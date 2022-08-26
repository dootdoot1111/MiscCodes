#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices,int k){
    int n=prices.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
    //base case 1
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            dp[i][j][0]=0;
        }
    }

    //base case 2
    for(int j=0;j<2;j++){
        for(int x=0;x<k+1;x++){
            dp[n][j][x]=0;
        }
    }

    int profit=0;
    for(int ind=n-1;ind>=0;ind--){                      //tabulation mein ulta chalta hai
        for(int buy=0;buy<2;buy++){
            for(int cap=1;cap<k+1;cap++){
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
    return dp[0][1][k];
}