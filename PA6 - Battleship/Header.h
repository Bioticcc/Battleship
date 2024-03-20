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

#endif

char make_board(char player[10][10], char cpu[10][10]);
int welcome();
int player_order();
char place_ships(char player[10][10], char cpu[10][10]);



