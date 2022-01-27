// https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/

class Solution {
  public:
  int solve(Node* root){
      if(!root) return 0;
      int left = solve(root->left);
      int right = solve(root->right);
      int res = root->data + left + right;
      root->data = left + right;
      return res;
  }
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        // Your code here
        solve(node);
    }
};