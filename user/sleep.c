#include <kernel/types.h>
#include <kernel/stat.h>
#include <user/user.h>

void print_usage(){
    printf("Usage: program <user input interger of ticks>\n");
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    print_usage();
    return 1;
  }
  int ticks;
  ticks = atoi(argv[1]);
  sleep(ticks);
  // Your code will go here
  exit(0);
}

// #include <stdio.h>

//#include <sleep.h>

// get current tickts
// initiate var for pause period let user define
// if argcount != 2 
    // printf("error will robinson");

// sys interupt for pause