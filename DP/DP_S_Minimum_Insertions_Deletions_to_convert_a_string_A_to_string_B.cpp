#include <bits/stdc++.h>
using namespace std;


//ek string ko humesha doosre mein convert kar sakte hain by deleting everything from string 1 and inserting all characters from string 2 to string 1
//max operations is length of first string+second string
//common elements ko mat touch karo and lcs nikal ke, deletions=length(str1)-length(lcs), insertions=len(Str2)-len(lcs)

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


int canYouMake(string &str, string &ptr)
{   
    int lenlcs=lcs3(str,ptr);
    int deletions=str.length()-lenlcs;
    int insertions=ptr.length()-lenlcs;
    return insertions+deletions;
    // Write your code here.
}