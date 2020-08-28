class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       vector<int>v(128,-1);// because ascii ia 7 bit character set(128 vals)
        int start=-1;
        int maxlen=0;
        for(int i=0;i<s.size();i++)
        {
          if(v[s[i]]>start)
              start=v[s[i]];
            v[s[i]]=i;
            maxlen=max(maxlen,i-start);
        }
        return maxlen;
    }
};