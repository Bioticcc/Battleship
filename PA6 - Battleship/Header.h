/*
Author: Adam Ward
Date: 
Description: 
*/


#pragma once

#ifndef HEADER_H
#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef struct stats {
	int num_hits, num_misses, total_shots;
	double hits_misses_ration;
} Stats;

#endif

void update_stats(Stats *stats_ptr, int status); //1 means hit, 0 means miss

char make_board(char player[10][10], char cpu[10][10], char cpudisplay[10][10], char tempboard[10][10], char CPUtempboard[10][10]);
char show_board(char player[10][10]);
int welcome();
int player_order();
void display_ships();
char place_ships(char player[10][10], char cpu[10][10], char tempboard[10][10]);
char place_CPU_ships(char cpu[10][10], char CPUtempboard[10][10]);
int game(char player[10][10], char cpu[10][10], char cpudisplay[10][10], int order);



