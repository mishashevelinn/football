//
// Created by misha on 05/05/2020.
//

#ifndef UNTITLED2_TEAM_H
#define UNTITLED2_TEAM_H
typedef struct {
    const char* TeamName;
} Team;
Team * TeamCreate (const char* name);

void TeamDestroy ( Team *team);

#endif //UNTITLED2_TEAM_H
