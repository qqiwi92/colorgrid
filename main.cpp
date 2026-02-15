#include <cmath>
#include <iostream>
#include <cstdio>

void draw() {
    const size_t width = 60, height = 30;
    double frequency = 0.15; 
    const double mPI = 3.14159265359;
    
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            
            size_t k = i + j;
            int r = std::sin(frequency * k ) * 127 + 128;
            int g = std::sin(frequency /2  *k + 2 * mPI/3) * 127 + 128;
            int b = std::sin(frequency * k + 4 * mPI/3) * 127 + 128;

            std::printf("\033[38;2;%d;%d;%dm█", r, g, b);
        }
        std::cout << "\n";
    }

    std::cout << "\033[0m" << std::endl;
}

int main() {
  draw();
}