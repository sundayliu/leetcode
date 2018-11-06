#include <unordered_map> // c++11
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums,int target)
    {
        vector<int> result;
        unordered_map<int,int> data;
        for(int i = 0; i < nums.size(); i++)
        {
            data[nums[i]] = i;
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            int t = target - nums[i];
            
            if (data.find(t) != data.end() && data[t] != i)
            {
                result.push_back(i);
                result.push_back(data[t]);
                break;
            }
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    int a[] = {2, 7, 11, 15};
    vector<int> nums(a,a+sizeof(a)/sizeof(a[0]));
    
    Solution sln;
    vector<int> result = sln.twoSum(nums,9);
    for(auto i = result.begin(); i != result.end(); i++)
    {
        cout << *i << ' ';
    }
    cout << endl;
    
    return 0;
}