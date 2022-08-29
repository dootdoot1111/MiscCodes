#include <bits/stdc++.h>
using namespace std;

int helper(int ind,int prev,vector<int> &bill,vector<int> &revenue,int x,int n){
    if(ind>n-1)
        return 0;
    int ans=0;
    int notpick=0+helper(ind+1,prev,bill,revenue,x,n);
    int pick=-1e9;
    if(bill[ind]-bill[prev]>x || prev==-1){
        pick=revenue[ind]+helper(ind+1,ind,bill,revenue,x,n);
    }
    ans=max(pick,notpick);
    return ans;
}
int highwayBillboard(vector<int> &billboards, vector<int> &revenue, int m, int x){
    int n=billboards.size();
    return helper(0,-1,billboards,revenue,x,n);
}

//increased the size of the dp array by 1, kyonki prev ko -1 ka access nahi tha na issilye
int helper(int ind,int prev,vector<int> &bill,vector<int> &revenue,int x,int n,vector<vector<int>> &dp){
    if(ind>n-1)
        return 0;
    if(dp[ind][prev+1]!=-1)
        return dp[ind][prev+1];
    int ans=0;
    int notpick=0+helper(ind+1,prev,bill,revenue,x,n,dp);
    int pick=-1e9;
    if(bill[ind]-bill[prev]>x || prev==-1){
        pick=revenue[ind]+helper(ind+1,ind,bill,revenue,x,n,dp);
    }
    ans=max(pick,notpick);
    return dp[ind][prev+1]=ans;
}
int highwayBillboard(vector<int> &billboards, vector<int> &revenue, int m, int x){ 
    int n=billboards.size();
    vector<vector<int>> dp(n,vector<int> (n+1,-1));
    return helper(0,-1,billboards,revenue,x,n,dp);
}