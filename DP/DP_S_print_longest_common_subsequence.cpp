#include<bits/stdc++.h>
using namespace std;

//normal tareeke = brute force karna hoga

//iterate over the dp matrix of the lcs waala

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
    int length=dp[n][m];
    int index=length-1;
    int i=n;
    int j=m;
    string ans="";
    for(int i=1;i<=length;i++){
        ans+='$';
    }
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1])        //kyonki matrix mein 1 based indexing hai
        {
            ans[index]=s1[i-1];
            index--;
            i--;
            j--;
        }
        else if(s1[i-1]>s2[j-1]){
            i--;
        }
        else
        j--;
    }
    return ans;
}


//hackerrank
vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
    int n=a.size();
    int m=b.size();
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    for(int j=0;j<=m;j++)  //f(-1,j)-string hi nahi hai toh match bhi nahi karega, toh return 0 bas
    dp[0][j]=0;
    for(int i=0;i<=n;i++)
    dp[i][0]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1])                            
             dp[i][j]= 1+dp[i-1][j-1];             
    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i=n;
    int j=m;
    vector<int> res;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            res.push_back(a[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1])
                i--;
            else 
                j--;
        }
    }
    reverse(res.begin(),res.end());
    return res;
}