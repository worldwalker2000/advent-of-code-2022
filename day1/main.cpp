#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <fstream>
#include <algorithm>

void part1()
{
    // std::ifstream f("sample.txt");
    std::ifstream f("input.txt");

    std::vector<unsigned long> cals{};
    std::make_heap(cals.begin(), cals.end());

    int acc = 0;
    while (!f.eof())
    {
        std::string buffer;
        std::getline(f, buffer);

        if (buffer == "")
        {
            cals.push_back(acc);
            std::push_heap(cals.begin(), cals.end());
            acc = 0;
        }
        else
            acc += std::atoi(buffer.c_str());
    }

    std::cout << cals.front() << std::endl;
}

void part2()
{
    // std::ifstream f("sample.txt");
    std::ifstream f("input.txt");

    std::vector<unsigned long> cals{};
    std::make_heap(cals.begin(), cals.end());

    int acc = 0;
    while (!f.eof())
    {
        std::string buffer;
        std::getline(f, buffer);

        if (buffer == "")
        {
            cals.push_back(acc);
            std::push_heap(cals.begin(), cals.end());
            acc = 0;
        }
        else
            acc += std::atoi(buffer.c_str());
    }

    unsigned long lacc = 0;

    std::pop_heap(cals.begin(), cals.end());
    lacc += cals.back();
    cals.pop_back();

    std::pop_heap(cals.begin(), cals.end());
    lacc += cals.back();
    cals.pop_back();

    std::pop_heap(cals.begin(), cals.end());
    lacc += cals.back();
    cals.pop_back();

    std::cout << lacc << std::endl;
}

int main()
{
    // part1();
    part2();

    return 0;
}
