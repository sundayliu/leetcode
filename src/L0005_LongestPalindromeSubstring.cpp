#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // DP
    // m[i][j]  s[i]...s[j]
    // i==j   m[i][j] = true
    // i != j    m[i] == m[j] && m[i+1][j-1]
    string longestPalindrome(string s) {
        if (s.size() <= 1)return s;
        
        int m[s.size()][s.size()] = {0}; // c++ 11
        int left = 0;
        int right = 0;
        int len = 0;
        for(int j = 0; j < s.size(); j++)
        {
            for(int i = 0; i < j; i++)
            {
                m[i][j] = (s[i]==s[j] && (j-i<2||m[i+1][j-1]));
                if (m[i][j] && len < j-i+1)
                {
                    len = j - i + 1;
                    left = i;
                    right = j;
                }
            }
            m[j][j] = 1;
        }
        return s.substr(left,right-left+1);
    }
};

int main(int argc, char* argv[])
{
    Solution sln;
    string s = "babad";
    string ret = sln.longestPalindrome(s);
    cout << ret << endl;
    return 0;
}