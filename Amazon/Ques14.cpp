// https://practice.geeksforgeeks.org/problems/burning-tree/1

class Solution
{
public:
    int ans = 0, p = 0, fh;
    bool flag = false;
    int solve(Node *root)
    {

        if (!root)
            return 0;

        int l = 1 + solve(root->left);
        int r = 1 + solve(root->right);

        return max(l, r);
    }

    void path(Node *root, int target, int mh)
    {
        if (!root)
            return;

        if (root->data == target)
        {
            flag = true;
            ans = solve(root) - 1;
            fh = mh;
            return;
        }

        path(root->left, target, mh + 1);
        if (flag)
        {
            int h = solve(root->right);
            ans = max(ans, h + fh - mh);
            return;
        }
        path(root->right, target, mh + 1);

        if (flag)
        {
            int h = solve(root->left);
            ans = max(ans, h + fh - mh);
            return;
        }
    }

    int minTime(Node *root, int target)
    {
        // Your code goes here
        ans = 0;

        path(root, target, 0);

        return ans;
    }
};