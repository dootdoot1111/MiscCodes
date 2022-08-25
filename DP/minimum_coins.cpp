#include <bits/stdc++.h>
using namespace std;

//greedy fails because the coin values may not be uniform

//recursion mein TC>O(2^n){ek coin ko pick karne ka multiple ways hai} and SC>O(n), if only coin of 1 denomination is present SC=O(target)
int minCoin(int ind,vector<int> &coins,int t){
    if(ind==0){
        if(t%coins[0]==0)  return t/coins[0];
        else
        return 1e9;
    }
    int nottake=minCoin(ind-1,coins,t);
    int take=INT_MAX;
    if(t>=coins[ind]){
        take=1+minCoin(ind,coins,t-coins[ind]);
    }
    return min(take,nottake);
}

//memoisation
//Tc=O(n*t) && SC=O(n*t)
int minCoin2(int ind,vector<int> &coins,int t,vector<vector<int>> &dp){
    if(ind==0){
        if(t%coins[0]==0)  return t/coins[0];
        else
        return 1e9;
    }
    if(dp[ind][t]!=-1) return dp[ind][t];
    int nottake=minCoin2(ind-1,coins,t,dp);
    int take=INT_MAX;
    if(t>=coins[ind]){
        take=1+minCoin2(ind,coins,t-coins[ind],dp);
    }
    return dp[ind][t]=min(take,nottake);
}

int minimumElements(vector<int> &coins, int t)
{
    // Write your code here.
    vector<vector<int>> dp(coins.size(),vector<int>(t+1,-1));
   int ans= minCoin2(coins.size()-1,coins,t,dp);
    if(ans>=1e9)
        return -1;
    else
        return ans;
}



//tabulation 
int minimumElements(vector<int> &coins, int target)
{
   vector<vector<int>> dp(coins.size(),vector<int> (target+1,0));
for(int t=0;t<=target;t++){
    if(t%coins[0]==0)
    dp[0][t]=t/coins[0];                //base case convert
    else
     dp[0][t]=1e9;
}
for(int ind=1;ind<coins.size();ind++){
    for(int t=0;t<=target;t++){
        int nottake=0+dp[ind-1][t];               
    int take=INT_MAX;
    if(t>=coins[ind]){
        take=1+dp[ind][t-coins[ind]];
    }
    dp[ind][t] =min(take,nottake);
    }   
}    
   int ans= dp[coins.size()-1][target];
    if(ans>=1e9)
        return -1;
    else
        return ans;
}


//space optimised,using only two rows
int minimumElements(vector<int>& arr, int T){
    
    int n= arr.size();
    
    vector<int> prev(T+1,0), cur(T+1,0);
    
    for(int i=0; i<=T; i++){
        if(i%arr[0] == 0)  
            prev[i] = i/arr[0];
        else prev[i] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + prev[target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + cur[target - arr[ind]];
                
             cur[target] = min(notTake, take);
        }
        prev = cur;
    }
    
    int ans = prev[T];
    if(ans >=1e9) return -1;
    return ans;
}
