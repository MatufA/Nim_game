#include <stdio.h>
#include <string.h>

int firstDecision(int *array);
int findMax(int array[]);
int find(int *array, int numberToFind);
int draw(int input);
//First decesion
int firstDecision(int *array){
    int packets[3] , pack , newPack ,replace;

    for (int i = 0; i < 3 ; i++) {
       packets[i] = array[i];
    }
    int biggest = findMax(packets);
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
         if(packets[biggest] == packets[(biggest+1)%3] + packets[(biggest + 2)%3]){
             return 1;
         }else{
             return -1;
         }
}
//Find max
int findMax(int array[]){
     int biggest = 0;
     if (array[0] <= array[1]){
         biggest = 1;
     }
      if (array[biggest] <= array[2]){
         biggest = 2;
     }
     return biggest;
}
//Find a number
int find(int *array, int numberToFind){
    int *numInArray = array;
     for(int i = 0; i < 3 ; i++){
         if (*(numInArray+i) == numberToFind){ 
             return i; 
         }
     }
     return -1;
}
//Check input
int draw(int input){
     if(input > 0){
         return 1;
     }
     return -1;
}