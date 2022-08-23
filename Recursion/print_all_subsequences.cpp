#include <bits/stdc++.h>
using namespace std;
void print(vector<int> inp,int index,vector<char> &arr){
    int n=inp.size();
    if(index>=n)
    {
        for(auto it:arr){
            cout<<it<<" ";
        }
    }
    arr.push_back(inp[index]);
    print(inp,index+1,arr);        //to pick

    arr.pop_back();
    print(inp,index+1,arr);        //to not pick

}