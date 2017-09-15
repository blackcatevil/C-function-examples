#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    FILE *fp;
    char cmd[64];
    char buf[64];
    char ip[16];
    char *p;

    if(argc != 2){
        printf("Usage: popen_v1 [ping ip]\n");
        return -1;
    }

    sprintf(ip, argv[1], sizeof(argv[1]));
    sprintf(cmd, "ping %s -c 1", ip);

    fp = popen(cmd, "r");
    if(fp < 0){
        printf("popen failed\n");
        return -1;
    }

    fgets(buf, sizeof(buf), fp);
    memset(buf, 0, sizeof(buf));

    for(;;){
        fgets(buf, sizeof(buf), fp);
        if('\n' == buf[0])
            continue;
       
        p = strstr(buf, "Unreachable");
        if (p != NULL){
            printf("%s is unreachable\n", ip);
        }
        else{
            printf("%s is reachable\n", ip);
        }
        break;
    }

    pclose(fp);
    return 0;
}
