#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,vector<string> > m;
        for(string str:strs)
        {
            string t = str;
            sort(t.begin(),t.end());
            m[t].push_back(str);
        }
        
        // cout << m.size() << endl;
        for(auto a:m)
        {
            // cout << a.first << endl;
            result.push_back(a.second);
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    vector<string> strs;
    const char* a[] = {"eat", "tea", "tan", "ate", "nat", "bat", NULL};
    for(int i = 0; a[i] != NULL;i++)
    {
        strs.push_back(a[i]);
    }
    
    cout << strs.size() << endl;
    
    Solution sln;
    vector<vector<string>> result = sln.groupAnagrams(strs);
    cout << result.size() << endl;
    for(int i = 0; i < result.size(); i++)
    {
        const vector<string>& x = result[i];
        for(int j = 0; j < x.size(); j++)
        {
            cout << x[j] << " ";
        }
        cout << endl;
    }
    return 0;
}