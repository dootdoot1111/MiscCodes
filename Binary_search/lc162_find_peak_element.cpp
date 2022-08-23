#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        if(n == 2)return nums[0] > nums[1] ? 0 : 1;
        int i = 1, j = n-2;
        while(i <= j){
            int mid = j + (i-j)/2;
                if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
                else if(nums[mid+1] > nums[mid]) i = mid+1;
                else if(nums[mid-1] >= nums[mid]) j = mid-1;
        }
        //agar yaha tak kuch return nahi hua matlab, input is sorted either ascending/descending
        if(nums[0] > nums[1]) return 0; //for tc [6,5,4,3,2,3,2]
        else if(nums[n-1] > nums[n-2]) return n-1; //for tc [1,2,3]
        return -1;
    }