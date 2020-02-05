#include <stdio.h>
#include <stdbool.h>

#define TABSTOPS 10

bool openFiles(int argc, const char* argv[], FILE**fin, FILE**fout, int* tabstops, const char*usage){
  if(argc != 3 && argc != 4) {
    fprintf(stderr , "%s\n", usage);
    return false;
  }
  *fin = fopen(argv[1] , "r");
  if(*fin == NULL){
    return false;
  }
  *fout = fopen(argv[2], "w");
  if(*fout == NULL){
    return false;
  }
  *tabstops = argc == 4 ? atoi(argv[3]) : TABSTOPS;
  return true;
}

void closeFiles(FILE *fin, FILE *fout){
  fclose(fin);
  fclose(fout);
}
