#include<bits/stdc++.h>
using namespace std;

//how to convert it into a n colured house?
int helper(int i,int j,vector<vector<int>>& cost,int n,vector<vector<int>>&dp){
    if(i>n-1)
    return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];
    if(j==3){
    int x3= min( cost[i][0]+helper(i+1,0,cost,n,dp),min(cost[i][1]+helper(i+1,1,cost,n,dp),cost[i][2]+helper(i+1,2,cost,n,dp)));
    return dp[i][j]=x3;
}
    if(j==2){
        int x2= min( cost[i][0]+helper(i+1,0,cost,n,dp),cost[i][1]+helper(i+1,1,cost,n,dp));
    return dp[i][j]=x2;
    }
    if(j==1){
        int x1= min( cost[i][0]+helper(i+1,0,cost,n,dp),cost[i][2]+helper(i+1,2,cost,n,dp));
    return dp[i][j]=x1;
    }
    if(j==0){
        int x0=min( cost[i][1]+helper(i+1,1,cost,n,dp),cost[i][2]+helper(i+1,2,cost,n,dp));
    return dp[i][j]=x0;
    }
}

//generic for n houses code
int helper2(int i,int j,vector<vector<int>>& cost,int n,vector<vector<int>>&dp){
    if(i>n-1)
    return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];
    int x=INT_MAX;
    for(int ind=0;ind<=2;ind++){
        if(ind==j)
        continue;
        else{
            int temp=cost[i][ind]+helper2(i+1,ind,cost,n,dp);
            x=min(x,temp);
        }
    }
    return x;
}

   

int minCost(vector<vector<int>> &cost)
{    int n=cost.size();
     vector<vector<int>> dp(n,vector<int>(4,-1));
    return helper(0,3,cost,n,dp);
}