#include <netdb.h>
#include <stdio.h>

//show the protocol program of function
void display_protocol(struct protoent *pt) {
    int i = 0;
    if (pt) {
        printf("protocol name:%s,", pt->p_name);
        if (pt->p_aliases[i]) {
            printf("alias name:");
            while (pt->p_aliases[i]) {
                printf("%s ", pt->p_aliases[i]);
                i++;
            }
        }
        printf(",value:%d\n", pt->p_proto);
    }
}

int main(int argc,char*argv[]){
    int i=0;
    const char *const protocol_name[]={
            "ip",
            "icmp",
            "igmp",
            "ggp",
            "ipencap",
            "st",
            "tcp",
            "egp",
            "igp",
            "pup",
            "udp",
            "hmp",
            "xns-idp",
            "rdp",
            "iso-tp4",
            "xtp",
            "ddp",
            "idpt-cmtp",
            "rdp",
            "iso-tp4",
            "xtp",
            "ddp",
            "idpr-cmtp",
            "ipv6",
            "ipv6-route",
            "ipv6-frag",
            "idrp",
            "revp",
            "gre",
            "esp",
            "ah",
            "skip",
            "ipv6-icmp",
            "ipv6-nonxt",
            "ipv6-opts",
            "repf",
            "vmtp",
            "eigrp",
            "ospf",
            "ax.25",
            "ipip",
            "etherip",
            "encap",
            "pim",
            "ipcomp",
            "vrrp",
            "12tp",
            "isis",
            "sctp",
            "fc",
            nullptr
    };

    setprotoent(1);
    while(protocol_name[i]!= nullptr){
        struct protoent *pt= getprotobyname((const char*)&protocol_name[i][0]);
        if(pt){
            display_protocol(pt);
        }
        i++;
    }
    endprotoent();
    return 0;
}