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

// Solution 2
// time: O(lg(m+n))
// space: O(1)

class Solution2 {
public:
    int kthSmallest(vector<int>::const_iterator it1, int m, vector<int>::const_iterator it2, int n, int k) {
        // if n > m swap two arrays
        if(n > m) return kthSmallest(it2, n, it1, m, k);
        // if the shorter array is empty
        if(n == 0) return *(it1 + k - 1);
        // if k == 1, find the smallest in two arrays
        if(k == 1) return min(*it1, *it2);
        // partition position should not be greater than size of the shorter arrays
        int pos = min(k / 2, n);
        int res = k - pos;
        if(*(it1 + res - 1) > *(it2 + pos - 1)) return kthSmallest(it1, res, it2 + pos, n - pos, k - pos);
        else return kthSmallest(it1 + res, m - res, it2, pos, k - res);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int half = (nums1.size() + nums2.size()) / 2;
        int median1 = kthSmallest(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), half + 1);
        if((nums1.size() + nums2.size()) % 2 == 0) {
            int median2 = kthSmallest(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), half);
            return (median1 + median2) / 2.0;
        } 
        return (double)median1;
    }
};
