# include <stdio.h>

int main(int argc, char **argv){
  printf("Hello Harper!\n");

  char string[8] = "COMP2100";
  int size = sizeof(string);
  for(int i =0; i < 9; i++){
	printf("\n-------\n\n");
	printf("number %d character is %c\n", i, string[i]);
	printf("number %d character in decimal is %d\n", i, string[i]);
	printf("number %d character in octal is %o\n", i, string[i]);
	printf("number %d character in hex is %x\n", i, string[i]);
  };
  return 0;
}
