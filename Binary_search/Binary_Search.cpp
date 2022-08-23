   #include <bits/stdc++.h>
   using namespace std;
   int search(vector<int> &nums, int target) {
        int l=0,h=nums.size()-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]==target)
                return mid;
            else if(target<nums[mid]){
                h=mid-1;
            }
            else if(target>nums[mid]){
                l=mid+1;
            }
        }
        return -1;
    }