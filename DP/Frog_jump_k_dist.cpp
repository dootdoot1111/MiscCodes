#include<bits/stdc++.h>
using namespace std;

int f(int ind,vector<int> height,int K){
    if(ind==0) return 0;
    int jump;
    int mmSteps=INT_MAX;
    for(int j=1;j<=K;j++){
        if(ind-j>=0){
            jump =f(ind-j,height,K)+abs(height[ind]-height[ind-j]);
            mmSteps=min(jump,mmSteps);
        }
    }
    return mmSteps;
}


