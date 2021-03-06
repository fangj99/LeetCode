
//Accepted    4 ms    cpp
struct node
{
    string state;
    int value;
    int leftCnt;
    int rightCnt;
    node(string _s="",int _v=0,int _l=0,int _r=0):state(_s),value(_v),leftCnt(_l),rightCnt(_r){}
};
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        len = 2*n-1;
        bfs(n);
        return ans;
    }
    void bfs(int n){
        queue<node> Q;
        node now,after;
        now.state +="(";
        now.value = 1;
        now.leftCnt = 1;
        Q.push(now);
        while(!Q.empty()){
            now = Q.front();
            Q.pop();
            if(now.state.length() == 2*n && now.value == 0){
                ans.push_back(now.state);
                continue;
            }
            if(now.value - 1 >= 0 && now.rightCnt < n){
                after.state = now.state + ')';
                after.value = now.value - 1;
                after.leftCnt = now.leftCnt;
                after.rightCnt = now.rightCnt + 1;
                Q.push(after);
            }
            if(now.value + 1 >= 0 && now.leftCnt < n){
                after.state = now.state + '(';
                after.value = now.value + 1;
                after.rightCnt = now.rightCnt;
                after.leftCnt = now.leftCnt+1;
                Q.push(after);
            }
        }
    }
    Solution()
    {
        ans.clear();
    }
private:
    vector<string> ans;
    int len;
};

