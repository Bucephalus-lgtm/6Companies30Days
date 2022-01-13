// https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1

void rotate(int n, int a[][n])
{
    // code here
    int temp[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = a[j][n - 1 - i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = temp[i][j];
        }
    }
}