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
