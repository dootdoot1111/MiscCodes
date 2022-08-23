#include <bits/stdc++.h>
using namespace std;
//count karne ka technique, use l and r and end mein return karwa do l+r
int print(vector<int> inp,int index,vector<char> &arr,int tempsum,int target){
    int n=inp.size();
    if(index>=n)
    {   if(tempsum==target){
        return 1;

        return 0;
    }
    
    arr.push_back(inp[index]);
    tempsum+=inp[index];
    int l= print(inp,index+1,arr,tempsum,target);   //to pick
   

    tempsum=tempsum-inp[index];
    arr.pop_back();
    
    int r=print(inp,index+1,arr,tempsum,target);   //to not pick
    

    return l+r;
}}