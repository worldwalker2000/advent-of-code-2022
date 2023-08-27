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

void part1()
{
    std::ifstream f("sample.txt");
    // std::ifstream f("input.txt");

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

    for (Inst inst : insts)
    {
        std::cout << inst.dir << " -> " << inst.n << std::endl;
    }
}

void part2()
{
}

int main()
{
    part1();
    // part2();

    return 0;
}
