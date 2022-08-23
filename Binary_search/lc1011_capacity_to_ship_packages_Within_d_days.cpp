#include<bits/stdc++.h>
using namespace std;

// Our answer will be lying between the maximum element in the array and the total sum of all the elements in the array. So,max_element and sum are the lower bound and the upper bound of our search space respectively.
// Next we perform binary search to find the minimum capacity(min_weight) required to ship all the elements.
// We check whether it is possible to ship all the packages within D days with the givenmin_weight using isPossibleToShip().
// i. If possible, we update the answer and check whether all the packages can be shipped with a lesser capacity.
// ii. If not, we update our lower bound max_element and find a different min_weight
bool isPossibleToShip(vector<int>& weights, int total_days, int min_capacity)
    {
        int days_so_far=1,load_for_a_day=0;
        for(int i=0;i<weights.size();i++)
        {
            load_for_a_day+=weights[i];
            if(load_for_a_day>min_capacity)
            {
                days_so_far++;
                load_for_a_day=weights[i];
            }
            if(days_so_far>total_days)
                return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int max_element=weights[0],sum=0,ans=-1,n=weights.size();
        for(int num:weights)
        {
            max_element=max(max_element,num);
            sum+=num;
        }
        while(max_element<=sum)
        {
            int min_weight = (max_element+sum)/2;
            if(isPossibleToShip(weights,days,min_weight))
            {
                sum=min_weight-1;
                ans=min_weight;
            }
            else
                max_element=min_weight+1;
        }
        return ans;
    }