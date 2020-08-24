//-----------------modifiaction of kadane's algorithm-------------------
//------------****negative when multiplied with negative gives bigger number -------------
class Solution {
public:
    int maxProduct(vector<int>& a) {
      int lmax= a[0];
      int lmin=a[0];
      int gmax=a[0];
        for(int i=1;i<a.size();i++)
        {
            if(a[i]<0) //**********//
                swap(lmax,lmin);
            lmax=max(lmax*a[i],a[i]);
            lmin=min(lmin*a[i],a[i]);
            gmax=max(lmax,gmax);
        }
        return gmax;
    }
};