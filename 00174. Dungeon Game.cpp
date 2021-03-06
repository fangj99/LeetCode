/*
[Dungeon Game](https://leetcode.com/problems/dungeon-game/)

这题还是比较坑的。我一开始 从(0,0)开始bfs。 
剪枝策略是 `dp[x][y] < minHP` 就更新 `dp[x][y]` 值。 最后发现这个是不对。如果不是重点右下角的话，这种判断 会过滤一些有利的条件。 具体的TestCase 可以看这个：

`[[0,0,0],[-1,0,0],[2,0,-2]]`

答案是 2. 


其实，逆向思维 从右下角开始就OK！

*/
int min(const int a,const int b){
    return a<b?a:b;
}

int calculateMinimumHP(int** dungeon, int dungeonRowSize, int dungeonColSize) {
    int ans = 0;
    
    int **dp = (int **)malloc(sizeof(int *) * dungeonRowSize);
    for(int i=0;i<dungeonRowSize ;i++){
        dp[i] = (int *)malloc(sizeof(int) * dungeonColSize);
    }
    int row = dungeonRowSize - 1;
    int col = dungeonColSize - 1;
    
    dp[row][col] = dungeon[row][col] > 0 ? 1 : (1 - dungeon[row][col]);
    
    for(int i=row-1;i>-1;i--){
        dp[i][col] = dp[i+1][col] - dungeon[i][col];
        if(dp[i][col] < 1) dp[i][col] = 1;
    }
    for(int i=col-1;i>-1;i--){
        dp[row][i] = dp[row][i+1] - dungeon[row][i];
        if(dp[row][i] < 1) dp[row][i] = 1;
    }
    
    
    for(int i=row-1;i>-1;i--){
        for(int j=col-1;j>-1;j--){
            dp[i][j] = min(dp[i+1][j],dp[i][j+1]) - dungeon[i][j];
            if(dp[i][j] < 1) dp[i][j] = 1;
        }
    }
    
    ans = dp[0][0];
    
    for(int i=0;i<dungeonRowSize;i++){
        free(dp[i]);
    }
    free(dp);
    
    
    return ans;
}

