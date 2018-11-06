#include <iostream>
#include <climits>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x != 0)
        {
            if (abs(res) > INT_MAX/10) return 0;
            res = res * 10 + x % 10;
            x/=10;
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    Solution sln;
    int x = sln.reverse(-2147483648);
    cout << x << endl;
    
    x = INT_MAX;
    cout << dec << x << endl;
    cout << hex << x << endl;
    
    x = INT_MIN;
    cout << dec << x << endl;
    cout << hex << x << endl;
    
    x = -1;
    cout << dec << x << endl;
    cout << hex << x << endl;
    
    return 0;
}