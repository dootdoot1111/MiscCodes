#include<bits/stdc++.h>
using namespace std;

//brute force-exponential in nature
//match or not match
//recursion 
int helper(int ind1,int ind2,string s1,string s2){
    if(ind1 <0 || ind2<0)
    return 0;

    if(s1[ind1]==s2[ind2])                            //if characters match
    return 1+helper(ind1-1,ind2-1,s1,s2);             //move both the iterators to the left

    return max(helper(ind1-1,ind2,s1,s2),helper(ind1,ind2-1,s1,s2));      //if character doesnt match, make two recursion calls, one mein ind1 ko kam karo and doosre mein ind2 ko
}
int lcs(string s1,string s2){
    int n=s1.length();
    int m=s2.length();
    return helper(n,m,s1,s2);
}


//memoisation TC=O(nxm), SC=O(nxm)+O(n+m), recursive stack ka space
int helper2(int ind1,int ind2,string s1,string s2,vector<vector<int>> &dp){
    if(ind1 <0 || ind2<0)
    return 0;
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    if(s1[ind1]==s2[ind2])                            //if characters match
    return 1+ helper2(ind1-1,ind2-1,s1,s2,dp);

    return dp[ind1][ind2]=max(helper2(ind1-1,ind2,s1,s2,dp),helper2(ind1,ind2-1,s1,s2,dp));      
}
int lcs2(string s1,string s2){
    int n=s1.length();
    int m=s2.length();
    vector<vector<int>> dp(n,vector<int> (m,-1));
    return helper2(n-1,m-1,s1,s2,dp);
}


//tabulation
//shifting of indices,1->0,n->n-1, kyonki mera base case -1 pe khatam hoga,toh shift everything 
int lcs3(string s1, string s2)
{
	int n=s1.length();
    int m=s2.length();
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    for(int j=0;j<=m;j++)  //f(-1,j)-string hi nahi hai toh match bhi nahi karega, toh return 0 bas
    dp[0][j]=0;
    for(int i=0;i<=n;i++)
    dp[i][0]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1])                            
             dp[i][j]= 1+dp[i-1][j-1];             
    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}