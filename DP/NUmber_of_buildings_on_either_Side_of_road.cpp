	#include <bits/stdc++.h>
    using namespace std;
    
    int mod=1000000007;
	
	int helper(int ind,int next,vector<vector<int>> &dp){
	    if(ind==0)
	    return 0;
	    
	    if(ind == 1){
	        if(next == 0)
	        return 2;
	        if(next == 1)
	        return 1;
	    }
	    if(dp[ind][next]!=-1)
	    return dp[ind][next];
	    
	    if(next==1)
	    return dp[ind][next]=helper(ind-1,0,dp)%mod;
	    if(next==0)
	    return dp[ind][next]=(helper(ind-1,1,dp)%mod+helper(ind-1,0,dp)%mod)%mod;
	    
	    
	}
	int TotalWays(int N)
	{
	    // Code here
	    vector<vector<int>> dp(N+1,vector<int>(2,-1));
	    long ans=helper(N,0,dp);
	    return (int)(ans%mod*ans%mod)%mod;
	}