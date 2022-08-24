#include <bits/stdc++.h>
using namespace std;


//straight forward recursion based
int helper(int ind,int W,vector<int> &wt,vector<int> &val){
        int n=wt.size();
        if(ind==0){
            if(wt[0]<=W) return val[0];
            return 0;
        }
        int notpick=0+helper(n-1,W,wt,val);
        int pick=INT_MIN;
        if(W>=wt[ind]){
            pick=val[ind]+helper(n-1,W-wt[ind],wt,val);
        }
        return max(pick,notpick);
}

int knapsack(vector<int> &wt,vector<int> &val,int maxWeight,int n){
    return helper(wt.size()-1,maxWeight,wt,val);
}

//memoisation 
int helper2(int ind,int W,vector<int> &wt,vector<int> &val,vector<vector<int>> &dp){
        int n=wt.size();
        if(ind==0){
            if(wt[0]<=W) return val[0];
            return 0;
        }
        if(dp[ind][W]!=-1) return dp[ind][W];
        int notpick=0+helper2(n-1,W,wt,val,dp);
        int pick=INT_MIN;
        if(W>=wt[ind]){
            pick=val[ind]+helper2(n-1,W-wt[ind],wt,val,dp);
        }
        return dp[ind][W]=max(pick,notpick);
}

int knapsack2(vector<int> &wt,vector<int> &val,int maxWeight,int n){
    vector<vector<int>> dp(wt.size(),vector<int>(maxWeight+1,-1));
    return helper2(wt.size()-1,maxWeight,wt,val,dp);
}

//tabulation 
int knapsack3(vector<int> &wt,vector<int> &val,int maxWeight,int n){
    vector<vector<int>> dp(wt.size(),vector<int>(maxWeight+1,-1));
    for(int W=wt[0];W<maxWeight;W++){                       //base case imp
        dp[0][W]=val[0];
    }
    for(int ind=1;ind<wt.size();ind++){ 
        for(int W=0;W<maxWeight;W++){
            int notpick=dp[n-1][W];
        int pick=INT_MIN;
        if(W>=wt[ind]){
            pick=val[ind]+dp[n-1][W-wt[ind]];
        }
        dp[ind][W]= max(pick,notpick);
        }
    }
    return dp[wt.size()-1][maxWeight];

}

//space optimisation from a matrix to a 2d vectors,using prev and curr
int knapsack4(vector<int> &wt,vector<int> &val,int maxWeight,int n){
    vector<int> prev(maxWeight+1,0),curr(maxWeight+1,0);
    for(int W=wt[0];W<maxWeight;W++){                       //base case imp
        prev[W]=val[0];
    }
    for(int ind=1;ind<wt.size();ind++){ 
        for(int W=0;W<maxWeight;W++){
            int notpick=prev[W];
        int pick=INT_MIN;
        if(W>=wt[ind]){
            pick=val[ind]+prev[W-wt[ind]];
        }
        curr[W]= max(pick,notpick);
        }
        prev=curr;
    }
    return prev[maxWeight];

}

//space optimisation using a single array, which we keep filling from right to left, as the elements which get filled depend upon its left elements,therefore only right to left possible not left to right
int knapsack5(vector<int> &wt,vector<int> &val,int maxWeight,int n){
    vector<int> prev(maxWeight+1,0);
    for(int W=wt[0];W<maxWeight;W++){                       //base case imp
        prev[W]=val[0];
    }
    for(int ind=1;ind<wt.size();ind++){ 
        for(int W=0;W<maxWeight;W++){
            int notpick=prev[W];
        int pick=INT_MIN;
        if(W>=wt[ind]){
            pick=val[ind]+prev[W-wt[ind]];
        }
        prev[W]= max(pick,notpick);
        }
    }
    return prev[maxWeight];

}
