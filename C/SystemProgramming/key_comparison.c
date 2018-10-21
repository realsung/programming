#include <stdio.h>
#include <string.h>

int main(){
    char buf[32];
    char key[] = "pr0gr4m_k3y";

    puts("input tha passphrase");
    fgets(buf,sizeof(buf),stdin);
    strtok(buf,"\n");

    if(!strcmp(buf,key)){
        puts("Congratulations!");
    }else{
        puts("Invalid input.");
    }

    return 0;
}