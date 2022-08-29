#include<bits/stdc++.h>
using namespace std;

//memoisation, and the partition trick only works if the cuts array is sorted
int f(int i, int j, vector<int> &cuts,vector<vector<int>> &dp){
        if(i>j)
        return 0;
         if(dp[i][j]!=-1)
             return dp[i][j];
        int mini=1e9;
        for(int ind=i;ind<=j;ind++){
            int tempcost=cuts[j+1]-cuts[i-1]+f(ind+1,j,cuts,dp)+f(i,ind-1,cuts,dp);
            mini=min(tempcost,mini);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        vector<vector<int>> dp(c+1,vector<int>(c+1,-1));   
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        return f(1,c,cuts,dp);
    }


//tabulation
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        vector<vector<int>> dp(c+2,vector<int>(c+2,0));   
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
       for(int i=c;i>=1;i--){
        for(int j=1;j<=c;j++){
            if(i>j)
                continue;               //base case ko issme hi incorporate kiya hai
            int mini=1e9;
            for(int ind=i;ind<=j;ind++){
            int tempcost=cuts[j+1]-cuts[i-1]+dp[ind+1][j]+dp[i][ind-1];
            mini=min(tempcost,mini);
        }
         dp[i][j]=mini;
        }
       }
       return dp[1][c];
    }