#include<bits/stdc++.h>
using namespace std;

//two subsets must have same sum, that means sum of each subset must be equals to the total sum of the array/2,so this problem becomes same as subset sum equals k
bool subsetSumToK(int n,int k,vector<int> &arr){
    vector<vector<bool>> dp(n,vector<bool>(k+1,false)); 

    for(int i=0;i<n;i++){
        dp[i][0]=true;              //kabhi target 0 ho rha toh return true
    }
    dp[0][arr[0]]=true;  //base case number 2, agar last element tak aagya and last element equals to target to store true

    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool notTake=dp[ind-1][target];

            bool take=false;
            if(target>=arr[ind])
            take=dp[ind-1][target-arr[ind]];

            dp[ind][target]=take||notTake;
        }
    }
    return dp[n-1][k];
}

bool canPartition(vector<int> &arr,int n){
    int totsum=0;
    for(int i=0;i<arr[i];i++) totsum+=arr[i];
    if(totsum%2!=0) return false;
    return subsetSumToK(arr.size(),totsum/2,arr);
}