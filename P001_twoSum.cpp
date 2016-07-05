class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numsMap;
        unordered_map<int, int>::const_iterator it;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            it = numsMap.find(target - nums[i]);
            if(it == numsMap.end())
                numsMap[nums[i]] = i;
            else {
                res.push_back(min(i, it->second));
                res.push_back(max(i, it->second));
                break;
            }
        }
        return res;
    }
};