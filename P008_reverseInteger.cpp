// consider the overflow condition
class Solution {
public:
    int reverse(int x) {
        int y = 0;
        while(x != 0) {
            auto rest = x % 10;
            if(x > 0 && ((INT_MAX - rest) / 10 < y)) return 0;
            if(x < 0 && ((INT_MIN - rest) / 10 > y)) return 0;
            y = (y * 10 + rest);
            x /= 10;
        }
        return y;
    }
};
