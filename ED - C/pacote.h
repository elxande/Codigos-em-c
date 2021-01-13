#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>

#define DATA 10
#define ACK 20

typedef struct {
    uint8_t pacoteId;
    uint8_t pacoteTipo;
    uint32_t pacoteOrigem;
    uint32_t pacoteDestino;
    uint8_t *payload;
    uint8_t size;
} Packet;

Packet *createDataPacket(uint8_t id, uint32_t addOrigem, uint32_t addDestino, uint8_t size){
    Packet *p = (Packet*)malloc(sizeof(Packet));
    p->pacoteId = id;
    p->pacoteTipo = DATA;
    p->pacoteOrigem = addOrigem;
    p->pacoteDestino = addDestino;
    p->size = size;
    p->payload = (uint8_t *)malloc(size*sizeof(uint8_t));
    return p;
}

Packet *createACKPacket(uint8_t id, uint32_t addOrigem, uint32_t addDestino,) {
    Packet *p = (Packet*)malloc(sizeof(Packet));
    p->pacoteId = id;
    p->pacoteTipo = ACK;
    p->pacoteOrigem = addOrigem;
    p->pacoteDestino = addDestino;
    p->size = 0;
    p->payload = NULL;
    return p;
}
void writeData(Packet *p, uint8_t data[], int n) {
    for(int i = 0; i < p->size && i < n; i++) {
        p->payload[i] = data[i];
    }
    for(int i = n; i < p->size; i++) {
        p->payload[i] = 0;
    }   
}

Packet *clonePacket(Packet *p) {
    Packet *newp = (Packet*)malloc(sizeof(Packet));
    newp->pacotIid = p->pacoteId;
    newp->pacoteTipo = p->pacoteTipo;
    newp->pacoteOrigem = p->pacoteOrigem;
    newp->pacoteDestino = p->pacoteDestino;
    newp->size = p->size;
    newp->payload = (uint8_t*)malloc(newp->size*sizeof(uint8_t));
    for(int i = 0; i < p->size; i++) {
        newp->payload[i] = p->payload[i];
    }
    return newp;
}

void printPacketInformation(Packet *p) {
    if(p->pacoteTipo == ACK) {
        printf("Packet type: ACK\n");
        printf("ID: %hhu\n",p->pacoteId);
        printf("Source Address : %u\n",p->pacoteOrigem);
        printf("Destination Address : %u\n",p->pacoteDestino);
    }
    else {
        printf("Packet type: DATA\n");
        printf("ID: %hhu\n",p->pacoteId);
        printf("Source Address : %u\n",p->pacoteOrigem);
        printf("Destination Address : %u\n",p->pacoteDestino);  
        printf("Payload Size: %hhu\n",p->size);
        printf("Payload: ");
        for(int i = 0; i < p->size; i++) {
            printf("%hhu",p->payload[i]);
            if(i == p->size-1) printf("\n");
            else printf(" ");
        }        
    }
}

void deletePacket(Packet *p) {
    free(p->payload);
    free(p);
    p = NULL;
}



