#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <boost/functional/hash.hpp>
#include <boost/algorithm/string.hpp>

typedef unsigned long UL;

void part1()
{
    // std::ifstream f("sample.txt");
    std::ifstream f("input.txt");

    std::vector<std::vector<int>> hm{};

    int y = 0;

    std::string buffer{};
    while (std::getline(f, buffer))
    {
        hm.push_back({});
        for (char c : buffer)
            hm[y].push_back(c - '0');
        y++;
    }

    std::array<std::pair<int, int>, 4> dirs =
    {{
         { 0, -1 },
         { 0, 1 },
         { -1, 0 },
         { 1, 0 },
     }};

    int nVisible{0};

    for (size_t y = 0; y < hm.size(); y++)
    {
        for (size_t x = 0; x < hm[y].size(); x++)
        {
            bool visible = false;

            for (size_t d = 0; d < dirs.size(); d++)
            {
                auto [dx, dy] = dirs[d];
                int tx = x, ty = y;
                int sh = hm[y][x];
                while (!visible)
                {
                    tx += dx;
                    ty += dy;

                    if (tx < 0 || tx > hm[y].size() - 1 || ty < 0 || ty > hm.size() - 1)
                    {
                        visible = true;
                        continue;
                    }

                    if (hm[ty][tx] >= sh)
                        break;
                }
            }

            if (visible)
                nVisible++;
        }
    }

    std::cout << nVisible << std::endl;
}

void part2()
{
    // std::ifstream f("sample.txt");
    std::ifstream f("input.txt");

    std::vector<std::vector<int>> hm{};

    int y = 0;

    std::string buffer{};
    while (std::getline(f, buffer))
    {
        hm.push_back({});
        for (char c : buffer)
            hm[y].push_back(c - '0');
        y++;
    }

    std::array<std::pair<int, int>, 4> dirs =
    {{
         { 0, -1 },
         { 0, 1 },
         { -1, 0 },
         { 1, 0 },
     }};

    int score{};

    for (size_t y = 0; y < hm.size(); y++)
    {
        for (size_t x = 0; x < hm[y].size(); x++)
        {
            int cscore{1};

            for (size_t d = 0; d < dirs.size(); d++)
            {
                int v{};
                auto [dx, dy] = dirs[d];
                int tx = x, ty = y;
                int sh = hm[y][x];
                while (true)
                {
                    tx += dx;
                    ty += dy;

                    if (tx < 0 || tx > hm[y].size() - 1 || ty < 0 || ty > hm.size() - 1)
                        break;

                    v++;

                    if (hm[ty][tx] >= sh)
                        break;
                }

                cscore *= v;
            }

            if (cscore > score)
                score = cscore;
        }
    }

    std::cout << score << std::endl;
}

int main()
{
    // part1();
    part2();

    return 0;
}
