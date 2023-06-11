#include <stdio.h>
#define MAX_CANDIDATES 10
typedef struct {
    char name[20];
    int votes;
} Candidate;
void printResults(Candidate* candidates, int numCandidates) {
    printf("\nResults:\n");
    printf("\n");
    printf("| %s | %s |\n", "Candidate", "Votes");
    printf("\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("| %s | %d |\n", candidates[i].name, candidates[i].votes);
    }
    printf("\n");
}
void printWinners(Candidate* winners, int numWinners) {
    printf("\nCongratulations to the top four candidates:\n");
    for (int i = 0; i < numWinners; i++) {
        printf("%d. %s\n", i + 1, winners[i].name);
    }
}
int main() {
    int numCompetitors, numVoters;
    printf("Enter the number of competitors: ");
    scanf("%d", &numCompetitors);
    printf("Enter the number of voters: ");
    scanf("%d", &numVoters);
    Candidate candidates[MAX_CANDIDATES];
    for (int i = 0; i < numCompetitors; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
    for (int i = 0; i < numVoters; i++) {
        printf("Vote %d:\n", i + 1);
        int candidateNum;
        printf("Enter the candidate number (1-%d): ", numCompetitors);
        scanf("%d", &candidateNum);
        candidates[candidateNum - 1].votes++;
    }
    for (int i = 0; i < numCompetitors - 1; i++) {
        for (int j = 0; j < numCompetitors - i - 1; j++) {
            if (candidates[j].votes < candidates[j + 1].votes) {
                Candidate temp = candidates[j];
                candidates[j] = candidates[j + 1];
                candidates[j + 1] = temp;
            }
        }
    }
    printResults(candidates, numCompetitors);
    int numWinners = 4; 
    if (numCompetitors < numWinners) {
        numWinners = numCompetitors;
    }
    printWinners(candidates, numWinners);
    printf("\nCongratulations to the winner:\n");
    printf("%s\n", candidates[0].name);
    return 0;
}
