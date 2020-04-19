#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "../include/interface.h"
#include "../include/Controller.h"

int main(){

  int exitcode=runController();
  if(exitcode) perror("ERRO!");
  return exitcode;    
}
