#include <bits/stdc++.h>
using namespace std;
//using two pointers ind and prev_ind
int f(int ind,int prev_ind,vector<int> inp,int n,vector<vector<int>> &dp){
if(ind==n)return 0;
if(dp[ind][prev_ind+1]!=-1)
return dp[ind][prev_ind+1];                     //tonotpick
int len=0+f(ind+1,prev_ind,inp,n,dp);
if(prev_ind==-1 || inp[ind]>inp[prev_ind]){
    len= max(len,1+f(ind+1,ind,inp,n,dp));      //tonotpick
}
return dp[ind][prev_ind+1] = len;
}

int longestIncreasingSusequence(vector<int> input){
    int n=input.size();
    vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
     return f(0,-1,input,n,dp);
}

//tabulation
int longestIncreasingSusequence2(vector<int> input){
    int n=input.size();
    vector<vector<int>> dp(n+1,vector<int> (n+1,0));
    for(int ind=n-1;ind>=0;ind--){
        for(int prev=ind-1;prev>=-1;prev--){
    int len=0+dp[ind+1][prev+1];
    if(prev==-1 || input[ind]>input[prev]){
        len= max(len,1+dp[ind+1][ind+1]);
    }
     dp[ind][prev+1] = len;
        }
    }
    return dp[0][0];
}

//spcae optimization
int longestIncreasingSusequence3(vector<int> input){
    int n=input.size();
    vector<int> next(n+1,0), curr(n+1,0);
    for(int ind=n-1;ind>=0;ind--){
        for(int prev=ind-1;prev>=-1;prev--){
    int len=0+next[prev+1];
    if(prev==-1 || input[ind]>input[prev]){
        len= max(len,1+next[ind+1]);
    }
     curr[prev+1] = len;
        }
        next=curr;
    }
    return curr[0];
}

//maintain a vector which stores ki uss index tak LIS ka max length kya hai
   int lengthOfLIS(vector<int>& input) {
        int n=input.size();
    vector<int> output(n,0);
    output[0]=1;
    for(int i=1;i<n;i++){
        output[i]=1;
        for(int j=i-1;j>=0;j--){
            if(input[j]>=input[i])
                continue;
            int possibleans=output[j]+1;
            if(output[i]<possibleans){
                output[i]=possibleans;
            }
            }
        }
    sort(output.begin(),output.end());
    return output[output.size()-1];
    }

//best TC=O(n) using Binary Search
int bestLengthLIS(vector<int> input){
    int n=input.size();
    vector<int> temp;
    temp.push_back(input[0]);
    int len=1;
    for(int i=1;i<n;i++){
        if(input[i]>temp.back()){
        temp.push_back(input[i]);
        len++;}
    
    else{
        int ind=lower_bound(temp.begin(),temp.end(),input[i])-temp.begin();
        temp[ind]=input[i];
    }}
    return len;
    
}
