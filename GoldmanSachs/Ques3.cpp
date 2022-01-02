// https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int l=0, r=0, count=0;
        long long product=1;
        while(r<n){
            product *= a[r];
            while(l<n && product>=k){
                product = product/a[l];
                l++;
            }
            if(product < k) count += r-l+1; 
            r++;
       }
       return count;
    }
};