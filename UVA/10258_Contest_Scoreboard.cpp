#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Team{
    int teamNum, ac, penalty;
    int submit[10];
    bool hasSubmit;
    bool operator<(const Team t) const{
        if(ac > t.ac)
            return true;
        if(ac < t.ac)
            return false;
        if(penalty < t.penalty)
            return true;
        else if(penalty == t.penalty)
            return teamNum < t.teamNum;
        else
            return false;
    }
}team[105];

int main()
{
    int cases, teamNum, problemNum, time;
    char s[100], L;

    scanf("%d", &cases);
    gets(s);
    gets(s);

    while(cases--){
        for(int i = 0; i < 105; i++){
            team[i].ac = team[i].penalty = team[i].hasSubmit = 0;
            team[i].teamNum = i;
            memset(team[i].submit, 0, sizeof(team[i].submit));
        }
        while(1){
            if(gets(s) == NULL)
                break;
            if(strlen(s) == 0)
                break;
            sscanf(s, "%d %d %d %c", &teamNum, &problemNum, &time, &L);
            team[teamNum].hasSubmit = true;
            if(L == 'C' && team[teamNum].submit[problemNum] != -1){
                team[teamNum].submit[problemNum]++;
                team[teamNum].penalty += time + (team[teamNum].submit[problemNum] - 1) * 20;
                team[teamNum].ac++;
                team[teamNum].submit[problemNum] = -1;
            }
            else if(L == 'I' && team[teamNum].submit[problemNum] == false)
                team[teamNum].submit[problemNum]++;
        }
        sort(team, team + 105);
        for(int i = 0; i < 105; i++){
            if(team[i].hasSubmit){
                printf("%d %d %d\n", team[i].teamNum, team[i].ac, team[i].penalty);
            }
        }
        if(cases)
            printf("\n");
    }
    return 0;
}
