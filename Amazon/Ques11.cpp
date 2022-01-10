// https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1

class Solution
{
public:
    vector<int> ans;
    void serializeHelper(Node *root)
    {
        if (!root)
        {
            ans.push_back(-1);
            return;
        }
        ans.push_back(root->data);
        serializeHelper(root->left);
        serializeHelper(root->right);
    }
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root)
    {
        // Your code here
        ans.clear();
        serializeHelper(root);
        return ans;
    }

    Node *deserializeHelper(vector<int> &A, int &index)
    {
        if (index >= A.size() or A.size() == 0)
            return NULL;
        if (A[index] == -1)
            return NULL;
        Node *temp = new Node(A[index]);
        index++;
        temp->left = deserializeHelper(A, index);
        index++;
        temp->right = deserializeHelper(A, index);
        return temp;
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &A)
    {
        // Your code here
        int index = 0;
        return deserializeHelper(A, index);
    }
};