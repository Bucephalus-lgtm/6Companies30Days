// https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1/

string decToBinary(int n)
{
    string str;
    for (int i = 31; i >= 0; i--)
    {
        int k = n >> i;
        if (k & 1)
            str.push_back('1');
        else
            str.push_back('0');
    }
    for (int i = 0; i < 32; i++)
    {
        if (str[i] == '1') return str.substr(i);
    }
}

vector<string> generate(int N)
{
    // Your code here
    vector<string> ans;
    for (int i = 1; i <= N; i++)
    {
        string temp = decToBinary(i);
        ans.push_back(temp);
    }
    return ans;
}