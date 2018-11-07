#include <iostream>
#include <string>
using namespace std;

// https://hk029.gitbooks.io/leetbook/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92/010.%20Regular%20Expression%20Matching/010.%20Regular%20Expression%20Matching.html
class Solution {
public:
    bool isMatch(string s, string p) {
        //return isMatchBacktrace(s,p);
        //return isMatchRecursive(s,p);
        return isMatchDP(s,p);
    }
    
    bool isMatchDP(string s, string p)
    {
        const int m = s.size();
        const int n = p.size();
        bool dp[m+1][n+1];
        dp[0][0] = true;
        for(int i = 1; i <=m;i++) dp[i][0] = false;
        for(int j = 1; j <=n;j++)
        {
            dp[0][j] = j > 1 && '*'==p[j-1]&& dp[0][j-2];
        }
        
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if (p[j-1] == '*')
                {
                    dp[i][j] = dp[i][j-2] || ((s[i-1]==p[j-2] || p[j-2]=='.') && dp[i-1][j]);
                }
                else
                {
                    dp[i][j] = (p[j-1]=='.' || p[j-1]==s[i-1]) && dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
    
    // 回溯法 从后往前匹配
     bool isMatchBacktrace(string s, string p)
    {
        
        return myMatchBacktrace(s,s.size()-1,p,p.size()-1);
    }
    
    bool myMatchBacktrace(string s,int i, string p, int j)
    {
        if (j == -1 )
        {
            if (i == -1) return true;
            else return false;
        }
        
        if (p[j] == '*')
        {
            if (i > -1 && (p[j-1]=='.'||p[j-1]==s[i]))
            {
                if (myMatchBacktrace(s,i-1,p,j)) return true;
                return myMatchBacktrace(s,i,p,j-2);
            }
        }
        
        if (p[j]=='.' || p[j] == s[i])
        {
            return myMatchBacktrace(s,i-1,p,j-1);
        }
        return false;
    }
    
    // 递归
    bool isMatchRecursive(string s, string p)
    {
        // 若p为空，若s也为空，返回true，反之返回false
        if (p.empty()) return s.empty();
        
        // 若p的长度为1，若s长度也为1，且相同或是p为'.'则返回true，反之返回false
        if (p.size() == 1)
        {
            return (s.size()==1 && (s[0]==p[0] || p[0]=='.'));
        }
        
        if (p[1] != '*')
        {
            // 若p的第二个字符不为*，若此时s为空返回false，否则判断首字符是否匹配，且从各自的第二个字符开始调用递归函数匹配
            if (s.empty()) return false;
            return (s[0]==p[0] || p[0]=='.') && isMatchRecursive(s.substr(1),p.substr(1));
        }
        else
        {
            // 若p的第二个字符为*，若s不为空且字符匹配，调用递归函数匹配s和去掉前两个字符的p，若匹配返回true，否则s去掉首字母
            while(!s.empty() && (s[0]==p[0] || p[0]=='.'))
            {
                if (isMatchRecursive(s,p.substr(2))) return true;
                else s = s.substr(1);
            }
        }
        
        // 返回调用递归函数匹配s和去掉前两个字符的p的结果
        return isMatchRecursive(s,p.substr(2));
    }
    
    bool isMatchRecursive2(string s, string p)
    {
        if (p.empty()) return s.empty();
        if (p.size()>1 && p[1]=='*')
        {
            return isMatchRecursive2(s,p.substr(2)) || (!s.empty() && (s[0]==p[0]||p[0]=='.') && isMatchRecursive2(s.substr(1),p));
        }
        else
        {
            return !s.empty() && (s[0]==p[0]||p[0]=='.') && isMatchRecursive2(s.substr(1),p.substr(1));
        }
    }
    
    // DP
};

int main(int argc,char* argv[])
{
    Solution sln;
    string s = "aa";
    string p = "a";
    cout << s << "|" << p << "|" << sln.isMatch(s,p) << endl;
    
    s = "aa";
    p = "a*";
    cout << s << "|" << p << "|" << sln.isMatch(s,p) << endl;
    
    s = "aa";
    p = "a*";
    cout << s << "|" << p << "|" << sln.isMatch(s,p) << endl;
    
    s = "ab";
    p = ".*";
    cout << s << "|" << p << "|" << sln.isMatch(s,p) << endl;
    
    s = "aab";
    p = "c*a*b";
    cout << s << "|" << p << "|" << sln.isMatch(s,p) << endl;
    
    return 0;
}