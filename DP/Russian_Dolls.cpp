#include <bits/stdc++.h>
using namespace std;


// nahi chal rha hai
static bool comp(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
    int helper(int ind,vector<vector<int>>& envelopes){
        int n=envelopes.size();
        if(ind==n)
            return 0;
        int notpick=0+helper(ind+1,envelopes);
        int pick=INT_MIN;
        if(envelopes[ind][0]>envelopes[ind-1][0] && envelopes[ind][1]>envelopes[ind-1][1]){
            pick=1+helper(ind+1,envelopes);
        }
        return max(pick,notpick);
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
         int n=envelopes.size();
        sort(envelopes.begin(), envelopes.end(), comp);
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                cout<<envelopes[i][j]<<" ";
            }
        }
        return helper(1,envelopes);
    }


//LIS ka concept height ke basis pe sort karo and if two heights are equal toh bade width waaletoh pehle daalo

static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& env) {
        int n = env.size();
        
        // sorting by height & if we encounter same height
        // sort by descending order of width
        sort(env.begin(), env.end(), cmp);
        
        // e.g. -> env => (3,8) (4,5) (2,1) (2,6) (7,8) (5,3) (5,7)
        // sorted version => (2,6) (2,1) (3,8) (4,5) (5,7) (5,3) (7,8)
        
        // Now, we only need to care about width
        // So, as of now we only need to look upon v[i][1]
        // [ 6, 1, 8, 5, 7, 3, 8 ]
        
        // Now, we can only put envolop a in envolop b another if width of a is
        // less than width of b, or we can say we need an envelop whose width
        // is just greater than envolop a ( height we have already handled )
        // So, we can think of lower_bound and Longest Increasing Subsequence
        
        // because we have sorted all envolopes of a particular height
        // by descending order of width, one envolope will not interfare with 
        // another envolop of same height, if we apply lower_bound
        // i.e. first elem greater than equal to itself in lis
        
        //LIS using binary search
        vector<int> lis;
        
        for(int i = 0;i<env.size();i++){
            int ele = env[i][1];
            
            int idx = lower_bound(lis.begin(), lis.end(), ele) - lis.begin();
            
            if(idx >= lis.size()) lis.push_back(ele);
            else lis[idx] = ele;
        }
        
        return lis.size();
    }
