#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[]){
    int tests_to_run = 10;
    printf("Starting Priority Scheduler Testing. Two tests will run in sequence.\n Both tests will use 'H' and 'L'  to indicate High and Low priority processes.\n");
    printf("Both tests will run for %d iterations.\n", tests_to_run);
    printf("First test: Expected outcome all 'H' then all 'L' characters printed to console.\n");
    
    ////////////////////////////////////////////////////// First Test //////////////////////////////////////////////////////
    int pid1 = fork();
    if (pid1 == 0) {
        set_priority(5);  // High priority
        sleep(2);  // Let low priority process start first and begin running
        for(int i = 0; i < tests_to_run; i++){
            printf("H");
        }
        exit(0);
    }
   
    int pid2 = fork();
    if (pid2 == 0){
        set_priority(95);  // Low priority  
        sleep(1);  // Start before high priority process
        for(int i = 0; i< tests_to_run * 10; i++){
            printf("L");
        }
        exit(0);
    }
    // wait between tests
    wait(0);
    wait(0);
    
    printf("\nFirst test complete. Expected: all 'H' then all 'L' characters.\n");
    printf("\n////////////////////////////////////////////////////\n");
    printf("Second test: Expected outcome is 'L' characters being interrupted immediately by 'H' once the user defined number of tests runs.\n");

    //////////////////////////////////////////////////////// Second Test //////////////////////////////////////////////////////
    int pid3 = fork();
    if (pid3 == 0){
        set_priority(95); 
        for(int i = 0; i < tests_to_run * 10; i ++){
            printf("L2");
        }
        exit(0);
    }
    int pid4 = fork();
    if (pid4 == 0){
        set_priority(5);
        for(int i = 0; i< tests_to_run; i++){
            printf("H2");
        }
        exit(0);
    }     
    // wait for test to complete
    wait(0);
    wait(0);
    printf("\nSecond test complete. Expected: L2 running, then H2 interrupt, then complete L2.\n");
    exit(0);
}