#include <bits/stdc++.h>
using namespace std;

int f(int ind,int prev_ind,vector<int> inp,int n,vector<vector<int>> &dp){
if(ind==0)return 0;
if(dp[ind][prev_ind]!=-1)
return dp[ind][prev_ind];
int len=0+f(ind+1,prev_ind,inp,n,dp);
if(prev_ind==-1 || inp[ind]>inp[prev_ind]){
    len= max(len,1+f(ind+1,ind,inp,n,dp));
}
return dp[ind][prev_ind+1] = len;
}

int longestIncreasingSusequence(vector<int> input){
    int n=input.size();
    vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
}