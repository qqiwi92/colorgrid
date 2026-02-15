#include <cmath>
#include <iostream>


void draw(
    int (*coloring_func)(int, int, double),
    double phase,
    size_t width = 30,
    size_t height = 20)
{
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      double freq = 0.2;
      int r = std::sin(coloring_func(x, y, phase)) * 127 + 128;
      int g = std::sin(coloring_func(x, y, phase) + 2) * 127 + 128;
      int b = std::sin(coloring_func(x, y, phase) + 4) * 127 + 128;
      std::printf("\033[48;2;%d;%d;%dm  ", r, g, b);
    }
    std::printf("\033[0m\n");
  }
}

int main()
{
  auto pattern = [](int x, int y, double phase) -> int {
    return x + y + static_cast< int >(phase);
  };

  draw(pattern, 0.0);

  return 0;
}
