#include<bits/stdc++.h>
using namespace std;


//reverse function kuch return nahi karta hai
//longest palindrome ke liye we just need to find the lcs of the word and its reverse
//we can also print the longest common palindrominc subsequence using matrix pe traversal waala technique
int lcs(string s1, string s2)
{
    int n=s1.length();
    int m=s2.length();
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    for(int j=0;j<=m;j++)
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
int longestPalindromeSubsequence(string s)
{   string s1=s;
    reverse(s1.begin(),s1.end());
    return lcs(s, s1);
 
}
int minInsertion(string &str)
{
    return str.length()-longestPalindromeSubsequence(str);
}