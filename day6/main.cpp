#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <boost/functional/hash.hpp>
#include <boost/algorithm/string.hpp>

typedef unsigned long UL;

void part1()
{
    // std::ifstream f("sample.txt");
    std::ifstream f("input.txt");

    int ws = 4;

    UL idx{};

    std::string buffer;
    while (std::getline(f, buffer))
    {
        std::cerr << buffer << std::endl;

        for (int i = ws - 1; i < buffer.size(); i++)
        {
            std::unordered_set<char> s;
            for (int j = 0; j < ws; j++)
                s.insert(buffer[i - j]);

            if (s.size() == ws)
            {
                idx = i;
                break;
            }

            for (char c : s)
                std::cerr << c << ", ";
            std::cerr << std::endl;
        }
    }

    std::cout << idx + 1 << std::endl;
}

void part2()
{
    // std::ifstream f("sample.txt");
    std::ifstream f("input.txt");

    int ws = 14;

    UL idx{};

    std::string buffer;
    while (std::getline(f, buffer))
    {
        std::cerr << buffer << std::endl;

        for (int i = ws - 1; i < buffer.size(); i++)
        {
            std::unordered_set<char> s;
            for (int j = 0; j < ws; j++)
                s.insert(buffer[i - j]);

            if (s.size() == ws)
            {
                idx = i;
                break;
            }

            for (char c : s)
                std::cerr << c << ", ";
            std::cerr << std::endl;
        }
    }

    std::cout << idx + 1 << std::endl;

}

int main()
{
    // part1();
    part2();

    return 0;
}
