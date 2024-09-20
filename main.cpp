#include "raylib.h"
#include <vector>
#include <random>

void DrawArray(const std::vector<int>& array, int highlightedIndex = -1) {
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    int barWidth = screenWidth / array.size();

    for(int i = 0; i < array.size(); i++) {
        Color barColor = GRAY;
        if(i == highlightedIndex) {
            barColor = RED;
        }
        DrawRectangle(i * barWidth, screenHeight - array[i], barWidth, array[i], barColor);
    }
}

int main(){
    /* Window initialization */
    InitWindow(800, 600, "Bubble sort visualisation");

    /* Creating random list */
    std::random_device rd;  // Source of randomness
    std::mt19937 gen(rd()); // Generator random number of Mersenne Twister
    std::uniform_int_distribution<> randomRangeGenerator(0, GetScreenHeight()); // Range of value

    std::vector<int> array(100);
    for(int& val : array) {
        val = randomRangeGenerator(gen); // Random number
    }

    /* Main Loop */
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawArray(array); // Draw random array and sort
        EndDrawing();
    }

    /* End of ray-lib */
    CloseWindow();

    return 0;
}