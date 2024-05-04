#ifndef UTILS_H_
#define UTILS_H_

#define MAX_MONSTERS 32
#define MAX_LEN 128

#define FILTER_NAME 1
#define FILTER_HP 2
#define FILTER_AC 3
#define FILTER_STATS 4
#define EXIT_CHOICE 5

void swap_int(int, int);
void trim(char *);
int load_monster_csv(monster_s **, FILE *);

#endif
