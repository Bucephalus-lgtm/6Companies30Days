class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1, r = 1e9, k = 0;

        while (l <= r) {
            k = (l + r) / 2;
            int h = 0;
            for (int i = 0; i < piles.size(); i ++) 
                h += ceil(1.0 * piles[i] / k);
            if (h > H) l = k + 1;
            else r = k - 1;
        }
        return l;
    }
};