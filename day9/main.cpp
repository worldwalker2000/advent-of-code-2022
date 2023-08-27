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

struct Inst
{
    char dir;
    int n;
};

struct Point
{
    int x;
    int y;

    bool operator==(const Point &other) const
    {
        return x == other.x && y == other.y;
    }
};

namespace std
{
    template <>
    struct hash<Point>
    {
        std::size_t operator()(const Point &p) const noexcept
        {
            return p.x + 1000 * p.y;
        }
    };
}

void part1()
{
    // std::ifstream f("sample.txt");
    std::ifstream f("input.txt");

    std::vector<Inst> insts;

    std::string buffer{};
    while (std::getline(f, buffer))
    {
        std::stringstream ss(buffer);

        Inst inst;
        ss >> inst.dir;
        ss >> inst.n;

        insts.push_back(inst);
    }

    Point head{};
    Point tail{};

    auto IsTouching = [&]()
    {
        return abs(head.x - tail.x) <= 1 && abs(head.y - tail.y) <= 1;
    };

    std::unordered_set<Point> points{tail};

    for (Inst inst : insts)
    {
        for (int i = 0; i < inst.n; i++)
        {
            switch (inst.dir)
            {
            case 'U':
                head.y++;
                break;
            case 'D':
                head.y--;
                break;
            case 'R':
                head.x++;
                break;
            case 'L':
                head.x--;
                break;
            }

            if (!IsTouching())
            {
                int dx = head.x - tail.x;
                int dy = head.y - tail.y;
                if (head.x == tail.x || head.y == tail.y)
                {
                    if (abs(dx) > abs(dy))
                    {
                        dx = dx > 0 ? 1 : -1;
                        dy = 0;
                    }
                    else
                    {
                        dy = dy > 0 ? 1 : -1;
                        dx = 0;
                    }
                }
                else
                {
                    dx = dx > 0 ? 1 : -1;
                    dy = dy > 0 ? 1 : -1;
                }

                tail.x += dx;
                tail.y += dy;
                points.insert(tail);
            }

            // std::cout << inst.dir << std::endl;
            // for (int yy = 0; yy < 5; yy++)
            // {
            //     int y = 4 - yy;
            //     for (int x = 0; x < 6; x++)
            //     {
            //         char c = '.';
            //         if (tail.x == x && tail.y == y)
            //             c = 'T';
            //         if (head.x == x && head.y == y)
            //             c = 'H';
            //         std::cout << c;
            //     }
            //     std::cout << "\n";
            // }
        }
    }

    std::cout << points.size() << std::endl;
}

struct Snake
{
    Point p;
    int follow;
};

void part2()
{
    // std::ifstream f("sample.txt");
    std::ifstream f("input.txt");

    std::vector<Inst> insts;

    std::string buffer{};
    while (std::getline(f, buffer))
    {
        std::stringstream ss(buffer);

        Inst inst;
        ss >> inst.dir;
        ss >> inst.n;

        insts.push_back(inst);
    }

    Snake snake[10] = {};
    for (int i = 1; i < 10; i++)
    {
        snake[i].follow = i - 1;
    }

    auto IsTouching = [&](int a, int b)
    {
        return abs(snake[a].p.x - snake[b].p.x) <= 1 && abs(snake[a].p.y - snake[b].p.y) <= 1;
    };

    std::unordered_set<Point> points{Point{0, 0}};

    auto Follow = [&](int a, int b)
    {
        if (!IsTouching(a, b))
        {
            int dx = snake[a].p.x - snake[b].p.x;
            int dy = snake[a].p.y - snake[b].p.y;
            if (snake[a].p.x == snake[b].p.x || snake[a].p.y == snake[b].p.y)
            {
                if (abs(dx) > abs(dy))
                {
                    dx = dx > 0 ? 1 : -1;
                    dy = 0;
                }
                else
                {
                    dy = dy > 0 ? 1 : -1;
                    dx = 0;
                }
            }
            else
            {
                dx = dx > 0 ? 1 : -1;
                dy = dy > 0 ? 1 : -1;
            }

            snake[b].p.x += dx;
            snake[b].p.y += dy;
            if (b == 9)
                points.insert(snake[b].p);
        }
    };

    for (Inst inst : insts)
    {
        for (int i = 0; i < inst.n; i++)
        {
            Point &head = snake[0].p;
            switch (inst.dir)
            {
            case 'U':
                head.y++;
                break;
            case 'D':
                head.y--;
                break;
            case 'R':
                head.x++;
                break;
            case 'L':
                head.x--;
                break;
            }

            for (int j = 1; j < 10; j++)
            {
                Follow(j - 1, j);
            }
        }

        // std::cout << inst.dir << std::endl;
        // for (int yy = 0; yy < 21; yy++)
        // {
        //     int y = 21 - yy;
        //     for (int x = 0; x < 27; x++)
        //     {
        //         char c = '.';
        //         for (int j = 0; j < 10; j++)
        //         {
        //             if (snake[j].p.x == x && snake[j].p.y == y)
        //             {
        //                 c = '0' + j;
        //             }
        //         }
        //         std::cout << c;
        //     }
        //     std::cout << "\n";
        // }
    }

    std::cout << points.size() << std::endl;
}

int main()
{
    // part1();
    part2();

    return 0;
}
