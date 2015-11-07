//******************************************************************************
//  MSP-FET430P140 Demo - DMA0, Repeated Burst to-from RAM, Software Trigger
//
//  Description: A 16 word block from 220h-240h is transfered to 240h-260h
//  using DMA0 in a burst block using software DMAREQ trigger.
//  After each transfer, source, destination and DMA size are
//  reset to inital software setting because DMA transfer mode 5 is used.
//  P1.0 is toggled durring DMA transfer only for demonstration purposes.
//  * RAM location 0x220 - 0x260 used - always make sure no compiler conflict *
//  ACLK = n/a, MCLK = SMCLK = default DCO ~ 800k
//  //* MSP430F169 Device Required *//
//
//               MSP430F169
//            -----------------
//        /|\|              XIN|-
//         | |                 |
//         --|RST          XOUT|-
//           |                 |
//           |             P1.0|-->LED
//
//  M. Buccini
//  Texas Instruments Inc.
//  Feb 2005
//  Built with CCE Version: 3.2.0 and IAR Embedded Workbench Version: 3.21A
//******************************************************************************

#include  <msp430x16x.h>

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog
  unsigned int i=0 ;
  //unsigned int j=0;
  //unsigned int z=0;
 // unsigned char temp=0x00 ;
  
// #pragma location=0x0200 
//  __no_init static char data[5];
  __no_init  static unsigned char data[96] @ 0x0200 ;
//  P2DIR = 0xff;
  
 // P1DIR |= 0x01;                            // P1.0  output
  DMA0SA = 0x0200;                          // Start block address
  DMA0DA = 0x0090;                          // Destination block address
  DMA0SZ = 0x0020;                           // Block size
 
  
  DMA0CTL = DMADT_0 + DMASRCINCR_3 + DMADSTINCR_3 + DMAEN; // Rpt, inc SRC, DST 单信号传输，源地址自加，目的地址不变

  for (;;)                                  // Repeat
  {
	for(i=0;i<96;i++)
     {
       data[i]=i;
     }
     
//     for(z=0; z<4; z++)
//     {
//        for(j=8*z; j<(8*z+8); j++)
//       {
//          P2OUT=data[j];
//        }
//     }
	 
//    P1OUT |= 0x01;                          // Set P1.0 (LED on)
    DMA0CTL |= DMAREQ;                      // Trigger block transfer
//    P1OUT &= ~0x01;                         // Clear P1.0 (LED off)
  }
}


////******************************************************************************
////  MSP-FET430P140 Demo - DMA0, Repeated Burst to-from RAM, Software Trigger
////
////  Description: A 16 word block from 220h-240h is transfered to 240h-260h
////  using DMA0 in a burst block using software DMAREQ trigger.
////  After each transfer, source, destination and DMA size are
////  reset to inital software setting because DMA transfer mode 5 is used.
////  P1.0 is toggled durring DMA transfer only for demonstration purposes.
////  * RAM location 0x220 - 0x260 used - always make sure no compiler conflict *
////  ACLK = n/a, MCLK = SMCLK = default DCO ~ 800k
////  //* MSP430F169 Device Required *//
////
////               MSP430F169
////            -----------------
////        /|\|              XIN|-
////         | |                 |
////         --|RST          XOUT|-
////           |                 |
////           |             P1.0|-->LED
////
////  M. Buccini
////  Texas Instruments Inc.
////  Feb 2005
////  Built with CCE Version: 3.2.0 and IAR Embedded Workbench Version: 3.21A
////******************************************************************************
//
//#include  <msp430x16x.h>
//
//void main(void)
//{
//  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog
//  
//  unsigned int i=0 ;
//                           // P1.0  output
//  __no_init  static unsigned char data[32] @ 0x0200 ;  
//  DMA0SA = 0x0200;                          // Start block address
//  DMA0DA = 0x0300;                          // Destination block address
//  DMA0SZ = 0x0020;                           // Block size
//  
//  DMA1SA = 0x0400;                          // Start block address
//  DMA1DA = 0x0500;                          // Destination block address
//  DMA1SZ = 0x0020;                           // Block size
//  
//  DMA2SA = 0x0600;                          // Start block address
//  DMA2DA = 0x0700;                          // Destination block address
//  DMA2SZ = 0x0020;                           // Block size
//  
//  DMACTL1 = ROUNDROBIN;
//  
//  DMA0CTL = DMADT_0 + DMASRCINCR_3 + DMADSTINCR_3 + DMAEN; // Rpt, inc SRC, DST
//  DMA1CTL = DMADT_0 + DMASRCINCR_3 + DMADSTINCR_3 + DMAEN; // Rpt, inc SRC, DST
//  DMA2CTL = DMADT_0 + DMASRCINCR_3 + DMADSTINCR_3 + DMAEN; // Rpt, inc SRC, DST
//
//  for (;;)                                  // Repeat
//  {
//    for(i=0;i<=31;i++)
//     {
//       data[i]=i;
//     }                
//    
//    DMA2CTL |= DMAREQ;                      // Trigger block transfer
//    DMA1CTL |= DMAREQ;                      // Trigger block transfer
//    //DMA0CTL |= DMAREQ;                      // Trigger block transfer
//    
//  }
//}
