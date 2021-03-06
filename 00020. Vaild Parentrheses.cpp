
//Accepted    2 ms    cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for_each(s.begin(), s.end(), [&](char ch){
            if(!S.empty() && ((S.top()=='('&& ch==')') || (S.top()=='['&&ch==']') || (S.top() == '{' && ch == '}'))){
                S.pop();
            }
            else{
                S.push(ch);
            }
        });
        return S.empty();
    }
};

