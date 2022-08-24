#include<bits/stdc++.h>
using namespace std;

//elements in the input vector are all greater than 0
//recursion based count waala
int f(int ind,int target,vector<int> &arr){
  //improvised base case, can handle input values equal to 0 too
    if(ind==0){
        if(target==0 && arr[0]==0)     //if both the target and the last element is 0, topick or nottopick doesnt make a diff
        return 2;
        if(target==0 || target==arr[0])        //if target equals 0 returns 1, or if last mein target equals arr[0] toh only pick option,threrfore 1                                          
        return 1;
        return 0;       //baaki cases mein return 0
    } 

    int notTake=f(ind-1,target,arr);
    int take= false;
    if(target>=arr[ind]){
        take=f(ind-1,target-arr[ind],arr);
    }
    return take + notTake;
}
bool subsetSumToK(int n,int k,vector<int> &arr){
    return f(n-1,k,arr);
}


// left right waale technique recursion ka converted to tabulation 
int countsubsetSumToK(int n,int k,vector<int> &arr){
    vector<vector<int>> dp(n,vector<int>(k+1,false)); 

    for(int i=0;i<n;i++){
        dp[i][0]=1;              //kabhi target 0 ho rha toh return true
    }
    dp[0][arr[0]]=1;  //base case number 2, agar last element tak aagya and last element equals to target to store true

    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            int notTake=dp[ind-1][target];

            int take=0;
            if(target>=arr[ind])
            take=dp[ind-1][target-arr[ind]];

            dp[ind][target]=take+notTake;
        }
    }
    return dp[n-1][k];
}


//todo space optimisation waala using prev and curr vectors