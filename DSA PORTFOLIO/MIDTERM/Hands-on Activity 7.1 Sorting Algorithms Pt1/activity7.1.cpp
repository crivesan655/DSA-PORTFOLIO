#include <iostream>
#include <cstdlib>  // For rand()
#include <ctime>    // For time()
#include "sorting_algorithms.h"

int main() {
    const int SIZE = 100;
    int votes[SIZE];

    // Candidate names for aesthetic purposes
    const char* candidateNames[5] = {
        "Bo Dalton Capistrano",
        "Cornelius Raymon Agustin",
        "Deja Jayla Bañaga",
        "Lalla Brielle Yabut",
        "Franklin Relano Castro"
    };

    // Seed random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate random votes from 1 to 5
    for (int i = 0; i < SIZE; i++) {
        votes[i] = (std::rand() % 5) + 1;  // Values from 1 to 5
    }

    // Sort votes using insertion sort
    insertionSort(votes, SIZE);

    // Count votes for each candidate (1 to 5)
    int voteCounts[5] = {0};

    for (int i = 0; i < SIZE; i++) {
        voteCounts[votes[i] - 1]++;
    }

    // Display vote counts with candidate names
    std::cout << "Vote counts per candidate:\n";
    for (int i = 0; i < 5; i++) {
        std::cout << "Candidate " << (i + 1) << " - " << candidateNames[i] 
                  << ": " << voteCounts[i] << " votes\n";
    }

    // Find winning candidate
    int maxVotes = voteCounts[0];
    int winner = 1;
    for (int i = 1; i < 5; i++) {
        if (voteCounts[i] > maxVotes) {
            maxVotes = voteCounts[i];
            winner = i + 1;
        }
    }

    std::cout << "\nThe winning candidate is Candidate " << winner 
              << " - " << candidateNames[winner - 1] 
              << " with " << maxVotes << " votes.\n";

    return 0;
}

