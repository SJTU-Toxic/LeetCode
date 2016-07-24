// Sliding Window O(n)
// worst case ： 2n
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash_table;
        int low = 0, high = 0, len = 0;
        while(low < s.length() && high < s.length()) {
            if(hash_table.find(s[high]) == hash_table.end()) {
                hash_table[s[high]] = high;
                ++high;
                len = max(len, high - low);
            }
            else {
                hash_table.erase(s[low++]);
            }
        }
        return len;
    }
};

// Optmized Sliding Window O(n)
class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash_table;
        int len = 0;
        for(int i = 0, j = 0; i < s.length(); i++) {
            if(hash_table.find(s[i]) != hash_table.end()) {
                j = max(j, hash_table[s[i]] + 1);
            }
            hash_table[s[i]] = i;
            len = max(len, i - j + 1);
        }
        return len;
    }
};


