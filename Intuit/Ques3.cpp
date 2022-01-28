// https://practice.geeksforgeeks.org/problems/find-the-missing-no-in-string/1

int extractNumber(const string& str, int i, int m)
{
    if (i + m > str.length()) return -1;
    return stoi(str.substr(i, m));    
}

int getLength(int num){
    return 1 + log10l(num);
}

/* You are required to complete this function
which return the required missing number
if present else return -1*/
int missingNumber(const string& str)
{
    // Code here
    int l = 1;
    for (; l<=6; ++l){
        int num = extractNumber(str, 0, l);
        if (num == -1) return -1;
        int ans = -1;
        bool flag = false;
        for (int i=l; i<str.size(); i += getLength(num)){
            if (ans == -1 and extractNumber(str, i, getLength(num+2)) == num+2){
                ans = num + 1;
                num += 2;
            }
            else if (extractNumber(str, i, getLength(num+1)) == num+1) num++;
            else
            {
                flag = true;
                break;
            }
        }
        if (!flag) return ans;
    }
    return -1;
}