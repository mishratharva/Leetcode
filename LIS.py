def LongestIncreasingSubsequence(a):
  n=len(a)
  if n==0:
    return 0
  dp=[]
  
  for i in range(n+1):
    dp.append(1)
    
    
  for i in range(1,n):
    for j in range(i):
      if a[i]>a[j]:
        dp[i]=max(dp[i],(dp[j]+1))
        
  mx=0
  
  
  for z in range(n+1):
    mx=max(dp[i],mx)
  return mx;



if _name_ == "_main_":
  
  l=list(map(int, input("Enter an array :\n").split()))
  answer=LongestIncreasingSubsequence(l)
  print("Longest Increasing Subsequence :",answer"r)
