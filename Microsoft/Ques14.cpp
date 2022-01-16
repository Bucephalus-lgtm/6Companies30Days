// https://practice.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1

class Solution
{
public:
    int minSteps(int D)
    {
        // code here
        int count = 0;
        int sum = 0;
        while (1)
        {
            sum += count;
            count++;
            if (sum == D)
                return count - 1;
            if (sum > D and (sum - D) % 2 == 0)
                return count - 1;
        }
        return 0;
    }
};