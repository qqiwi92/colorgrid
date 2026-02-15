#include <cmath>
#include <cstdio>
#include <iostream>

void draw(
    int (*coloring_func)(int, int, double),
    double phase,
    size_t width = 30,
    size_t height = 20)
{
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      double val = coloring_func(x, y, phase);
      int r = std::sin(val) * 127 + 128;
      int g = std::sin(val + 2) * 127 + 128;
      int b = std::sin(val + 4) * 127 + 128;
      std::printf("\033[48;2;%d;%d;%dm  ", r, g, b);
    }
    std::printf("\033[0m\n");
  }

  std::printf("\033[%zuA", height);
}

int main()
{
  auto pattern = [](int x, int y, double phase) -> int {
    return (int)((double)(x ^ y) + phase);
  };

  double phase = 0;
  std::printf("\033[?25l");

  while (true) {
    draw(pattern, phase);
    phase += 100;
    std::fflush(stdout);

    std::printf("\033[?25h");

  }
    return 0;
}
