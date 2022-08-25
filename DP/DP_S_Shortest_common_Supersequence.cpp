#include<bits/stdc++.h>
using namespace std;

//length og the shortest superstring= len(s1)+len(s2)-len(LCS)
//matrix mein traverse karke string banao
string lcs3(string s1, string s2)
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
    int i=n;
    int j=m;
    string ans="";
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1])        //kyonki matrix mein 1 based indexing hai
        {   ans+=s1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            ans+=s1[i-1];
            i--;
        }
        else{
        ans+=s2[j-1];
        j--;}
    }
    while(i>0) 
    {ans+=s1[i-1];
    i--;}
    while(j>0){
        ans+=s2[j-1];
        j--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

string shortestSupersequence(string a, string b)
{   
    return lcs3(a,b);
	// Write your code here.
}