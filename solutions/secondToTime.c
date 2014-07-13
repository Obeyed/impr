#include<stdio.h>

#define MINUTE 60
#define HOUR 3600

int main(void){
  int sec, min, hour, inp;

  printf("Enter the total seconds: ");
  scanf("%d", &inp);
  printf("\n");

  hour = inp / HOUR;
  min  = inp % HOUR / MINUTE;
  sec  = inp % HOUR % MINUTE;

  hour > 0 ? (hour == 1 ? printf("%d time", hour) : printf("%d timer", hour)) : printf("");
  min > 0 ? (sec > 0 ? printf(", ") : printf(" og ")) : (sec > 0 ? printf(" og ") : printf(""));
  min > 0 ? (min == 1 ? printf("%d minut", min) : printf("%d minutter", min)) : printf("");
  sec > 0 ? printf(" og ") : printf("");
  sec > 0 ? (sec == 1 ? printf("%d sekund", sec) : printf("%d sekunder", sec)) : printf("");

  return 0;
}
