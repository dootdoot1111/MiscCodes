#include <bits/stdc++.h>
using namespace std;
//tcO(2^n)
//bool function use karke ek subseq print karwa ke excess recursive calls ko avoid kar sakte hain
bool print(vector<int> inp,int index,vector<char> &arr,int tempsum,int target){
    int n=inp.size();
    if(index>=n)
    {   if(tempsum==target){
        for(auto it:arr){
            cout<<it<<" ";
        }
        return true;}
        return false;
    }
    
    arr.push_back(inp[index]);
    tempsum+=inp[index];
    if( print(inp,index+1,arr,tempsum,target)==true)        //to pick
    return true;

    tempsum=tempsum-inp[index];
    arr.pop_back();
    
    if(print(inp,index+1,arr,tempsum,target)==true)        //to not pick
    return true;

    return false;
}