#include <bits/stdc++.h>
using namespace std;
//recursion
long helper(int ind,int* input,int value){
    if(ind==0){
        if(value%input[0]==0)
            return 1;
        else
            return 0;
    }
    long nottake=helper(ind-1,input,value);
    long take=0;
    if(value>=input[ind]){
        take=helper(ind,input,value-input[ind]);
    }
    
    return take+nottake;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    return helper(n-1,denominations,value);
    
}

//memoisation
long helper2(int ind,int* input,int value,vector<vector<long>> &dp){
    if(ind==0){
        if(value%input[0]==0)
            return 1;
        else
            return 0;
    }
    if(dp[ind][value]!=-1)
        return dp[ind][value];
    long nottake=helper2(ind-1,input,value,dp);
    long take=0;
    if(value>=input[ind]){
        take=helper2(ind,input,value-input[ind],dp);
    }
    
    return dp[ind][value]=take+nottake;
}
long countWaysToMakeChange2(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<long>> dp(n,vector<long> (value+1,-1));
    return helper2(n-1,denominations,value,dp);
    
}


//tabulation
int minimumElements(vector<int>& arr, int T){
    
    int n= arr.size();
    
    vector<vector<int>> dp(n,vector<int>(T+1,0));
    
    for(int i=0; i<=T; i++){
        if(i%arr[0] == 0)  
            dp[0][i] = i/arr[0];
        else dp[0][i] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + dp[ind-1][target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + dp[ind][target - arr[ind]];
                
             dp[ind][target] = min(notTake, take);
        }
    }
    
    int ans = dp[n-1][T];
    if(ans >=1e9) return -1;
    return ans;
}