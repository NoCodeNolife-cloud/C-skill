#include <stdio.h>

union to{
    unsigned short int value;
    unsigned char byte[2];
};

int main(int argc,char*argv[]){
    to typeorder;
    typeorder.value=0xabcd;
    if(typeorder.byte[0]==0xcd&&typeorder.byte[1]==0xab){
        printf("Low endian byte order bete[0]:0x%x,byte[1]:0x%x\n",typeorder.byte[0],typeorder.byte[1]);
    }

    if(typeorder.byte[0]==0xab&&typeorder.byte[1]==0xcd){
        printf("High endian byte order bete[0]:0x%x,byte[1]:0x%x\n",typeorder.byte[0],typeorder.byte[1]);
    }
}