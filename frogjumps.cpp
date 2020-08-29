class Solution {
public:
    bool canCross(vector<int>& stones) {
        for(int i=3;i<stones.size();i++)
        {
            if(stones[i]>stones[i-1]*2)
                return false;
        }
     set<int>st;
        for(int i=0;i<stones.size();i++)
            st.insert(stones[i]);
        stack<int>positions,jumps;
        positions.push(0);
        jumps.push(0);
        int laststone=stones[stones.size()-1];
        while(!positions.empty())
        {
            int pos=positions.top();
            positions.pop();
            int jumpPositions=jumps.top();
            jumps.pop();
            for(int i=jumpPositions-1;i<=jumpPositions+1;i++)
            {
                if(i<=0)
                    continue;
                int nextposition=pos+i;
                if( nextposition==laststone)
                    return true;
                else if(st.find(nextposition)!=st.end())
                {
                    positions.push(nextposition);
                    jumps.push(i);
                }
            }
        }
      return false;  
    }
};