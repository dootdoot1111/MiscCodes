#include <bits/stdc++.h>
using namespace std;
//tcO(2^n)
void print(vector<int> inp,int index,vector<char> &arr,int tempsum,int target){
    int n=inp.size();
    if(index>=n)
    {   if(tempsum==target)
        for(auto it:arr){
            cout<<it<<" ";
        }
    }
    arr.push_back(inp[index]);
    tempsum+=inp[index];
    print(inp,index+1,arr,tempsum,target);        //to pick

    tempsum=tempsum-inp[index];
    arr.pop_back();
    
    print(inp,index+1,arr,tempsum,target);        //to not pick

}