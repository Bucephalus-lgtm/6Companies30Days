// https://practice.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum/1

int solve(Node *root, int target, int &count)
{
    if (!root)
        return 0;

    int leftSum = solve(root->left, target, count);
    int rightSum = solve(root->right, target, count);

    int sum = root->data + leftSum + rightSum;
    if (sum == target)
        count++;
    return sum;
}

// Function to count number of subtrees having sum equal to given sum.
int countSubtreesWithSumX(Node *root, int X)
{
    // Code here
    int count = 0;
    solve(root, X, count);
    return count;
}