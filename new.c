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
  position p=binsearch(arr, 0, n-1, find);
  printf("%d %d", p.start, p.end);
}