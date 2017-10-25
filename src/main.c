
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "circbuff.h"
#include "uart.h"
#include "debug.h"



int main(){
  
  /*#ifdef PROJECT2
 project2();
 #endif*/

 CB_t userbuff;
 uint8_t size = 16;
 CB_status status = 0;
 status = CB_init(&userbuff,size);
 printf("initialize status: %d\n",status);
 
 uint8_t data = 'a';
 status = CB_buffer_add_item(&userbuff,data);
 printf("add status: %d\n", status);
 printf("count: %d\n", userbuff.count);


 
for(uint8_t y=1; y<=12; y++)
 {
   status = CB_buffer_add_item(&userbuff,y);
   printf("add status: %d\n", status);
   printf("count: %d\n", userbuff.count);
 }

  for(uint8_t x=0; x<=15; x++)
 {
   status = CB_buffer_remove_item(&userbuff,userbuff.poppedData);
   printf("remove status: %d  |  removed data: %0x \n", status, *userbuff.poppedData);
   printf("count: %d\n", userbuff.count);
 }
 

   for(uint8_t y=1; y<=13; y++)
 {
   status = CB_buffer_add_item(&userbuff,y);
   printf("add status: %d\n", status);
      printf("count: %d\n", userbuff.count);
 }

  
   
 printf("\nBuffer Contents\n");

 print_memory(userbuff.circbuff, size);

 CB_peek(&userbuff,1,userbuff.poppedData);
 printf("peeked data: %0x\n",*userbuff.poppedData);
 
 printf("headptr address: %p \n",userbuff.headptr);
 printf("tailptr address: %p \n",userbuff.tailptr);
  return 0;
}




