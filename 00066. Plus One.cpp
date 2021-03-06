
//	Accepted	4 ms	cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        
        std::reverse(digits.begin(), digits.end());
        
        int tmp = 1;
        
        for_each(digits.begin(), digits.end(), [&](int& num){
            num += tmp;
            tmp = num/10;
            num %= 10;
            ans.push_back(num);
        });
        
        if(tmp) ans.push_back(1);
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
