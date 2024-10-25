#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/pstat.h"

struct pstat pinfo;
int main(int argc, char *argv[]){
    getpinfo(&pinfo);
    int i = 0;
    if (pinfo.inuse[i] > 0){
    for (int i=0; i < NPROC; i++){
        printf("%d\n", pinfo.ticks[i]);
        printf("%d\n", pinfo.tickets[i]);
        }
    }
}