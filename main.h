#ifndef MAIN_GAME_H_
#define MAIN_GAME_H_

#include<stdio.h>
#include "vec2.c"
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>

#define SLEEP_TIME 10
#define MAP_WIDTH 40
#define MAP_HEIGHT 20

#define MENU_STATE 0
#define GAME_STATE 1
#define GAME_OVER_STATE 2
#define GAME_EXIT_STATE 3

#define UP     72
#define DOWN   80
#define LEFT   75
#define RIGHT  77

short ascii_h_line_code = 205;
short ascii_v_line_code = 186;
short ascii_space_code  = 255;
short ascii_snake_code = 219;
short ascii_bait_code = 248;

short snake_pos_x;
short snake_pos_y;
 
int score;

VEC2_INT* player[MAP_WIDTH * MAP_HEIGHT] = {NULL};
VEC2_INT* direction;
VEC2_INT* bait_pos = NULL;

short map[MAP_WIDTH][MAP_HEIGHT];
short map_and_snake[MAP_WIDTH][MAP_HEIGHT];

int game_state = 0;

void reset_game();
void draw_menu();
void draw_game();
void draw_map();
void draw_game_over();
void draw_snake_art();
void move_snake();
void ate_bait();
void game_over();
void game_over_effect();

void hide_cursor();
void merge_snake_to_map();
void get_key();
#endif /*MAIN_GAME_H_*/
