//
// Created by misha on 05/05/2020.
//
#include "Team.h"
#include "Match.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef UNTITLED2_LAGUE_H
#define UNTITLED2_LAGUE_H

typedef struct {
    int NumMatches, NumTeams;
    Team **teams;
    Match **matches;
} League;

League *LeagueCreate();

void LeagueDestroy(League *league);

void read_teams(League *league, const char *file_name);

void read_matches(League *leag, const char *file_name);

int num_wins(League *league, Team *t);

int num_ties(League *league, Team *t);

int num_losses(League *league, Team *t);

int num_matches(League *league, Team *t);

int num_GF(League *league, Team *t);

int num_GA(League *league, Team *t);

void print_table(League *league); //HW4_LEAGUE_H
#endif //UNTITLED2_LAGUE_H
