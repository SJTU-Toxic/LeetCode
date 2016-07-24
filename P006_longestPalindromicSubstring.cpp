// Solution 1 : brute force
// time: O(n^2) space: O(1)
class Solution1 {
public:
    string longestPalindrome(string s) {
        int max = 1, pos = 0;
        for(int i = 0; i <s.size(); i++) {
            int j = i, k = i + 1;
            int tmp, len;
            while(j >= 0 && k < s.size()) {
                if(s[j] == s[k]) {
                    tmp = j;
                    len = k - j + 1;
                    if(len > max) {
                        max = len;
                        pos = tmp;
                    }
                    j--;
                    k++;
                }
                else break;
            }
            j = i - 1, k = i + 1;
            while(j >= 0 && k < s.size()) {
                if(s[j] == s[k]) {
                    tmp = j;
                    len = k - j + 1;
                    if(len > max) {
                        max = len;
                        pos = tmp;
                    }
                    j--;
                    k++;
                }
                else break;
            }
        }
        return s.substr(pos, max);
    }
};
