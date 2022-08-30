#include <bits/stdc++.h>
using namespace std;

int findCatalan(int n) 
    {
        vector<int>dp(n+1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            int h=i-1;
            int l=0;
            int sum=0;
            while(l<=h){
                if(l==h){
                    sum+=(dp[l]*dp[h]);
                }
                else{
                  sum+=((dp[l]*dp[h])+(dp[l]*dp[h]));
                }
                l++;
                h--;
            }
            dp[i]=sum;
        }
        return dp[n];
    }