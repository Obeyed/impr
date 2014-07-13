#include <stdio.h>

#define HNDRD 100
#define FFTY 50
#define TWNTY 20
#define TEN 10

int convertToBills();

int main(void) {                     
  int dollars, hundreds, fifties, twenties, tens;
  float rest;

  printf("Enter amount in dollars: ");
  scanf(" %d", &dollars);

  rest = convertToBills(dollars, &hundreds, &fifties, &twenties, &tens);

  if(hundreds)
    printf("100 dollar bills: %d \n", hundreds);
  if(fifties)
    printf(" 50 dollar bills: %d \n", fifties); 
  if(twenties)
    printf(" 20 dollar bills: %d \n", twenties); 
  if(tens)
    printf("10 dollar bills: %d \n", tens); 
  printf("Remainding amount: $ %.2f \n", rest);

  return 0;
}

int convertToBills(int dollars, int *hds, int *fts, int *tts, int *tns) {
  *hds = dollars / HNDRD;
  *fts = dollars % HNDRD / FFTY;
  *tts = dollars % HNDRD % FFTY / TWNTY;
  *tns = dollars % HNDRD % FFTY % TWNTY / TEN;

  return (dollars % TEN);
}
