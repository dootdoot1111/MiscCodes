#include<bits/stdc++.h>
using namespace std;

//only positive numbers in the input; dp last row will check if a particular sum is possible using the numbers 
//last row of dp pe check kara ki kaun kaun se sum values possible hai, then accordingly s2 ka sum dhundha and phir min nikala
int subsetSumToK(int n,int k,vector<int> &arr){
    vector<vector<bool>> dp(n,vector<bool>(k+1,false)); 

    for(int i=0;i<n;i++){
        dp[i][0]=true;              
    }
    if(arr[0]<=k) dp[0][arr[0]]=true;  

    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool notTake=dp[ind-1][target];

            bool take=false;
            if(target>=arr[ind])
            take=dp[ind-1][target-arr[ind]];

            dp[ind][target]=take||notTake;
        }
    }
    int mini=INT_MAX;
    for(int s1=0;s1<k/2;s1++){
        if(dp[n-1][s1]==true){
            mini=min(mini,abs((k-s1)-s1));   //k-s1=s2, s1
        }
    }
    return mini;
}

int partition(vector<int> &arr){
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return subsetSumToK(n,sum,arr);

}