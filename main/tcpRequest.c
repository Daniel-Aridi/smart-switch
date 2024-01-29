/****************************************************
    managing incoming requests of type proto messages
    initiating secure sessions 
    defining control signals
*****************************************************/

#include <stdio.h>
#include <string.h>
#include "esp_log.h"

#include "tcpIp.h"
#include "IOC.h"
#include "utils.h"
#include "tcpRequest.h"
#include "TCPRequest.pb-c.h"

#define NEW_SECURITY_SESSION 0
#define SWITCH_RELAY_REQUEST 1
#define PAYLOAD_DATA 2

#define keySize 32

const char *turnRelayOneOn = "TurnON";
const char *turnRelayOneOff = "TurnOFF";
TCPMESSAGE__Payload *deserializedMessage;
uint8_t clientPublicKey[keySize];

void print_array(uint8_t *array, int length){

    for(int i = 0; i < length; i++){
        printf("%02X ", array[i]);
    }
    printf("\n");
}

//NOTE: Check for null 


void manage_request(const int sock){

    

    deserializedMessage = tcp__message__payload__unpack(NULL, len, rx_buffer);
    

    if(deserializedMessage == NULL){
        
    }
    
    

    if(deserializedMessage->type == NEW_SECURITY_SESSION){
        printf("a new security session is requested\n");

        ProtobufCBinaryData PublicKey = deserializedMessage->sec1->sc0->client_pubkey;
        memcpy(clientPublicKey, PublicKey.data, keySize);
        print_array(clientPublicKey, keySize);
    }

    if(deserializedMessage->type == SWITCH_RELAY_REQUEST){

       set_relay_state(deserializedMessage->relaynumber, deserializedMessage->relaystate);
    }

    printf("message type: %d, data: %s\n", deserializedMessage->type, deserializedMessage->stringdata);

    
    tcp__message__payload__free_unpacked(deserializedMessage, NULL);

}

