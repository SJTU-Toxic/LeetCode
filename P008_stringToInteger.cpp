// my submission
class Solution1 {
public:
    int myAtoi(string str) {
        int res = 0;
        if(str.empty()) return res;
        int pos = 0;
        while(pos < str.size() && str[pos] == ' ') pos++;
        if(pos == str.size()) return res;
        if((pos == str.size() - 1) && (str[pos] < '0' || str[pos] > '9')) return res;
        if(str[pos] != '+' && str[pos] != '-') {
            if(str[pos] > '9' || str[pos] < '0') return res;
            res = str[pos] - '0';
        }
        else {
            int temp = pos;
            pos++;
            while(pos < str.size() && str[pos] == '0') pos++;
            if(str[pos] < '0' || str[pos] > '9') return res;
            if(str[temp] == '+') res = str[pos] - '0';
            else res = -(str[pos] - '0');
        }
        pos++;
        while(pos < str.size() && str[pos] >= '0' && str[pos] <= '9') {
            if(res > 0 && ((INT_MAX - (str[pos] - '0')) / 10 < res)) return INT_MAX;
            else if(res < 0 && ((INT_MIN + (str[pos] - '0')) / 10 > res )) return INT_MIN;
            res *= 10;
            if(res >= 0) res += (str[pos] - '0');
            else res -= (str[pos] - '0');
            pos++;
        }
        return res;
    }
};

// simple solution 
class Solution2 {
public:
    int myAtoi(string str) {
        int sgn = 1, i = 0, base = 0;
        while(i < str.length() && str[i] == ' ') {
            i++;
        }
        if(i < str.length() && (str[i] == '-' || str[i] == '+')) {
            sgn = 1 - 2 * (str[i++] == '-');
        }
        while(i < str.length() && str[i] <= '9' && str[i] >= '0') {
            if(INT_MAX / 10 < base || (INT_MAX / 10 == base && str[i] > '7')) {
                if(sgn == 1) return INT_MAX;
                else return INT_MIN;
            }
            base = base * 10 + (str[i++] - '0');

        }
        return base * sgn;
    }
};
