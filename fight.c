#include <stdio.h>
#include <stdlib.h>
#include "boxeador.h"

int option;

// Function to simulate a fight between two boxers
void fight(boxeador *box1, boxeador *box2) {
    box1->life = 3;
    box2->life = 3;

    while (box1->life > 0 && box2->life > 0) {
        // Display the life of both boxers
        printf("LIFE: ");
        for (int i = 0; i < box1->life; i++) {
            printf("S ");
        }
        printf("\n");

        printf("OPPONENT: ");
        for (int i = 0; i < box2->life; i++) {
            printf("S ");
        }
        printf("\n");

        // Menu of options for the player (boxer 1)
        printf("1. ATTACK\n");
        printf("2. DEFEND\n");
        printf("3. DODGE\n");
        scanf("%d", &option);

        int box1_action = option;  // Player's action (boxer 1)

        // Boxer 2 (computer) chooses an action randomly
        int box2_action = rand() % 3;

        // Boxer 1's action
        if (box1_action == 1) {
            box2->life--;
            printf("%s attacked! %s lost 1 life.\n", box1->name, box2->name);
        } else if (box1_action == 2) {
            printf("%s defended himself!\n", box1->name);
        } else if (box1_action == 3) {
            printf("%s dodged!\n", box1->name);
        } else {
            printf("Invalid option. Try again.\n");
            continue;  // Skip this turn and ask for a new action
        }

        // Boxer 2's action (computer)
        if (box2->life > 0) {
            if (box2_action == 0) {
                box1->life--;
                printf("%s attacked! %s lost 1 life.\n", box2->name, box1->name);
            } else if (box2_action == 1) {
                printf("%s defended himself!\n", box2->name);
            } else {
                printf("%s dodged!\n", box2->name);
            }
        }

        // Check for simultaneous attacks (when both attack at the same time)
        if (box1_action == 1 && box2_action == 0) {
            // Both attacked. Since they are attacking opposite sides, both lose 1 life
            box1->life--;
            box2->life--;
            printf("Both players attacked! %s and %s lost 1 life.\n", box1->name, box2->name);
        }

        
        printf("\nPress ENTER for next turn...\n");
        getchar();  // Clear the keyboard buffer
        getchar();  // Wait for the user to press ENTER

        // Check winner
        if (box1->life <= 0) {
            printf("\n%s wins!\n", box2->name);
            break;
        } else if (box2->life <= 0) {
            printf("\n%s wins!\n", box1->name);
            break;
        }
    }
}
