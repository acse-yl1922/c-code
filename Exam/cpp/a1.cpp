#include <iostream>
#include <random>

using namespace std;

// Function to simulate rolling two dice with 12 sides each, N times
int roll_dice(int N) {
    // Set up random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 12);

    // Roll dice N times and count the number of times 6 appears
    int count = 0;
    for (int i = 0; i < N; i++) {
        int roll1 = dis(gen);
        int roll2 = dis(gen);
        if (roll1 == 6 || roll2 == 6) {
            count++;
        }
    }

    return count;
}