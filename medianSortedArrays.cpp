class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    int n=a.size();
    int m=b.size();
    if(n>m)
        return findMedianSortedArrays(b,a);
    int l=0;
    int k=(n+m-1)/2;
    int r=min(n,k);
        double ans;
        double d=1.000000;
     while(l<r)
     {
    int parX=(l+r)/2;
    int parY=k-parX;
         if( a[parX]<b[parY])
             l=parX+1;
         else 
             r=parX;
     }
             if((n+m)%2)
             {
                 ans=(max((l>0 ? a[l-1] : INT_MIN),((k-l)>=0 ?  b[k-l] :INT_MIN)))*d;
             }
             else
             {
                 // cout<<a[parX-1]<<" "<<a[parX]<<" "<<b[parY-1]<<" "<<b[parY]<<endl;
                 int x=(max((l>0 ? a[l-1] : INT_MIN),((k-l)>=0 ?  b[k-l] :INT_MIN)));
                 int y=(min((l<n ? a[l] : INT_MAX),((k-l+1)<m ?  b[k-l+1] :INT_MAX)));
                 ans=(x+y)/(2.0);
             }
         
     
        
        
     return ans;
    }
};