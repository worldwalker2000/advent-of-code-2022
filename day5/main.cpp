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

    std::string firstLine{};
    std::vector<std::string> lines{};

    std::string buffer{};
    while (std::getline(f, buffer))
    {
        if (firstLine == "")
            firstLine = buffer;

        if (buffer == "")
            break;

        lines.push_back(buffer);
    }

    const UL width = (firstLine.length() + 1) / 4;
    std::vector<std::vector<char>> stacks{width};

    for (auto it = lines.rbegin() + 1; it != lines.rend(); it++)
    {
        std::string l = *it;
        l += " ";
        for (int i = 0; i < l.length() / 4; i++)
        {
            char c = l.substr(i * 4, 4)[1];
            if ((int)c != 32)
                stacks[i].push_back(c);
        }
    }

    while (std::getline(f, buffer))
    {
        std::cerr << buffer << std::endl;
        std::stringstream ss(buffer);

        ss >> buffer; // remove the word "move"

        int count{}, from{}, to{};

        ss >> count;

        ss >> buffer; // remove the word "from"

        ss >> from;

        ss >> buffer; // remove the word "to"

        ss >> to;

        // ew 1 base fix
        from--;
        to--;

        for (int i = 0; i < count; i++)
        {
            char c = stacks[from].back();
            stacks[from].pop_back();
            stacks[to].push_back(c);
        }
    }

    for (std::vector<char> s : stacks)
    {
        std::cout << s.back();
    }
    std::cout << std::endl;
}

void part2()
{
    // std::ifstream f("sample.txt");
    std::ifstream f("input.txt");

    std::string firstLine{};
    std::vector<std::string> lines{};

    std::string buffer{};
    while (std::getline(f, buffer))
    {
        if (firstLine == "")
            firstLine = buffer;

        if (buffer == "")
            break;

        lines.push_back(buffer);
    }

    const UL width = (firstLine.length() + 1) / 4;
    std::vector<std::vector<char>> stacks{width};

    for (auto it = lines.rbegin() + 1; it != lines.rend(); it++)
    {
        std::string l = *it;
        l += " ";
        for (int i = 0; i < l.length() / 4; i++)
        {
            char c = l.substr(i * 4, 4)[1];
            if ((int)c != 32)
                stacks[i].push_back(c);
        }
    }

    while (std::getline(f, buffer))
    {
        std::cerr << buffer << std::endl;
        std::stringstream ss(buffer);

        ss >> buffer; // remove the word "move"

        int count{}, from{}, to{};

        ss >> count;

        ss >> buffer; // remove the word "from"

        ss >> from;

        ss >> buffer; // remove the word "to"

        ss >> to;

        // ew 1 base fix
        from--;
        to--;

        std::vector<char> inter{};
        for (int i = 0; i < count; i++)
        {
            char c = stacks[from].back();
            stacks[from].pop_back();
            inter.push_back(c);
        }

        for (auto it = inter.rbegin(); it != inter.rend(); it++)
        {
            stacks[to].push_back(*it);
        }
    }

    for (std::vector<char> s : stacks)
    {
        std::cout << s.back();
    }
    std::cout << std::endl;

}

int main()
{
    // part1();
    part2();

    return 0;
}
