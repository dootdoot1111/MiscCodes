#include<bits/stdc++.h>
using namespace std;

//recursive
int helper(int ind,vector<int> &price,vector<int> &wt,int W){
if(ind==0){
    return (int)(W/wt[0])*price[0];
}

int notpick=0+helper(ind-1,price,wt,W);
int pick=INT_MIN;
if(W>=wt[ind]){
    pick=price[ind]+helper(ind,price,wt,W-wt[ind]);
}
return max(pick,notpick);
}

int cutRod(vector<int> &price, int n)
{
	 vector<int> wt(n,0);

    for(int i=0;i<n;i++){
        wt[i]=i+1;
    }
    vector<vector<int>> dp(price.size(),vector<int>(n+1,-1));
    return helper(n-1,price,wt,n);
}
//memoised solution
int helper2(int ind,vector<int> &price,vector<int> &wt,int W,vector<vector<int>> &dp){
if(ind==0){
    return (int)(W/wt[0])*price[0];
}
if(dp[ind][W]!=-1)
    return dp[ind][W];
int notpick=0+helper2(ind-1,price,wt,W,dp);
int pick=INT_MIN;
if(W>=wt[ind]){
    pick=price[ind]+helper2(ind,price,wt,W-wt[ind],dp);
}
return dp[ind][W]=max(pick,notpick);
}

int cutRod2(vector<int> &price, int n)
{
	 vector<int> wt(n,0);

    for(int i=0;i<n;i++){
        wt[i]=i+1;
    }
    vector<vector<int>> dp(price.size(),vector<int>(n+1,-1));
    return helper2(n-1,price,wt,n,dp);
}


//tabulation
int cutRod3(vector<int> &price, int n){
     vector<int> wt(n,0);

    for(int i=0;i<n;i++){
        wt[i]=i+1;
    }

    vector<vector<int>> dp(price.size(),vector<int>(n+1,-1));
    for(int W=0;W<=n;W++){
        dp[0][W]=(int)(W/wt[0])*price[0];
    }
    for(int ind=1;ind<n;ind++){
        for(int W=0;W<=n;W++){
            int notpick=0+dp[ind-1][W];
            int pick=INT_MIN;
            if(W>=wt[ind]){
            pick=price[ind]+dp[ind][W-wt[ind]];
                }
            dp[ind][W]= max(pick,notpick);
        }
    }
    return dp[price.size()-1][n];
}

//space optimised 1d array 