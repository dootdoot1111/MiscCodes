#include <bits/stdc++.h>
using namespace std;

//https://www.codingninjas.com/codestudio/library/building-bridges
//sort karo either with respect to northern or southern cities then find LIS jissko tumne sort nahi kiya hai
int f(int ind,int prevind,vector<int> &input,int n,vector<vector<int>> &dp){
     if(ind==n)
    return 0;
    if(dp[ind][prevind+1]!=-1)
    return dp[ind][prevind+1];
    int len=0+f(ind+1,prevind,input,n,dp);
    if(prevind==-1 || input[ind]>input[prevind]){
        len=max(len,1+f(ind+1,ind,input,n,dp));
    }
    return dp[ind][prevind+1]=len;
}

int LISlen(vector<int> input){
    int n=input.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return f(0,-1,input,n,dp);
}

int min_bridges(vector<int> north,vector<int> south){
    vector<pair<int,int>> cities;
    int n=north.size();
    for(int i=0;i<n;i++){
        cities.push_back(make_pair(south[i],north[i]));
    }
    sort(cities.begin(), cities.end());
    vector<int> LISinput;
    for(int i=0;i<n;i++){
        LISinput.push_back(cities[i].second);
}
return LISlen(LISinput);

}

int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>> n;
        int temp;
        vector<int> north(n), south(n);
        for(int i=0;i<n;i++){
            cin>>temp;
            north.push_back(temp);
        }
        for(int i=0;i<n;i++){
            cin>>temp;
            south.push_back(temp);
        }
       cout<< min_bridges(north,south)<< " ";
       cout<<endl;
    }
}