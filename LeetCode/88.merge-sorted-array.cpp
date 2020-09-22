/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //     int idx1 = m - 1, idx2 =  n - 1;
    //    for(int i = m + n - 1; i >= 0; i--){
    //        if(idx1 == 0){
    //            nums1[i] = nums2[idx2--];
    //            continue;
    //        }
    //        if(idx2 == 0){
    //            nums1[i] = nums1[idx1--];
    //            continue;
    //        }
    //         if(nums1[idx1] >= nums2[idx2 || idx2 == 0]){
    //             nums1[i] = nums1[idx1--];
    //         }
    //         else{
    //             nums1[i] = nums2[idx2--];
    //         }
    //    }
        int last=m+n-1;
        while(n){
            if(m==0||nums1[m-1]<=nums2[n-1]){
                nums1[last--]=nums2[--n];
            }else{
                nums1[last--]=nums1[--m];
            }
        }
    }
};
// @lc code=end

