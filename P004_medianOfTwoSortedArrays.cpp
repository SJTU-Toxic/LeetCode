// Solution 1
// time: O(n)
// space: O(n)

class Solution1 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] <= nums2[j]) nums3.push_back(nums1[i++]);
            else nums3.push_back(nums2[j++]);
        }
        while(i < nums1.size()) nums3.push_back(nums1[i++]);
        while(j < nums2.size()) nums3.push_back(nums2[j++]);
        if(nums3.size() % 2 == 0) return (nums3[nums3.size() / 2 - 1] + nums3[nums3.size() / 2]) / 2.0;
        else return (double)nums3[nums3.size() / 2];
    }
};
