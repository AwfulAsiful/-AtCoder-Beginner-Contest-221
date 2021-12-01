

/* https://atcoder.jp/contests/abc221/tasks/abc221_a */

/* Submission */
#include<stdio.h>
#include <stdlib.h>



int main(){
  int A,B,ans=1,diff;
  scanf("%d %d",&A,&B);
  diff=B-A;
  diff=abs(diff);
  for(int i=1;i<=diff;i++){
    ans=32*ans;} 
  printf("%d",ans);
  return 0;
}