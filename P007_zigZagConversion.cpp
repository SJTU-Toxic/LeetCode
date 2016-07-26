class Solution1 {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        string res;
        int step = numRows * 2 - 2;
        for(int i = 1; i <= numRows; i++) {
            int j = i - 1;
            bool flag = false;
            while(j < s.size()) {
                res += s[j];
                if(i == 1 || i == numRows) {
                    j += step;
                }
                else if(flag == false) {
                    j += (step - (i - 1) * 2);
                    flag = true;
                }
                else {
                    j += ((i - 1) * 2);
                    flag = false;
                }
            }
        }
        return res;
    }
};
