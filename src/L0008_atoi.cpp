#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        int i = 0;
        for(; i < str.size() && str[i]==' ';i++);
        int sign = 1;
        int res = 0;
        if (i < str.size() && (str[i]=='+' || str[i]=='-'))
        {
            if (str[i] == '+') sign = 1;
            if (str[i] == '-') sign = -1;
            i++;
        }
        
        for(;i<str.size();i++)
        {
            if (str[i] >= '0' && str[i] <='9')
            {
                int digit = str[i]-'0';
                if (sign == -1 && -res < (INT_MIN+digit)/10) return INT_MIN;
                if (sign == 1 && res > (INT_MAX-digit)/10) return INT_MAX;
                res = res * 10 + digit;
            }
            else
            {
                break;
            }
        }
        
        return res*sign;
    }
};

int main(int argc, char* argv[])
{
    Solution sln;
    int result = sln.myAtoi("");
    cout << result << endl;
    result = sln.myAtoi("11111");
    cout << result << endl;
    result = sln.myAtoi("-22222222222222");
    cout << result << endl;
    
    result = sln.myAtoi("abdfksjfs");
    cout << result << endl;
    return 0;
}