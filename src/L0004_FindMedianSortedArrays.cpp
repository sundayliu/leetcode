#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result = 0.0f;
        int m = nums1.size();
        int n = nums2.size();
        
        if (m == 0)
        {
            if (n % 2 == 0)
            {
                result = (nums2[n/2] + nums2[n/2-1])/2.0f;
            }
            else
            {
                result = nums2[n/2];
            }
            return result;
        }
        if (n == 0)
        {
            if (m % 2 == 0)
            {
                result = (nums1[m/2] + nums1[m/2-1])/2.0f;
            }
            else
            {
                result = nums1[m/2];
            }
            return result;
        }
        int len = (m+n)/2;
        int m1,m2;
        bool m1_init = false;
        
        int i = 0;
        int j = 0;
        int k = 0;
        while(k <= len)
        {
            k++;
            
            
            if (i >= m)
            {
                if (m1_init)
                {
                    m1 = m2;
                    m2 = nums2[j];
                }
                else{
                    m1 = m2 = nums2[j];
                    m1_init = true;
                }
                j++;
                continue;
            }
            if (j >= n)
            {
                if (m1_init)
                {
                    m1 = m2;
                    m2 = nums1[i];
                }
                else{
                    m1 = m2 = nums1[i];
                    m1_init = true;
                }
                i++;
                continue;
            }
            
            if ((nums1[i] > nums2[j]))
            {
                if (m1_init)
                {
                    m1 = m2;
                    m2 = nums2[j];
                }
                else{
                    m1 = m2 = nums2[j];
                    m1_init = true;
                }
                j++;
                
            }
            else
            {
                
                if (m1_init)
                {
                    m1 = m2;
                    m2 = nums1[i];
                }
                else{
                    m1 = m2 = nums1[i];
                    m1_init = true;
                }
                i++;
                
            }
            //cout << m1 << " " << m2 << endl;
            //cout << i << " " << j << endl;
            
            
        }
        
        if ((m+n)%2 == 0)
        {
            result = (m1 + m2) / 2.0f;
        }
        else
        {
            result = m2;
        }
        
        return result;
    }
};

int main(int argc, char* argv[])
{
    int a[] = {1,2};
    int b[] = {3,4};
    
    vector<int> nums1(a,a+sizeof(a)/sizeof(a[0]));
    vector<int> nums2(b,b+sizeof(b)/sizeof(b[0]));
    Solution sln;
    double result = sln.findMedianSortedArrays(nums1,nums2);
    cout << result << endl;
    return 0;
}