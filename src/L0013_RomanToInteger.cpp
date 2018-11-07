#include <iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        if (s.empty()) return 0;
        int result = 0;
        int cur = 0;
        int pre = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'I') cur = 1;
            else if (s[i] == 'V') cur = 5;
            else if (s[i] == 'X') cur = 10;
            else if (s[i] == 'L') cur = 50;
            else if (s[i] == 'C') cur = 100;
            else if (s[i] == 'D') cur = 500;
            else if (s[i] == 'M') cur = 1000;
            
            if (pre < cur)
            {
                cur = cur - pre - pre;
            }
            pre = cur;
            result += cur;
        }
        return result;
    }
};

int main(int argc,char* argv[])
{
    Solution sln;
    cout << "III" << ":" << sln.romanToInt("III") << endl;
    cout << "IV" << ":" << sln.romanToInt("IV") << endl;
    cout << "IX" << ":" << sln.romanToInt("IX") << endl;
    cout << "LVIII" << ":" << sln.romanToInt("LVIII") << endl;
    cout << "MCMXCIV" << ":" << sln.romanToInt("MCMXCIV") << endl;
    
    return 0;
}