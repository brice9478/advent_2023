/*
** EPITECH PROJECT, 2023
** file in string
** File description:
** Reverse dressmaker
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int my_strlen(char const *str)
{
    int a = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        a++;
    }
    return (a);
}

void file_in_string(char **av)
{
    int fd = open(av[1], O_RDONLY);
    struct stat sfile;
    int count = 0;
    char *buffer;
    int dimensions;
    char *room;
    char *line;
    int first = 0;
    int last = 0;
    int total = 0;
    bool real_first = false;
    char **tab = malloc(sizeof(char *) * 11);
    int clone_count;
    int i = 0;
    int j = 0;
    int count_line = 0;
    bool real_last = false;
    bool only_one = false;

    tab[0] = malloc(sizeof(char) * 5);
    tab[1] = malloc(sizeof(char) * 4);
    tab[2] = malloc(sizeof(char) * 4);
    tab[3] = malloc(sizeof(char) * 6);
    tab[4] = malloc(sizeof(char) * 5);
    tab[5] = malloc(sizeof(char) * 5);
    tab[6] = malloc(sizeof(char) * 4);
    tab[7] = malloc(sizeof(char) * 6);
    tab[8] = malloc(sizeof(char) * 6);
    tab[9] = malloc(sizeof(char) * 5);

    tab[0] = "zero";
    tab[1] = "one";
    tab[2] = "two";
    tab[3] = "three";
    tab[4] = "four";
    tab[5] = "five";
    tab[6] = "six";
    tab[7] = "seven";
    tab[8] = "eight";
    tab[9] = "nine";
    stat(av[1], &sfile);
    dimensions = sfile.st_size;
    buffer = malloc(sizeof(char) * (dimensions + 1));
    room = malloc(sizeof(char) * (dimensions + 1));
    for (count = 0; count < dimensions; count++) {
        read(fd, buffer, 1);
        room[count] = buffer[0];
    }
    room[count] = '\0';
    free(buffer);
    count = 0;
    for (count_line = 0; count_line < 1000; count_line++) {
        for (count; room[count] != '\n'; count++) {
            if (room[count] >= '0' && room[count] <= '9' && real_first == false) {
                real_first = true;
                first = room[count] - 48;
            } else if (real_first == false) {
                for (i = 0; i < 10; i++) {
                    clone_count = count;
                    if (tab[i][0] == room[clone_count]) {
                        for (j = 0; room[clone_count] == tab[i][j]; j++) {
                            clone_count++;
                        }
                        if (j == my_strlen(tab[i])) {
                            first = i;
                            real_first = true;
                        }
                    }
                }
            }
            if (room[count] >= '0' && room[count] <= '9' && real_last == true) {
                last = room[count] - 48;
                only_one = true;
            } else if (real_last == true) {
                for (i = 0; i < 10; i++) {
                    clone_count = count;
                    if (tab[i][0] == room[clone_count]) {
                        for (j = 0; room[clone_count] == tab[i][j]; j++) {
                            clone_count++;
                        }
                        if (j == my_strlen(tab[i])) {
                            last = i;
                            only_one = true;
                        }
                    }
                }
            }
            if (real_first == true)
                real_last = true;
        }
        if (only_one == false)
            last = first;
        real_last = false;
        total = total + (first * 10) + last;
        real_first = false;
        only_one = false;
        printf("%d %d %d %d\n", count_line + 1, first, last, total);
        first = 0;
        last = 0;
        count++;
    }
    printf("t %d\nf %d\nl %d\n", total, first, last);

    for (int x = 0; x < 10; x++)
        free(tab[i]);
    free(tab);
    free(room);
}