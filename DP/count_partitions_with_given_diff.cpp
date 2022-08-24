#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
int countsubsetSumToK(int n,int k,vector<int> &arr){
    vector<vector<int>> dp(n,vector<int>(k+1,false)); 

    //base case updated such that it can handle inputs with 0
   if(arr[0]==0)
   dp[0][0]=2;
   else
   dp[0][0]=1;

   if(arr[0]!=0 && arr[0]<=k)
   dp[0][arr[0]]=1;              


    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            int notTake=dp[ind-1][target];

            int take=0;
            if(target>=arr[ind])
            take=dp[ind-1][target-arr[ind]];

            dp[ind][target]=(take+notTake)%mod;
        }
    }
    return dp[n-1][k];
}

//s1-s2=d; totalsum-2*s2=d; s2=(totalsum-d)/2; toh arr bhej ke check karlo kitne subarrays ka sum s2 hoga and return that
int countPartition(vector<int> &arr,int k){
    int totalsum=0;
    for(int i=0;i<arr.size();i++){
        totalsum+=arr[i];
    }
    if(totalsum-k<0 || (totalsum-k)%2!=0 )
    return false;

    return countsubsetSumToK(arr.size(),(totalsum-k)/2,arr);
}