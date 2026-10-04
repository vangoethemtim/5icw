#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char marker[8];          // "CHEATLAB"
    uint32_t start_health;   // 100
    uint32_t start_ammo;     // 10
    uint32_t start_gold;     // 250
    uint32_t gun_damage;     // 15
    uint32_t enemy_health;   // 60
} GameConfig;

/*
 * Zoek in de EXE naar ASCII: CHEATLAB
 *
 * Daarna volgen de waarden als 32-bit little-endian integers.
 */
volatile GameConfig config = {
    {'C','H','E','A','T','L','A','B'},
    100,
    10,
    250,
    15,
    60
};

int main(void)
{
    int health = config.start_health;
    int ammo = config.start_ammo;
    int gold = config.start_gold;
    int enemy = config.enemy_health;
    int enemies_defeated = 0;

    srand((unsigned int)time(NULL));

    printf("===========================\n");
    printf("       HEX ARENA\n");
    printf("===========================\n\n");

    while (health > 0 && enemies_defeated < 3) {

        printf("\nEnemy %d/3\n", enemies_defeated + 1);
        printf("---------------------------\n");
        printf("Health: %d\n", health);
        printf("Ammo:   %d\n", ammo);
        printf("Gold:   %d\n", gold);
        printf("Enemy:  %d HP\n\n", enemy);

        printf("1. Shoot\n");
        printf("2. Buy ammo (50 gold)\n");
        printf("3. Buy medkit (100 gold)\n");
        printf("4. Run away\n");
        printf("> ");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {

            if (ammo <= 0) {
                printf("CLICK! No ammo.\n");
                continue;
            }

            ammo--;

            printf("You shoot for %u damage!\n", config.gun_damage);
            enemy -= config.gun_damage;

            if (enemy <= 0) {
                printf("\n*** ENEMY DEFEATED ***\n");

                enemies_defeated++;
                gold += 75;

                if (enemies_defeated < 3)
                    enemy = config.enemy_health;

                continue;
            }

            int enemy_damage = 8 + rand() % 8;

            printf("Enemy hits you for %d damage!\n", enemy_damage);
            health -= enemy_damage;
        }

        else if (choice == 2) {

            if (gold >= 50) {
                gold -= 50;
                ammo += 5;
                printf("Bought 5 bullets.\n");
            } else {
                printf("Not enough gold.\n");
            }
        }

        else if (choice == 3) {

            if (gold >= 100) {
                gold -= 100;
                health += 30;
                printf("Used medkit. +30 HP.\n");
            } else {
                printf("Not enough gold.\n");
            }
        }

        else if (choice == 4) {
            printf("You escaped.\n");
            return 0;
        }
    }

    if (health <= 0) {
        printf("\n===========================\n");
        printf("         GAME OVER\n");
        printf("===========================\n");
    } else {
        printf("\n===========================\n");
        printf("          YOU WIN!\n");
        printf("===========================\n");

        printf("Final gold: %d\n", gold);
    }

    return 0;
}