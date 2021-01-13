#include "packet.h"
#include <stdio.h>

int main() {
    Packet *p1 = createDataPacket(1, 10, 20, 10);
    Packet *p2 = createACKPacket(1, 20, 10);
    uint8_t data[8] = {1,2,3,4,5,6,7,8};
    writeData(p1, data, 8);
    Packet *p3 = clonePacket(p1);
    uint8_t data2[8] = {8,7,6,5,4,3,2,1};
    writeData(p3, data2,8);
    printPacketInformation(p1);
    printPacketInformation(p2);
    printPacketInformation(p3);
    deletePacket(p1);
    deletePacket(p2);
    deletePacket(p3);
    return 0;
}