#include<bits/stdc++.h>
using namespace std;

//any given string can be made a palindrome by just attaching the word with its reverse

//abcaa + rev(abcaa) = abcaaaacba which is a palindrome,par yeh minimum insertions nahi hai
//longest palindromic subsequence ke mid element ke dono taraf insert elements in a reverse order jo palindrome ke part hi nahi hain

//minimum insertions= length of the string - longest palindromic subsequence

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
