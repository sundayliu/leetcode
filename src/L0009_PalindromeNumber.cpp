#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x >=0 && x<=9) return true;
        vector<int> data;
        while(x > 0)
        {
            int res = x % 10;
            data.push_back(res);
            x = x / 10;
        }
        int n = data.size();
        int i = 0,j = 0;
        if (n % 2 == 0)
        {
            i = n / 2;
            j = n / 2 - 1;
        }
        else
        {
            i = j = n / 2;
        }
        
        bool result = true;
        for(;i<n && j >=0;i++,j--)
        {
            if (data[i] != data[j])
            {
                result = false;
                break;
            }
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    Solution sln;
    bool result = sln.isPalindrome(-121);
    cout << result << endl;
    result = sln.isPalindrome(121);
    cout << result << endl;
    
    result = sln.isPalindrome(120);
    cout << result << endl;
    return 0;
}