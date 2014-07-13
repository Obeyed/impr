#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int arrayMerge(const float *, const float*, float *, int, int);
void printArray(const float *, int);
int compare(const void *, const void *);

int main(void){
  float first[] = {-10.5, -1.8, 3.5, 6.3, 7.2}, 
	second[] = {-1.8, 3.1, 6.3},
        third[] = {0.0, -2, 7.2, -20.5, 1.4},	
	result[MAX];
  int sizeFrst, sizeScnd, sizeThrd, sizeResult;	 
  size_t sortSize;

  sizeFrst = sizeof(first) / sizeof(float);
  sizeScnd = sizeof(second) / sizeof(float);
  sizeThrd = sizeof(third) / sizeof(float);
  sortSize = sizeof(third) / sizeof(float);

  qsort(third, sortSize, sizeof(float), compare);

  printf("Calling merger with first then second:\n");
  sizeResult = arrayMerge(first, second, result, sizeFrst, sizeScnd);
  printArray(result, sizeResult);

  printf("\n\nCalling merger with second then first:\n");
  sizeResult = arrayMerge(second, first, result, sizeScnd, sizeFrst);
  printArray(result, sizeResult);

  printf("\n\nCalling merger with first then third:\n");
  sizeResult = arrayMerge(first, third, result, sizeFrst, sizeThrd);
  printArray(result, sizeResult);

  return 0;
}

void printArray(const float result[], int sRes){
  int i;

  for(i = 0 ; i < sRes ; i++)
    printf("%.1f ", result[i]);
}

int arrayMerge(const float arrayOne[], const float arrayTwo[], float merged[], int sOne, int sTwo){
  int i, j, sMerged;

  for(i = 0, sMerged = 0, j = 0 ; i < sOne && j < sTwo ; ){  
    if(arrayOne[i] == arrayTwo[j]){
      merged[sMerged++] = arrayOne[i++];
      j ++;
    }
    else if(arrayOne[i] < arrayTwo[j]){
      merged[sMerged++] = arrayOne[i++];
    }
    else{
      merged[sMerged++] = arrayTwo[j++];
    }
  }

  while(i < sOne)
    merged[sMerged++] = arrayOne[i++];

  while(j < sTwo)
    merged[sMerged++] = arrayTwo[j++];

  return sMerged;
}

int compare(const void *a, const void *b){
  float *pa = (float *) a,
	*pb = (float *) b;

  return *pa - *pb;
}
