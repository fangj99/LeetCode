//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//


#include <cmath>
#include <cstdio>
#include <cstdlib>

#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;


/**
 
 310. Minimum Height Trees
 
 For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.
 
 Format
 The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).
 
 You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
 
 Example 1:
 
 Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]
 
       0
       |
       1
      / \
     2   3
 return [1]
 
 Example 2:
 
 Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
 
     0  1  2
      \ | /
        3
        |
        4
        |
        5
 return [3, 4]
 
 Hint:
 
 How many MHTs can a graph have at most?
 Note:
 
 (1) According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
 
 (2) The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
 
 Credits:
 Special thanks to @dietpepsi for adding this problem and creating all test cases.
 
 Subscribe to see which companies asked this question.
 
 */


/**
 
 Breadth-first Search / Graph
 
 无向图 遍历每个图节点，当做根节点。 使用广度优先搜索从根节点开始遍历树，获取该根节点下的高度。
 n不大的情况下，图的连通性使用 二维数组保存
 
 时间复杂度为 tree_height(i) * n^2
 
 41 / 66 test cases passed.
 Status: Time Limit Exceeded
 
 
 420
 [[0,1],[1,2],[0,3],[0,4],[3,5],[4,6],[0,7],[4,8],[1,9],[6,10],[3,11],[0,12],[5,13],[8,14],[5,15],[7,16],[4,17],[0,18],[15,19],[8,20],[11,21],[16,22],[0,23],[13,24],[12,25],[3,26],[21,27],[1,28],[17,29],[3,30],[29,31],[15,32],[1,33],[0,34],[34,35],[19,36],[23,37],[4,38],[15,39],[16,40],[35,41],[27,42],[40,43],[35,44],[3,45],[30,46],[33,47],[16,48],[36,49],[42,50],[31,51],[25,52],[6,53],[52,54],[33,55],[17,56],[45,57],[19,58],[9,59],[37,60],[42,61],[36,62],[28,63],[1,64],[1,65],[60,66],[26,67],[23,68],[45,69],[27,70],[2,71],[7,72],[63,73],[37,74],[15,75],[36,76],[12,77],[48,78],[71,79],[53,80],[23,81],[5,82],[15,83],[33,84],[61,85],[9,86],[54,87],[1,88],[77,89],[76,90],[8,91],[27,92],[71,93],[87,94],[71,95],[66,96],[90,97],[25,98],[41,99],[31,100],[31,101],[30,102],[19,103],[46,104],[51,105],[42,106],[66,107],[97,108],[107,109],[106,110],[46,111],[5,112],[58,113],[40,114],[106,115],[103,116],[116,117],[22,118],[57,119],[10,120],[98,121],[34,122],[11,123],[89,124],[120,125],[114,126],[75,127],[126,128],[33,129],[40,130],[125,131],[96,132],[46,133],[130,134],[64,135],[22,136],[47,137],[61,138],[105,139],[44,140],[106,141],[83,142],[121,143],[68,144],[118,145],[139,146],[68,147],[84,148],[63,149],[1,150],[140,151],[40,152],[95,153],[10,154],[144,155],[66,156],[39,157],[71,158],[64,159],[94,160],[133,161],[66,162],[6,163],[65,164],[89,165],[156,166],[156,167],[126,168],[82,169],[58,170],[115,171],[80,172],[65,173],[63,174],[38,175],[168,176],[30,177],[34,178],[2,179],[22,180],[57,181],[93,182],[122,183],[38,184],[113,185],[59,186],[112,187],[2,188],[72,189],[140,190],[99,191],[15,192],[180,193],[176,194],[52,195],[18,196],[135,197],[26,198],[182,199],[160,200],[64,201],[76,202],[71,203],[137,204],[125,205],[161,206],[206,207],[50,208],[171,209],[98,210],[193,211],[162,212],[207,213],[63,214],[138,215],[129,216],[205,217],[60,218],[218,219],[189,220],[167,221],[168,222],[188,223],[81,224],[209,225],[117,226],[216,227],[79,228],[195,229],[127,230],[143,231],[153,232],[69,233],[110,234],[126,235],[136,236],[184,237],[156,238],[226,239],[233,240],[3,241],[1,242],[140,243],[129,244],[189,245],[186,246],[77,247],[245,248],[111,249],[156,250],[133,251],[135,252],[198,253],[165,254],[98,255],[191,256],[119,257],[37,258],[202,259],[8,260],[69,261],[31,262],[171,263],[100,264],[174,265],[216,266],[58,267],[255,268],[21,269],[108,270],[211,271],[31,272],[259,273],[20,274],[241,275],[38,276],[230,277],[115,278],[195,279],[245,280],[177,281],[183,282],[275,283],[85,284],[52,285],[236,286],[76,287],[218,288],[283,289],[259,290],[46,291],[193,292],[213,293],[164,294],[97,295],[46,296],[94,297],[151,298],[216,299],[68,300],[298,301],[118,302],[273,303],[249,304],[279,305],[274,306],[277,307],[65,308],[71,309],[206,310],[219,311],[14,312],[225,313],[225,314],[94,315],[141,316],[174,317],[216,318],[129,319],[266,320],[139,321],[223,322],[317,323],[283,324],[137,325],[168,326],[319,327],[3,328],[101,329],[24,330],[323,331],[241,332],[115,333],[158,334],[229,335],[203,336],[192,337],[291,338],[186,339],[206,340],[211,341],[324,342],[18,343],[196,344],[62,345],[97,346],[93,347],[293,348],[13,349],[274,350],[292,351],[154,352],[27,353],[61,354],[259,355],[129,356],[292,357],[17,358],[341,359],[166,360],[209,361],[301,362],[248,363],[232,364],[49,365],[188,366],[61,367],[56,368],[34,369],[359,370],[345,371],[125,372],[225,373],[222,374],[362,375],[2,376],[86,377],[46,378],[135,379],[124,380],[8,381],[279,382],[181,383],[193,384],[351,385],[280,386],[344,387],[331,388],[146,389],[74,390],[67,391],[132,392],[48,393],[234,394],[281,395],[96,396],[217,397],[13,398],[286,399],[197,400],[255,401],[319,402],[175,403],[203,404],[115,405],[63,406],[177,407],[53,408],[383,409],[115,410],[348,411],[274,412],[251,413],[77,414],[159,415],[209,416],[148,417],[84,418],[129,419]]
 
 
 使用 floyd n^3 求出全图的最短路，最小高度树的构造其实就是 根节点到叶子节点最远的距离。
 
 45 / 66 test cases passed.
 Status: Time Limit Exceeded
 
 404
 [[0,1],[0,2],[1,3],[1,4],[2,5],[3,6],[1,7],[1,8],[7,9],[1,10],[3,11],[2,12],[8,13],[13,14],[1,15],[12,16],[15,17],[13,18],[13,19],[11,20],[14,21],[10,22],[20,23],[17,24],[4,25],[5,26],[25,27],[5,28],[9,29],[17,30],[29,31],[24,32],[24,33],[28,34],[3,35],[29,36],[12,37],[0,38],[3,39],[37,40],[29,41],[29,42],[24,43],[10,44],[1,45],[12,46],[43,47],[31,48],[16,49],[45,50],[7,51],[3,52],[6,53],[2,54],[25,55],[28,56],[22,57],[18,58],[18,59],[3,60],[32,61],[47,62],[29,63],[39,64],[18,65],[30,66],[1,67],[23,68],[15,69],[64,70],[26,71],[50,72],[8,73],[17,74],[2,75],[67,76],[75,77],[48,78],[73,79],[34,80],[16,81],[71,82],[76,83],[72,84],[8,85],[34,86],[5,87],[12,88],[31,89],[84,90],[15,91],[19,92],[18,93],[42,94],[16,95],[31,96],[96,97],[92,98],[20,99],[16,100],[54,101],[90,102],[77,103],[46,104],[42,105],[83,106],[51,107],[60,108],[14,109],[55,110],[86,111],[62,112],[36,113],[21,114],[113,115],[15,116],[107,117],[25,118],[59,119],[93,120],[53,121],[2,122],[86,123],[9,124],[30,125],[40,126],[122,127],[102,128],[117,129],[1,130],[4,131],[16,132],[112,133],[40,134],[9,135],[102,136],[112,137],[55,138],[27,139],[136,140],[138,141],[95,142],[89,143],[102,144],[103,145],[76,146],[42,147],[58,148],[85,149],[72,150],[91,151],[116,152],[115,153],[78,154],[46,155],[133,156],[16,157],[148,158],[125,159],[104,160],[2,161],[46,162],[21,163],[76,164],[102,165],[49,166],[84,167],[85,168],[134,169],[126,170],[165,171],[149,172],[110,173],[37,174],[110,175],[127,176],[39,177],[78,178],[152,179],[34,180],[126,181],[69,182],[77,183],[132,184],[115,185],[56,186],[70,187],[96,188],[160,189],[16,190],[85,191],[39,192],[54,193],[11,194],[39,195],[174,196],[10,197],[43,198],[53,199],[16,200],[124,201],[94,202],[68,203],[30,204],[85,205],[204,206],[53,207],[28,208],[143,209],[83,210],[5,211],[88,212],[164,213],[50,214],[96,215],[43,216],[34,217],[46,218],[86,219],[160,220],[201,221],[189,222],[184,223],[124,224],[110,225],[101,226],[171,227],[80,228],[135,229],[225,230],[169,231],[66,232],[138,233],[47,234],[149,235],[59,236],[106,237],[208,238],[148,239],[114,240],[155,241],[24,242],[168,243],[158,244],[52,245],[240,246],[155,247],[138,248],[30,249],[50,250],[46,251],[230,252],[218,253],[140,254],[132,255],[52,256],[85,257],[216,258],[43,259],[216,260],[152,261],[84,262],[103,263],[80,264],[254,265],[138,266],[80,267],[51,268],[193,269],[118,270],[16,271],[260,272],[80,273],[253,274],[132,275],[34,276],[259,277],[14,278],[28,279],[167,280],[219,281],[234,282],[138,283],[3,284],[211,285],[239,286],[206,287],[57,288],[213,289],[258,290],[172,291],[128,292],[51,293],[106,294],[208,295],[13,296],[250,297],[21,298],[197,299],[100,300],[221,301],[233,302],[77,303],[55,304],[124,305],[23,306],[266,307],[46,308],[127,309],[60,310],[261,311],[166,312],[252,313],[207,314],[76,315],[249,316],[66,317],[121,318],[157,319],[106,320],[39,321],[152,322],[110,323],[150,324],[114,325],[106,326],[245,327],[70,328],[172,329],[72,330],[286,331],[321,332],[174,333],[123,334],[36,335],[318,336],[1,337],[80,338],[203,339],[272,340],[240,341],[19,342],[138,343],[202,344],[128,345],[167,346],[312,347],[265,348],[119,349],[334,350],[210,351],[129,352],[140,353],[280,354],[274,355],[308,356],[323,357],[226,358],[262,359],[270,360],[29,361],[289,362],[19,363],[162,364],[254,365],[20,366],[177,367],[334,368],[150,369],[110,370],[322,371],[338,372],[36,373],[24,374],[177,375],[112,376],[152,377],[334,378],[132,379],[248,380],[162,381],[59,382],[346,383],[99,384],[61,385],[299,386],[42,387],[384,388],[379,389],[290,390],[339,391],[58,392],[203,393],[276,394],[203,395],[299,396],[56,397],[121,398],[124,399],[155,400],[339,401],[278,402],[267,403]]
 
 
 拓扑排序,入度为1的节点必为叶子节点 或 根节点。以此为依据，依次去除叶子节点，最终剩余的节点即为最小高度树的根节点
 
 时间复杂度为 edges 图的边数
 
 66 / 66 test cases passed.
 Status: Accepted
 Runtime: 62 ms
 
 
 */


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        
        vector<unordered_set<int>> graph(n);
        for(pair<int, int> edge : edges){
            graph[edge.first].insert(edge.second);
            graph[edge.second].insert(edge.first);
        }
        
        vector<int> leafs;
        
        for(int i=0;i<n;i++) if(graph[i].size() == 1) leafs.push_back(i);
        
        auto count = n - leafs.size();
        if(leafs.size() < 1) return (leafs.push_back(0),leafs);
        
        while(count > 0){
            vector<int> tmp;
            for(int leaf : leafs){
                
                for(int neighbor : graph[leaf]){
                    graph[neighbor].erase(leaf);
                    if(graph[neighbor].size() == 1) tmp.push_back(neighbor);
                }
                
            }
            
            leafs = tmp;
            count -= leafs.size();
        }
        
        return leafs;
    }
    
};


// n = 4, edges = [[1, 0], [1, 2], [1, 3]] => [1]
// n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]  => [3,4]

int main(){
    Solution solve;
    vector<pair<int, int>> edges;
    
    vector<int> ans = solve.findMinHeightTrees(1, edges);
    
    for(int root : ans) cout<<root<<endl;
    
    
    return 0;
}