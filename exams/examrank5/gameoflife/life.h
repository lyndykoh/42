#ifndef LIFE_H
#define LIFE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_game
{
    int width;
    int height;
    int iter;
    int i;
    int j;
    int draw;
    char alive;
    char dead;
    char **board;
} t_game;

int initgame(t_game *game, char *argv[]);
void fillboard(t_game *game);
void freeboard(t_game *game);
void printboard(t_game *game);
int play(t_game *game);
int countneighbours(t_game *game, int i, int j);

#endif