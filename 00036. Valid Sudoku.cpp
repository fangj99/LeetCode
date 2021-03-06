
//Accepted	56 ms	cpp
class Solution {
public:
    Solution()
    {
        memset(row,false,sizeof(row));
        memset(col,false,sizeof(col));
        memset(block,false,sizeof(block));
    }
    bool isValidSudoku(vector<vector<char> > &board) {
        int num;
        for(unsigned i=0;i<board.size();i++)
        {
            for(unsigned j=0;j<board[i].size();j++)
            {
                if(board[i][j] != '.')
                {
                    num = board[i][j] - '0';
//                    cout<<num<<" "<<row[i][num]<<" "<<col[j][num]<<" "<<block[(i/3)*3 + j/3][num]<<endl;
                    if(row[i][num]) return false;
                    row[i][num] = true;
                    if(col[j][num]) return false;
                    col[j][num] = true;
                    if(block[(i/3)*3 + j/3][num]) return false;
                    block[(i/3)*3 + j/3][num] = true;
                }
            }
        }
        return true;
    }

private:
    static const int N = 10;
    bool row[N][N],block[N][N],col[N][N];
};
