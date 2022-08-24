#include<bits/stdc++.h>
using namespace std;

//recursion based
bool f(int ind,int target,vector<int> &arr){
    if(target==0) return true;
    if(ind==0) return (arr[0]==target);

    bool notTake=f(ind-1,target,arr);
    bool take= false;
    if(target>=arr[ind]){
        take=f(ind-1,target-arr[ind],arr);
    }
    return take | notTake;
}
bool subsetSumToK(int n,int k,vector<int> &arr){
    return f(n-1,k,arr);
}


//memoization
bool f(int ind,int target,vector<int> &arr,vector<vector<int>> &dp){
    if(target==0) return true;  
    if(ind==0) return (arr[0]==target);
    if(dp[ind][target]!=-1) return (dp[ind][target]); //just check if dp vector already has any value stored
    bool notTake=f(ind-1,target,arr,dp);
    bool take= false;
    if(target>=arr[ind]){
        take=f(ind-1,target-arr[ind],arr,dp);
    }
    return dp[ind][target]=take | notTake;    //store it in the dp vector
}
bool subsetSumToK(int n,int k,vector<int> &arr){
    vector<vector<int>> dp(n,vector<int>(k+1,-1)); //initialised a 2d array since two varying parameters are there,only int type possible hoga,bool se nhi bana sakte
    return f(n-1,k,arr);
}


//tabulation; bottom-up approach
//recursive approach soch ke bas ussko convert karna hota hai, pehle dono base cases, then jitne parametrs vary ho rhe utne ka loop and bas recurive code ko convert kardo, recursion mein jo function call hota hai usse dp matrix ke indices bana do

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
            if(target>=arr[0])
            take=dp[ind-1][target-arr[ind]];

            dp[ind][target]=take||notTake;
        }
    }
    return dp[n-1][k];
}

//last case space optimisation, use two rows prev and curr,instead of a 2d matrix
//TC memoization, tabulation and space optimised cheezoin mein same hai par SC kam hote jaata hai
//SC space optimied mein O(target)
bool subsetSumToK(int n,int k,vector<int> &arr){
    vector<bool> prev(k+1,false), curr(k+1,false);
    prev[0]=true, curr[0]=true; 
    prev[arr[0]]=true;  

    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool notTake=prev[target];     //dp[ind-1] is prev

            bool take=false;
            if(target>=arr[0])
            take=prev[target-arr[ind]];

            curr[target]=take||notTake;
        }
        prev=curr;
    }
    return prev[k];
}