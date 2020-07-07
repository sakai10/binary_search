#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int y=0;
  for(int j = 0; j < n; j++){
    y += (A[j]+x-1)/x;
  }
  return y <= k;
}
int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  
  int a_max = 0;
  for(int k = 0; k < n; k++){
      if(A[k] > a_max) a_max = A[k];
    }

  lb  = 0;
  ub = a_max;
  while(ub - lb > 1){
      int mid = (lb + ub) / 2;
      if(p(mid)){
          ub = mid;
      }
      else{
          lb = mid;
      }
   }
   
  printf("%d\n", ub);
  return 0;
}
