#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/if_ether.h>
#include <net/if.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

struct arppacket {

    unsigned short ar_hrd;
    unsigned short ar_pro;
    unsigned char ar_hln;
    unsigned char ar_pln;
    unsigned short ar_op;
    unsigned char ar_sha[ETH_ALEN];
    unsigned char *ar_sip;
    unsigned char ar_tha[ETH_ALEN];
    unsigned char *ar_tip;
};

int main(int argc, char *argv[]) {

    char ef[ETH_FRAME_LEN];
    ethhdr *p_ethhdr;
    char eth_dest[ETH_ALEN] = {(char) 0xFF, (char) 0xFF, (char) 0xFF, (char) 0xFF, (char) 0xFF, (char) 0xFF};
    char eth_source[ETH_ALEN] = {0x00, 0x0C, 0x29, 0x73, (char) 0x9D, 0x15};

    int fd;
    fd = socket(AF_INET, SOCK_PACKET, htons(0x0003));
    p_ethhdr = (ethhdr *) ef;
    memcpy(p_ethhdr->h_dest, eth_dest, ETH_ALEN);
    memcpy(p_ethhdr->h_source, eth_source, ETH_ALEN);
    p_ethhdr->h_proto = htons(0x0806);

    arppacket *p_arp;
    p_arp = (arppacket *) ef + ETH_HLEN;
    p_arp->ar_hrd = htons(0x1);
    p_arp->ar_pro = htons(0x0800);
    p_arp->ar_hln = 6;
    p_arp->ar_pln = 4;

    memcpy(p_arp->ar_sha, eth_source, ETH_ALEN);
    p_arp->ar_sip = (unsigned char *) inet_addr("192.168.1.152");
    memcpy(p_arp->ar_tha, eth_dest, ETH_ALEN);
    p_arp->ar_tip = (unsigned char *) inet_addr("192.168.1.1");

    int i = 0;
    for (i = 0; i < 8; i++) {
        write(fd, ef, ETH_FRAME_LEN);
        sleep(1);
    }
    close(fd);
    return 0;
}