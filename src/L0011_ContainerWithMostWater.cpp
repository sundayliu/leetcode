#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        if (height.size() <= 1) return 0;
        int i = 0,j = height.size()-1;
        while (i < j)
        {
            area = max(area,min(height[i],height[j]) * (j-i));
            if (height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return area;
    }
};

int main(int argc, char* argv[])
{
    int a[] = {1,8,6,2,5,4,8,3,7};  // 49
    vector<int> heights(a,a+sizeof(a)/sizeof(a[0]));
    Solution sln;
    int area = sln.maxArea(heights);
    cout << area << endl;
    
    return 0;
}