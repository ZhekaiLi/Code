#include<stdio.h>

int search( int item, int list[], int length );

int main()
{
  int list[10] = {1,4,9,24,54,66,71,74,83,90};
  int length = sizeof(list) / sizeof(list[0]);
  int item = 74;
  int ans;
  ans = search( item, list, length );
  if ( ans == -1 ) {
    printf("item cannot find");
  }else {
    printf("item is in list[%d]", ans);
	}
}

int search( int item, int list[], int length )
{
	int left = 0;
	int right = length-1;
	int ans = -1;
	while ( left < right)
	{
		int mid = (left+right) / 2;
		if ( item == list[mid] ) {
			ans = mid;
			break;
		}else if ( item > list[mid] ) {
			left = mid+1;
		}else {
			right = mid-1;
		}
	}
	return ans;
}
