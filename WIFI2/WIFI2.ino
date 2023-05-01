//Wifi Code für Arduino 2

#include <RF24.h>
#include <RF24Network.h>
#include <SPI.h>

RF24 radio(10, 9);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
  
const int this_node = 01;   // Address of our node in Octal format ( 04,031, etc)
const int node00 = 00;     
bool zustand_1 = false;
bool zustand_2 = false;
bool zustand_3 = false;
bool zustand_4 = false;
bool zustand_5 = false;


void setup() 
{

  SPI.begin();
  radio.begin();
  network.begin(90, this_node); //(channel, node address)
}

void loop() 
{
  network.update();
  while ( network.available() ) 
  {     // Is there any incoming data?
    RF24NetworkHeader header;
    int test_empfang_1;
    network.read(header, &test_empfang_1, sizeof(test_empfang_1)); // Read the incoming data
    printf("Test Empfang 1: ");
    printf(test_empfang_1);
    printf("\n");
  }
  
}