/*
[98. Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)


## 题目大意

给定一棵二叉树，判断是否标准平衡二叉树

关于平衡树的定义：
https://en.wikipedia.org/wiki/Binary_search_tree



## 解题思路
中序遍历 二叉树，得出数组。按照定义该数组应该是 升序的
*/


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        
        vector<int> ans;
        treeToVector(root,ans);
        
        bool isVaild = true;
        
        for(size_t i = 1; i < ans.size();i++){
            if(ans[i] <= ans[i-1]){
                isVaild = false;
                break;
            }
        }
        
        return isVaild;
    }
    
private:
    void treeToVector(TreeNode *root, vector<int>& ans){
        if(!root) return;
        treeToVector(root->left, ans);
        ans.push_back(root->val);
        treeToVector(root->right, ans);
        
    }
};
