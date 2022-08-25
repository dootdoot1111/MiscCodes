#include<bits/stdc++.h>
using namespace std;

//consecutive hona hai ab, toh matrix ke diagonal hi useful hoga bas
//dp on strings mein dp matrix pe iterate karke bahut kuch kar sakte hain
//row and column dono ek ek string represent karte hain
int lcs3(string s1, string s2)
{
	int n=s1.length();
    int m=s2.length();
    int ans=0;
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    for(int j=0;j<=m;j++)  //f(-1,j)-string hi nahi hai toh match bhi nahi karega, toh return 0 bas
    dp[0][j]=0;
    for(int i=0;i<=n;i++)
    dp[i][0]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]) {                           
             dp[i][j]= 1+dp[i-1][j-1];    //pichle diagonal element+1
             ans=max(ans,dp[i][j]);}

            else dp[i][j]=0;
        }
    }
    return ans;
}