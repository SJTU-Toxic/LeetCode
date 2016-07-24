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
// Solution 2
// time: O(n)
// space: O(n)
class Solution2 {
public:
    //pre-process
    string process(const string& s) {
        string res = "#";
        for(int i = 0; i < s.size(); i++) {
            res += s[i];
            res += '#';
        }
        return res;
    }
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        string temp = process(s);
        //the string is not longer than 1000, so the pre-processed string would not be longer than 2001
        int p[2001];
        for(int i = 0; i < temp.size(); i++) p[i] = 0;
        int pos = 0;
        int curMax = 0;
        int max = 1, idx = 0;
        for(int i = 0; i < temp.size(); i++) {
            int mirror = 2 * pos - i;
            if(curMax > i) {
                p[i] = min(p[mirror], curMax - i);
            }
            while(temp[i - p[i] - 1] == temp[i + p[i] + 1] && (i - p[i] >= 0) && (i + p[i] < temp.size())) p[i]++;
            if(p[i] + i > curMax) {
                pos = i;
                curMax = pos + p[i];
                if(p[i] > max) {
                    idx = i;
                    max = p[i];
                    // already reach the end of string
                    if(max >= temp.size() - i) break;
                }
            }
        }
        return s.substr((idx - max) / 2, max);
    }
};
