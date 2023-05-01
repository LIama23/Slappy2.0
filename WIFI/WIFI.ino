
//Wifi code für Arduino 1

#include <RF24.h>
#include <RF24Network.h>
#include <SPI.h>

RF24 radio(10, 9);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
 
const int this_node = 00;   // Address of this node in Octal format ( 04,031, etc)
const int node01 = 01;      
bool zustand_1 = false;
bool zustand_2 = false;
bool zustand_3 = false;
bool zustand_4 = false;
bool zustand_5 = false;

void setup() 
{

  SPI.begin();
  radio.begin();
  network.begin(90, this_node);  //(channel, node address)
}

void loop() 
{
  network.update();
  int test_1 = 23;
  int test_2[] = {23,34,45};
  RF24NetworkHeader header(node01);     // (Address where the data is going)
  bool ok = network.write(header, &test_1, sizeof(test_1)); // Send the data
}