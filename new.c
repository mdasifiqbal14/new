// input: sorted array arr[] of size n, two integers a, b
// output: number of pairs (x, y) such that a<=x+y<=b and x, y in arr[]
// time complexity should be n*log(n)

#include <stdio.h>

typedef struct {int start; int end;} position;

position binsearch(int arr[], int start, int end, int find){
  if(end<start){
    position p={end, start};
    return p;
  }
  int mid=(start+end)/2;
  if(find==arr[mid]){
    position p={mid, mid};
    return p;
  }
  else if(find<arr[mid])
    return binsearch(arr, start, mid-1, find);
  else
    return binsearch(arr, mid+1, end, find);
}

int main(){
  int arr[]={1,2,4,5};
  int n=sizeof(arr)/sizeof(arr[0]);
  int find;
  position p, q;
  int i, left, right;
  int a=1;
  int b=10;
  int num=0;

  for(i=0;i<n;i++){
    left=a-arr[i];
    right=b-arr[i];
    p=binsearch(arr, 0, n-1, left);
    q=binsearch(arr, 0, n-1, right);
    if(p.end!=n && q.start!=-1) num+=(q.start-p.end+1);
  }
}