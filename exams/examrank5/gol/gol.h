#ifndef GOL_H
#define GOL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_game
{
    int height;
    int width;
    int iter;
    int i;
    int j;
    int draw;
    char alive;
    char dead;
    char **board;
} t_game;

int initgame(t_game *game, char *argv[]);
void freeboard(t_game *game);
void fillboard(t_game *game);
int play(t_game *game);
int countneighbours(t_game *game, int i, int j);
void printboard(t_game *game);

#endif