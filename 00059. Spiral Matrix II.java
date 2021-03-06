
//Accepted	332 ms	java
public class Solution {
    public int[][] generateMatrix(int n) {
        int [][]maze = new int[n][n];
        final int dir[][] = {{0,1},{1,0},{0,-1},{-1,0}};
        int _i,_j,count,length,k,i,j;
        length = n*n;
        count = 1;
        k = _i = _j = 0;
        while(count <= length)
        {
            maze[_i][_j] = count++;
            i = _i+dir[k][0];
            j = _j+dir[k][1];
            if(i<0||i>=n||j<0||j>=n||maze[i][j]!=0) 
            {
                k = (k+1)%4;
                i = _i+dir[k][0];
                j = _j+dir[k][1];
            }
            _i = i;
            _j = j;
        }
        return maze;
    }
}

