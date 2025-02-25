#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}    
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    if(!root) return {};
    vector<vector<int>>ans;
    queue<TreeNode*>bfs;
    bfs.push(root);
    bfs.push(NULL);
    vector<int>level;
    while(!bfs.empty()){
        TreeNode* top = bfs.front();
        bfs.pop();
        if(top==NULL){
            if(!level.empty()){
                ans.push_back(level);
                level.clear();
            }
            if(!bfs.empty()) bfs.push(top);
        }
        else{
            level.push_back(top->val);
            if(top->left) bfs.push(top->left);
            if(top->right) bfs.push(top->right);

        }
    }
    return ans;
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int>> bag = levelOrder(root);
    for(int i=0;i<bag.size();i++){
        for(int j=0;j<bag[i].size();j++){
            cout<<bag[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(n)
// Input: [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]
// Explanation: The tree is traversed level by level.
