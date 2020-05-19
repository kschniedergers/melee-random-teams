#include <mml/random.h>

#define P1_TEAM 0x803F0E06
#define P2_TEAM 0x803F0E2A
#define P3_TEAM 0x803F0E4E
#define P4_TEAM 0x803F0E72

#define RED 0
#define BLUE 1
#define GREEN 2

#define INJECTPOINT 0x802617D0


int randomTeam() {
    float rand = rand * 3;
    if (rand <= 1) {
        return RED;
    }
    else if (rand <= 2) {
        return BLUE;
    }
    else {
        return GREEN;
    }
}

void setTeam(u8 port, u8 color) {
    switch (port) {
        case 1 :
            (u8*)P1_TEAM = color;
            break;
        case 2 :
            (u8*)P2_TEAM = color;
            break;
        case 3 :
            (u8*)P3_TEAM = color;
            break;
        case 4 :
            (u8*)P4_TEAM = color;
            break;
    }
}

int _main() {
    
    int[4] teamSetup
    
    int rand = rand() * 3;
    if (rand <= 1) {
        teamSetup = [1,2,3,4];
    }
    else if (rand <=2) {
        teamSetup = [1,3,2,4];
    }
    else {
        teamSetup = [1,4,2,3];
    }
   
    int team1Color = randomTeam();
    int team2Color;
    
    do {
        team2Color = randomTeam();
    } while (team1Color == team2Color);

    setTeam(teamSetup[0], (u8) team1Color);
    setTeam(teamSetup[1], (u8) team1Color); 
    setTeam(teamSetup[2], (u8) team2Color);
    setTeam(teamSetup[3], (u8) team2Color);
}
