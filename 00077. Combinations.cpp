
//Accepted	80 ms	cpp
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ans;

        vector<int> tmp;

//        bool *vis = (bool*)malloc(sizeof(bool)*(n+1));
//
//        memset(vis,false,sizeof(vis));

        dfs(ans,tmp,1,n,0,k);

        return ans;
    }

    void dfs(vector<vector<int> >& A,vector<int>& T,int star,int n,int step,int k)
    {
        if(step == k)
        {
            vector<int> tmp(T);
            A.push_back(tmp);
            return ;
        }

        for(int i=star;i<=n;i++)
        {
            if((T.size()==0 ||(i>T.back())))
            {
                T.push_back(i);
                dfs(A,T,star+1,n,step+1,k);
                T.pop_back();
            }
        }
    }
};
