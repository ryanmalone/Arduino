

// client.pde
//

// need to add a real time clock module/function

// Simple example of how to use VirtualWire to send and receive messages
// with a DR3100 module.
// Send a message to another arduino running the 'server' example, which
// should send a reply, which we will check
//
// See VirtualWire.h for detailed API docs
// Author: Mike McCauley (mikem@airspayce.com)
// Copyright (C) 2008 Mike McCauley
// $Id: client.pde,v 1.1 2008/04/20 09:24:17 mikem Exp $

//#include <Time.h>
#include <VirtualWire.h>
// time sync to PC is HEADER and unix time_t as ten ascii digits
//#define TIME_MSG_LEN  11   
// Header tag for serial time sync message
//#define TIME_HEADER  255   

///
/// VARIABLES
///

//For counting number of times the magnet passes the reed switch
unsigned long rotationCount = 0; 
// Message Count
unsigned long msgSequenceCount = 0;
// Set client ID so server knows which bike message is being sent from.
int clientId = 1;
// Message to send
char currentRotationsMsg[21];

char* MesgPrefix = "##BM##";


void setup()
{ 
    Serial.begin(9600); // Debugging only
    Serial.println("setup");
    // Initialise the IO and ISR
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);      // Bits per sec
    vw_rx_start();       // Start the receiver PLL running
    
    
    
    // Configure reed switch to push to interrupt
    digitalWrite(2, HIGH); //Enable pullup
    attachInterrupt(1, rising, RISING);
    
    // Setup rotation counter
  //  count = 0 ;
  
    
    
    
}
void loop()
{
  
    
 
    
   // sprintf(currentRotationsMsg, "%d,%d,%d,%d,", 1, 2, 3, 4);
    sprintf(currentRotationsMsg, "%s,%d,%lu,%lu", MesgPrefix, clientId, msgSequenceCount, rotationCount);
    
    
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    digitalWrite(13, true); // Flash a light to show transmitting
    vw_send((uint8_t *)currentRotationsMsg, strlen(currentRotationsMsg));
    vw_wait_tx(); // Wait until the whole message is gone
    Serial.print("Sent: ");
    Serial.println(currentRotationsMsg);
     Serial.print("Count: ");
    Serial.println(rotationCount);
    digitalWrite(13, false);
    msgSequenceCount++ ;
    delay(100);
        
}

void rising()
{
 static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  // If interrupts come faster than 10ms, assume it's a bounce and ignore
  if (interrupt_time - last_interrupt_time > 30)
  {
    rotationCount++;
  }
  last_interrupt_time = interrupt_time;
}


