#include<bits/stdc++.h>
using namespace std;

//recursion
int unbound_knapsack(int ind,vector<int> &wt,vector<int> &val,int W){
    if(ind==0){
        return (W/wt[0])*val[0];
    }
    int nottake= 0 + unbound_knapsack(ind-1,wt,val,W);
    int take=INT_MIN;
    if(W>=wt[ind]){
        take=val[ind]+unbound_knapsack(ind,wt,val,W-wt[ind]);
    }
    return max(take,nottake);

}

//memoisation
int unbound_knapsack2(int ind,vector<int> &wt,vector<int> &val,int W,vector<vector<int>> &dp){
    if(ind==0){
        return (W/wt[0])*val[0];
    }
    if(dp[ind][W]!=-1)return dp[ind][W];
    int nottake= 0 + unbound_knapsack2(ind-1,wt,val,W,dp);
    int take=INT_MIN;
    if(W>=wt[ind]){
        take=val[ind]+unbound_knapsack2(ind,wt,val,W-wt[ind],dp);
    }
    return dp[ind][W]=max(take,nottake);

}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
   vector<vector<int>> dp(n,vector<int> (w+1,-1));
    return unbound_knapsack2(n-1,weight,profit,w,dp);
}


//tabulation
int unbound_knapsack3(int n, int w, vector<int> &profit, vector<int> &weight){
     vector<vector<int>> dp(n,vector<int> (w+1,0));
    for(int W=0;W<=w;W++){
        dp[0][W]=(int) W/weight[0]*profit[0];
    }
    for(int ind=1;ind<n;ind++){
        for(int W=0;W<=w;W++){
            int nottake= 0 + dp[ind-1][W];
    int take=INT_MIN;
    if(W>=weight[ind]){
        take=profit[ind]+dp[ind][W-weight[ind]];
    }
   dp[ind][W]= max(take,nottake);
        }
    }
    return dp[n-1][w];
}

//space optimised 1d array 