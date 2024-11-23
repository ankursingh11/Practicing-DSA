
// https://www.naukri.com/code360/problems/1062679?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTabValue=PROBLEM

int NthRoot(int n, int m) {
  int start = 1, end = m;

  while(start <= end){
      int mid = (start + end)/2;

      if(pow(mid, n) == m) return mid;
      else if(pow(mid, n) < m) start = mid+1;
      else end = mid-1;
  }

  return -1;
}