#include "gol.h"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        write(STDERR_FILENO, "Usage: ./life width height iterations\n", 38);
        return 1;
    }

    t_game game;
    if (initgame(&game, argv) == -1)
        return 1;
    fillboard(&game);
    for (int i = 0; i < game.iter; i++)
    {
        if (play(&game) == -1)
        {
            freeboard(&game);
            return 1;
        }
    }
    printboard(&game);
    freeboard(&game);
    return 0;
}

int initgame(t_game *game, char *argv[])
{
    game->width = atoi(argv[1]);
    game->height = atoi (argv[2]);
    game->iter = atoi(argv[3]);
    game->i = 0;
    game->j = 0;
    game->draw = 0;
    game->alive = '0';
    game->dead = ' ';
    game->board = malloc(game->height * sizeof(char *));
    if (!game->board)
        return -1;
    for (int i = 0; i < game->height; i++)
    {
        game->board[i] = malloc(game->width * sizeof(char));
        if (!game->board[i])
        {
            freeboard(game);
            return -1;
        }
        for (int j = 0; j < game->width; j++)
        {
            game->board[i][j] = ' ';
        }
    }
    return 0;
}

void fillboard(t_game *game)
{
    char buffer;
    int flag;

    while (read(STDIN_FILENO, &buffer, 1) == 1)
    {
        flag = 0;
        switch(buffer)
        {
            case 'w':
                if (game->i > 0)
                    game->i--;
                break;
            case 's':
                if (game->i < game->height - 1)
                    game->i++;
                break;
            case 'a':
                if (game->j > 0)
                    game->j--;
                break;
            case 'd':
                if (game->j < game->width - 1)
                    game->j++;
                break;
            case 'x':
                game->draw = !game->draw;
                break;
            default: 
                flag = 1;
                break;
        }
        if (game->draw && flag == 0)
        {
            if (game->i >= 0 && game->i < game->height && game->j >= 0 && game->j < game->width)
                game->board[game->i][game->j] = game->alive;
        }
    }
}

int play(t_game *game)
{
    char **temp = malloc(game->height * sizeof(char *));
    if (!temp)
        return -1;
    for (int i = 0; i < game->height; i++)
    {
        temp[i] = malloc(game->width * sizeof(char));
        if (!temp[i])
            return -1;
    }

    int neighbour;
    for (int i = 0; i < game->height; i++)
    {
        for (int j = 0; j < game->width; j++)
        {
            neighbour = countneighbours(game, i, j);
            if (game->board[i][j] == game->alive)
            {
                if (neighbour == 2 || neighbour == 3)
                    temp[i][j] = game->alive;
                else 
                    temp[i][j] = game->dead;
            }
            else 
            {
                if (neighbour == 3)
                    temp[i][j] = game->alive;
                else 
                    temp[i][j] = game->dead;
            }
        }
    }
    freeboard(game);
    game->board = temp;
    return 0;
}

int countneighbours(t_game *game, int i, int j)
{
    int count = 0;
    for (int di = -1; di < 2; di++)
    {
        for (int dj = -1; dj < 2; dj++)
        {
            if (di == 0 && dj == 0)
                continue;
            int ni = i + di;
            int nj = j + dj;
            if (ni >= 0 && ni < game->height && nj >= 0 && nj < game->width)
            {
                if (game->board[ni][nj] == game->alive)
                    count++;
            }
        }
    }
    return count;
}

void printboard(t_game *game)
{
    for (int i = 0; i < game->height; i++)
    {
        for (int j = 0; j < game->width; j++)
        {
            putchar(game->board[i][j]);
        }
        putchar('\n');
    }
}

void freeboard(t_game *game)
{
    if (game->board)
    {
        for (int i = 0; i < game->height; i++)
        {
            if (game->board[i])
                free(game->board[i]);
        }
        free(game->board);
    }
}