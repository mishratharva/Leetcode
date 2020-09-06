class Solution {
public:
    bool repeatedSubstringPattern(string s) {
       string str=s+s;
        string s1=str.substr(1,str.length()-2);
            if(s1.find(s)!=string::npos)
                return true;
             else
                 return false;
    }
};