#include <stdio.h>

//defining the usage function to print to console if this can be used in later stages
// void usage(){
//   fprintf(stderr, "Usage: this program is a program built to satisfy the requirements of COMP2100 and has no further utility at this stage.\n\n------------\n\n");
// }

// defining the data struct to be used later on in main to make a data struct. Each field has had its bits specified by measn of defining the appropriate type.
struct data {
  char apples;
  unsigned int drug;
  short territory;
  char bead;
  long key;
  unsigned int cabbage;
  unsigned short minister;
  double neck;
  double jeans;
  unsigned char income;
  unsigned short credit;
  unsigned int rifle;
  int tomatoes;
  int stem;
  char needle[11];
  unsigned char pigs;
  float hour;
};

//This function is to take the leg workout of the big output to the console that is needed to be done to satisfy the requirements of 1.1. By removing it from the main function and giving it its own function it helps to quickly debug if there are issues with printing.
void printData(struct data d){

  //first printing the 'static' text
  printf("apples, drug, territory, bead, key, cabbage, minister, neck, jeans, income, credit, rifle, tomatoes, stem, needle, pigs, hour\n");

  //then printing the rest of the 'dynamic' text, breaking each field into its own print statement to better isolate issues
  printf("%d, ", d.apples);
  printf("%d, ", d.drug);
  printf("%4hx, ", d.territory);
  printf("%c, ", d.bead);
  printf("%li, ", d.key);
  printf("%d, ", d.cabbage);
  printf("%d, ", d.minister);
  printf("%f, ", d.neck);
  printf("%f, ", d.jeans);
  printf("%d, ", d.income);
  printf("%d, ", d.credit);
  printf("%d, ", d.rifle);
  printf("%d, ", d.tomatoes);
  printf("%d, ", d.stem);
  printf("%s, ", d.needle);
  printf("%d, ", d.pigs);
  printf("%f", d.hour);
  printf("\n");

};


int main(int argc, char **argv){

  struct data d = {6, 0, -1746, 'o', 396273, 0577, 1, -701.403702, 1.093750, 1, 0, 0, 0, 246, "fear", 0xa6, 363.302094};

  printData(d);

  return 0;

}