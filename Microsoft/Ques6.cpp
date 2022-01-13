// https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1/

class Solution
{
public:
    void generate(unordered_map<int, vector<char>> &mp, int a[], int n, int index, string temp, vector<string> &res)
    {

        if (index == n)
        {
            res.push_back(temp);
            return;
        }

        auto v = mp[a[index]];

        for (int i = 0; i < v.size(); i++)
        {
            generate(mp, a, n, index + 1, (temp + v[i]), res);
        }
    }
    // Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        // Your code here
        unordered_map<int, vector<char>> mp;

        mp[2] = {'a', 'b', 'c'};
        mp[3] = {'d', 'e', 'f'};
        mp[4] = {'g', 'h', 'i'};
        mp[5] = {'j', 'k', 'l'};
        mp[6] = {'m', 'n', 'o'};
        mp[7] = {'p', 'q', 'r', 's'};
        mp[8] = {'t', 'u', 'v'};
        mp[9] = {'w', 'x', 'y', 'z'};

        vector<string> res;
        int index = 0;
        generate(mp, a, N, index, temp, res);

        return v;
    }
};