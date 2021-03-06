
//Accepted	4 ms	cpp
class Solution {
public:
    int numDecodings(string s) {
        int count = 0;
        if(s.length() == 0) return 0;
        if(s[0] == '0') return 0;
        
        int *dp = (int*)malloc(sizeof(int) * (s.length()+1));
        memset(dp, 0, sizeof(int)*(s.length() + 1));
        dp[0] = 1;
        dp[1] = s[0] != '0' ? 1:0;
        
        for(int i=2;i<=s.length();i++){
            int a = stoi(s.substr(i-1,1));
            int b= stoi(s.substr(i-2,2));
            
            if(a >= 1 && a<= 9){
                dp[i] += dp[i-1];
            }
            
            if(b >= 10 && b <= 26){
                dp[i] += dp[i-2];
            }
        }
        
        
        count = dp[s.length()];
        free(dp);
        return count;
    }
    
};
