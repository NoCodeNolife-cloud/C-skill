#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    struct in_addr ip, local, network;
    char addr1[] = "192.168.1.1";//a.v.c.d type net address string
    char addr2[] = "255.255.255.255";//binary values are all one
    char addr3[] = "192.16.1";//type of a.b.c network address
    char *str = NULL, *str2 = NULL;

    int err = 0;
    //test function inet_aton
    err=inet_aton(addr1,&ip);
    if(err){
        printf("inet_aton:string %s value is:0x%x\n",addr1,ip.s_addr);
    }else{
        printf("inet_aton:string %s error\n",addr1);
    }
    //inet_addr, firstly test 192.168.1.1, then test 255.255.255.255
    ip.s_addr=inet_addr(addr1);
    if(err!=-1){
        printf("inet_addr:string %s value is:0x%x\n",addr1,ip.s_addr);
    }else{
        printf("inet_addr:string %s error\n",addr1);
    }
    ip.s_addr= inet_addr(addr2);
    if(ip.s_addr!=-1){
        printf("inet_addr:string %s value is:0x%x\n",addr2,ip.s_addr);
    }else{
        printf("inet_addr:string %s error\n",addr2);
    }

    //inet_ntoa, firstly test 192.168.1.1, then test 255.255.255.255
    ip.s_addr=192<<24|168<<16|1<<8|1;
    str=inet_ntoa(ip);
    ip.s_addr=255<<24|255<<16|255<<8|255;
    str2= inet_ntoa(ip);
    printf("inet_ntoa:0x%x string %s,pre is:%s \n",ip.s_addr,str2,str);

    //test function inet_addr
    ip.s_addr= inet_addr(addr3);
    if(err!=-1){
        printf("inet_addr:string %s value is:0x%x\n",addr3,ip.s_addr);
    }else{
        printf("inet_addr:string %s error\n",addr3);
    }
    str=inet_ntoa(ip);
    printf("inet_ntoa:string %s ip:0x%x \n",str,ip.s_addr);

    //test function of inet_lnaof, get the local address
    inet_aton(addr1,&ip);
    local.s_addr=htonl(ip.s_addr);
    local.s_addr= inet_lnaof(ip);
    str= inet_ntoa(local);
    printf("inet_lnaof:string %s ip:0x%x\n",str,local.s_addr);

    //test function of inet_netof, get local address
    network.s_addr=inet_netof(ip);
    printf("inet_netof:value:0x%x \n",network.s_addr);

    return 0;
}