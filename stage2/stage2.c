#include <stdio.h>

char* fileName = "input-1.bin";

void usage(int error){
  switch(error){
    case 1 : 
      printf("You did not enter a file name.");
      break;
    case 2 :
      printf("Please enter a valid file name. The file %s is invalid.", fileName);
      break;
    default: 
      printf("Error.");
  };
  printf("\n");
};

struct data {
  char apples;
  int drug;
  short territory;
  char bead;
  long key;
  unsigned int cabbage;
  short minister;
  double neck;
  double jeans;
  char income;
  short credit;
  int rifle;
  int tomatoes;
  int stem;
  char needle[11];
  unsigned char pigs;
  float hour;
};

// this function prints out the labels that precede the data
void printContextHeader(){
  printf("apples, drug, territory, bead, key, cabbage, minister, neck, jeans, income, credit, rifle, tomatoes, stem, needle, pigs, hour");
};

// this function prints a filled data structure
void printData(struct data *d){

  //printing the 'dynamic' text by breaking each field into its own print statement to better isolate issues and debug
  printf("\n");
  printf("%d, ", d->apples);
  printf("%d, ", d->drug);
  printf("%hx, ", d->territory);
  printf("%c, ", d->bead);
  printf("%li, ", d->key);
  printf("%u, ", d->cabbage);
  printf("%d, ", d->minister);
  printf("%f, ", d->neck);
  printf("%f, ", d->jeans);
  printf("%d, ", d->income);
  printf("%d, ", d->credit);
  printf("%d, ", d->rifle);
  printf("%d, ", d->tomatoes);
  printf("%d, ", d->stem);
  printf("%s, ", d->needle);
  printf("%d, ", d->pigs);
  printf("%f", d->hour);

};

// this function takes a reference to a data strucutre and a file and reads the info from the file into the data structure
void readDataIntoStructField(struct data *d, FILE * inputFile){
  fread(&d->apples,sizeof(d->apples),1,inputFile);
  fread(&d->drug,sizeof(d->drug),1,inputFile);
  fread(&d->territory,sizeof(d->territory),1,inputFile);
  fread(&d->bead,sizeof(d->bead),1,inputFile);
  fread(&d->key,sizeof(d->key),1,inputFile);
  fread(&d->cabbage,sizeof(d->cabbage),1,inputFile);
  fread(&d->minister,sizeof(d->minister),1,inputFile);
  fread(&d->neck,sizeof(d->neck),1,inputFile);
  fread(&d->jeans,sizeof(d->jeans),1,inputFile);
  fread(&d->income,sizeof(d->income),1,inputFile);
  fread(&d->credit,sizeof(d->credit),1,inputFile);
  fread(&d->rifle,sizeof(d->rifle),1,inputFile);
  fread(&d->tomatoes,sizeof(d->tomatoes),1,inputFile);
  fread(&d->stem,sizeof(d->stem),1,inputFile);
  fread(&d->needle,sizeof(d->needle),1,inputFile);
  fread(&d->pigs,sizeof(d->pigs),1,inputFile);
  fread(&d->hour,sizeof(d->hour),1,inputFile);
};

long int initiateFileLength(int fileLength, FILE *inputFile){
  fseek(inputFile, 0, SEEK_END);
  fileLength = ftell(inputFile);
  fseek(inputFile, 0, SEEK_SET);
  return fileLength;
};

void handleFile(FILE *inputFile, long int fileLength, struct data *d){

  fileLength = initiateFileLength(fileLength, inputFile);

  //printing the context header
  printContextHeader();

  // looping over the file until we hit the end of the file by checking where our cursor is against the end of the file. Each loop reads the data into "d" the data structure, then prints it and moves the cursor finally.
  long int cursor = ftell(inputFile);
  while(cursor != fileLength){
    readDataIntoStructField(d, inputFile);
    printData(d);
    cursor = ftell(inputFile);
  }

  fclose(inputFile);
};

int main(int argc, char** argv){
  
  // declaring variables
  FILE *inputFile;
  struct data d;
  long int fileLength;

  //getting the file name
  if(argc != 0){
    fileName = argv[1];
    inputFile = fopen(fileName,"rb");
    if(inputFile != 0){
      handleFile(inputFile, fileLength, &d);
    } else {
      usage(2);
    }
  } else {
    usage(1);
  }

  return 0;
}