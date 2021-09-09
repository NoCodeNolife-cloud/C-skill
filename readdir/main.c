#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <csapp.h>

int main() {
    DIR *streamp;
    struct dirent *dep;

    streamp= opendir("./CMakeFiles");

    errno=0;
    while((dep= readdir(streamp))!=NULL){
        printf("Found file:%s\n",dep->d_name);
    }
    if(errno!=0){
        printf("readdir error");
    }

    closedir(streamp);
    return 0;
}
