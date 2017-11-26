#include <stdio.h>
#include <string.h>
#include "play_h.h"

int main(){
     int biggest , replace, pack, newPack , gameOver = 1;
     int packets[3];
     
     printf("Please enter three number:\n");
     scanf("%d %d %d" , &packets[0], &packets[1], &packets[2]);
    
     if(packets[0] ==0 || packets[1] == 0 || packets[2] == 0 ){
         printf("You can't pick zero!\nPlease enter three number:\n");
         scanf("%d %d %d" , &packets[0], &packets[1], &packets[2]);
     }
     
     printf("packet sizes are: %d %d %d\n", packets[0], packets[1], packets[2]);

     int firstPlay = firstDecision(packets);
    
     while(gameOver > 0){
         if (firstPlay > 0){
             if(packets[0] + packets[1] + packets[2] == 1){
                 printf("You lost - Computer win\nGAME OVER!");
                 return 0;
                }
            
             printf("Your turn\nPlease state how much to take: \n");
             scanf("%d to %d", &pack, &newPack);
             
             replace = find(packets,pack);
             
             while(replace == (-1)){
                 char errorMessage[55];
                 (replace == (-1) && draw(newPack) < 0) ? strcpy(errorMessage, "Packet not found and you most draw from the packets") : 
                 (replace == (-1)) ?  strcpy(errorMessage , "Packet not found") : strcpy(errorMessage , "You most draw from the packets");
                 printf("%s, choose again: \n", errorMessage);
                 scanf("%d to %d" ,&pack, &newPack);
                 replace = find(packets,pack);
                 }
            
             packets[replace] = newPack;
             firstPlay = -1;
         
         }else if(firstPlay < 0){
                  if(packets[0] + packets[1] + packets[2] == 1){
                  printf("Computer lost - You win\nGAME OVER!");
                  return 0;
                 }
             biggest = findMax(packets);
             // X > 1  
             if(packets[biggest] > 1){
             //X 0 0
                 if(packets[(biggest+1)%3] + packets[(biggest+2)%3] == 0){
                     pack =  packets[biggest];
                     packets[biggest] =1;
                     printf("I turned %d to %d\nPacket sizes are now:\n%d %d %d\nGame Over - You Lost!", pack, packets[biggest], packets[0], packets[1], packets[2]);
                     return 0;
             //X 1 0
             }else if( packets[(biggest+1)%3] + packets[(biggest+2)%3] == 1){
                 pack =  packets[biggest];
                 packets[biggest] =0;
                 printf("I turned %d to %d\nPacket sizes are now:\n%d %d %d\nGame Over - You Lost!", pack, packets[biggest], packets[0], packets[1], packets[2]);
                 return 0;
             //X 1 1
             }else if(packets[(biggest+1)%3] == 1 && packets[(biggest+2)%3] == 1){
                 pack =  packets[biggest];
                 packets[biggest] =1;
                 printf("I turned %d to %d\nPacket sizes are now:\n%d %d %d\n", pack, packets[biggest], packets[0], packets[1], packets[2]);
                 //1 1 1
                 printf("Your turn\nPlease state how much to take: \n");
                 scanf("%d to %d", &pack, &newPack);
                 
                 replace = find(packets,pack);
                 
                 while(replace == (-1) && draw(newPack)){
                 char errorMessage [60];
                 (replace == (-1) && draw(newPack) < 0) ? strcpy(errorMessage, "Packet not found and you most draw from the packets") : (replace == (-1)) ?  strcpy(errorMessage , "Packet not found") : strcpy(errorMessage , "You most draw from the packets");
                 printf("%s, choose again: \n", errorMessage);
                 scanf("%d to %d" ,&pack, &newPack);
                 replace = find(packets,pack);
                 }
                 
                 packets[replace] = newPack;
                 //0 1 1
                 packets[2] =0;
                 printf("I turned %d to %d\nPacket sizes are now:\n%d %d %d\nGame Over - You Lost!", 1, 0, packets[0], packets[1], packets[2]);
                 return 0;
                 }
             }
             
             pack =  packets[biggest];
             packets[biggest]  = packets[(biggest+1)%3] - packets[(biggest+2)%3];
             if(packets[biggest] < 0){
                 packets[biggest] *= (-1);
                 }
                 printf("I turned %d to %d\nPacket sizes are now:\n%d %d %d\n", pack,  packets[biggest], packets[0], packets[1], packets[2]);
            
            firstPlay = 1;
         }
     } 
 return 0;   
}
