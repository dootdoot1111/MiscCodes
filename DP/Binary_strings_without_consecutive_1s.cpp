#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;    
int solve(int prev,int n,vector<vector<int>> &dp)
    {
       if(n==0) return 0;
       if(n==1)
       {
           if(prev==0)
           return 2;
           if(prev==1)
           return 1;
       }
       if(dp[n][prev]!=-1)
           return dp[n][prev];
       if(prev==0)
       return dp[n][prev]=(solve(0,n-1,dp)+solve(1,n-1,dp))%mod;
       if(prev==1)
       return dp[n][prev]=solve(0,n-1,dp)%mod;
    }
int numberOfBinaryStrings(int n) {
    // Write your code here.
    vector<vector<int>> dp(n+1,vector<int> (2,-1));
  return solve(0,n,dp);
    
}

//tabulation
int numberOfBinaryStrings2(int n) {
    // Write your code here.
    vector<vector<int>> dp(n+1,vector<int> (2,0));
    dp[1][0]=2;
    dp[1][1]=1;

    for(int i=2;i<=n;i++){
        for(int prev=0;prev<2;prev++){
            if(prev==0)
             dp[i][prev]=(dp[i-1][0]+dp[i-1][1])%mod;
            if(prev==1)
            dp[i][prev]=dp[i-1][0]%mod;
        }
    }
    return dp[n][0];
    
}