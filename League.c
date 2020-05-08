//
// Created by tal5s on 05/05/2020.
//

#include "Team.h"
#include "Match.h"
#include <stdio.h>
#include <stdlib.h>
#include "League.h"

League *LeagueCreate() {
    League *league;
    league = (League *) malloc(sizeof(League));
    if (league == NULL) {
        printf("Failed to allocate %lu bytes\n", sizeof(League));
        exit(1);
    }
    return league;
}

void LeagueDestroy(League *league) {
    free(league);
}

void read_teams(League *league, const char *file_name) {
    league->teams = NULL; //pushed all variables and inits to the top
    league->NumTeams = 0;
    char *line = NULL;
    size_t line_size = 0;
    FILE *fp = fopen(file_name, "r");
    if (!fp) {
        fprintf(stderr, "error in line %d, failed to open a file\n", __LINE__);
        exit(-1);
    }
    while (getline(&line, &line_size, fp) != EOF) { //erased the 'len' variable
        league->teams = (Team **) realloc(league->teams, sizeof(Team));
        league->teams[league->NumMatches] = TeamCreate(line);
        league->NumMatches++;
    }
    fclose(fp);
}

void read_matches(League *league, const char *file_name) {
    league->matches = NULL;
    league->NumMatches = 0;
    FILE *fp = fopen(file_name, "r");
    if (!fp) {
        fprintf(stderr, "error in line %d, failed to open a file\n", __LINE__);
        exit(-1);
    }
    char *line = NULL;
    size_t size = 10;
    size_t len = 0;
    char *ptrH[10];
    char *ptrG[10];
    int goalH = 0;
    int goalG = 0;
    printf("OK1\n");
    while ((len = getline(&line, &size, fp)) != EOF) {
        fscanf(fp, "%s\t%s\t%d \t%d", ptrH, ptrG, &goalH, &goalG);
        league->matches = (Match **) realloc(league->matches, sizeof(Match) );
        Team *teamH = NULL;
        Team *teamG = NULL;
        for (int i = 0; i < league->NumMatches; i++) {
            if (*(league->teams[i]->TeamName) == **ptrH) {
                teamH = league->teams[i];
            }

            if (*(league->teams[i]->TeamName) == **ptrG) {
                teamG = league->teams[i];
            }

            if ((teamH->TeamName) != NULL && (teamG->TeamName) != NULL) {
                break;
                printf("OK6");
            }
        }
        league->matches[league->NumMatches] = MatchCreate(teamH, teamG, goalH, goalG);
        league->NumMatches++;
    }
    fclose(fp);
}