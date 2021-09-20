#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

#define ADDRLEN 16

int main(int argc, char *argv[]) {
    struct in_addr ip;
    char IPSTR[]="192.168.1.1";//network address
    char addr[ADDRLEN];//Save the converted string IP address,16 bytes
    const char*str=NULL;
    int err=0;

    //test function of inet_pton, convert 192.168.1.1 to binary format
    err= inet_pton(AF_INET,IPSTR,&ip);
    if(err>0){
        printf("inet_pton:ip,%s value is:0x%x\n",IPSTR,ip.s_addr);
    }

    //test function of inet_ntop to convert the 192.168.1.1 to string
    ip.s_addr=htonl(192<<24|168<<16|12<<8|255);//192.168.12.255
    //convert binary network order 192.168.12.255 to string
    str=(const char*) inet_ntop(AF_INET,(void*)&ip,(char*)&addr[0],ADDRLEN);
    if(str){
        printf("inet_ntop:ip,0x%x is %s\n",ip.s_addr,str);
    }

    return 0;


}