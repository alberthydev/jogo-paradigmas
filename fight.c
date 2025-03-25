#include <stdio.h>
#include "boxeador.h"

//function to simulate a fight between two boxers
void fight(boxeador *box1, boxeador *box2){
    box1->life = 3;
    box2->life = 3;

    while(box1->life > 0 && box2->life > 0){
        printf("LIFE: ");
        for(int i = 0; i < box1->life; i++){
            printf("S2 ");
        }
        printf("\n");

        printf("OPPONENT: ");
        for(int i = 0; i < box2->life; i++){
            printf("S2 ");
        }
        printf("\n");

        //menu of options
        printf("1. ATTACK\n");
        printf("2. DEFEND\n");
        printf("3. DODGE\n");

        int option;
        scanf("%d", &option);

        switch(option){
            case 1:
                box2->life--;
                break;
            case 2:
                box1->life;
                break;
            case 3:
                return fight(box2, box1);
                break;
        }
    }
}