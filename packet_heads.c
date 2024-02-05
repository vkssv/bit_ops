#include <stdio.h>
#include <pcap.h>

/*
struct pcap_if {
	struct pcap_if *next;
	char *name;		/* name to hand to "pcap_open_live()" 
	char *description;	textual description of interface, or NULL
	struct pcap_addr *addresses;
	bpf_u_int32 flags;	PCAP_IF_ interface flags
    };
*/


int main(int argc, char **argv) {
    char *device; /* Name of device (e.g. eth0, wlan0) */
    char error_buffer[PCAP_ERRBUF_SIZE]; /* Size defined in pcap.h */
    pcap_if_t* alldevsp;

    /* Find a device */
    if (pcap_findalldevs(&alldevsp, error_buffer)) {
        printf("Error finding device: %s\n", error_buffer);
        return 1;
    }


   

    printf("Network device found: %s\n", alldevsp->name);
    return 0;
}
