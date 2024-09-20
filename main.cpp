#include "raylib.h"
#include <vector>
#include <random>
#include <thread>
#include <chrono>

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

void BubbleSortVisualized(std::vector<int>& array) {
    int n = array.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawArray(array, j); // Draw random array and sort
            EndDrawing();

            //Delay for 50ms
            std::this_thread::sleep_for(std::chrono::milliseconds(1));

            // Swapping
            if(array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
            }
        }
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
        BubbleSortVisualized(array);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        break;
    }

    /* End of ray-lib */
    CloseWindow();

    return 0;
}