
//Accepted	16 ms	cpp
class Solution {
private:
    vector<int> _Qcol;
    vector<vector<string> > _ans;
    int _n;
public:
    vector<vector<string> > solveNQueens(int n) {
        _Qcol = vector<int>(n,0);
        _n = n;
        
        dfs(0);
        
        return _ans;
    }
    
    void dfs(int step)
    {
        if(step == _n)
        {
            vector<string> tmp;
            for(int i=0;i<_n;i++)
            {
                string str = string(_n,'.');
                str[_Qcol[i]] = 'Q';
                tmp.push_back(str);
            }
            _ans.push_back(tmp);
        }
        for(int i=0;i<_n;i++)
        {
            if(judge(step,i))
            {
                _Qcol[step] = i;
                dfs(step+1);
                _Qcol[step] = 0;
                
            }
        }
    }
    
    bool judge(const int x,const int y)
    {
        for(int i=0;i<x;i++)
        {
            if(_Qcol[i] == y) return false;
            if(_Qcol[i] - y == i - x) return false;
            if(y - _Qcol[i] == i - x) return false;
        }
        return true;
    }
};

