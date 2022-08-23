   #include <bits/stdc++.h>
   using namespace std;


   //Find the element which is greater than both its left and right elements
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=1,r=arr.size()-2;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]>arr[mid-1] && arr[mid+1]<arr[mid])
                return mid;
            else if(arr[mid-1]>arr[mid])
                r=mid-1;
            else
                l=mid+1;
        }
        return -1;
    }