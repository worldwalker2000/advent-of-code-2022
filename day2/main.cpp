#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <sstream>
#include <boost/functional/hash.hpp>

// A, X - Rock
// B, Y - Paper
// C, Z - Scissors

enum Con
{
    WIN = 0,
    TIE,
    LOS,
};

std::unordered_map<std::pair<char, char>, Con, boost::hash<std::pair<char, char>>> c =
{
    { { 'X', 'A' }, TIE },
    { { 'X', 'B' }, LOS },
    { { 'X', 'C' }, WIN },

    { { 'Y', 'A' }, WIN },
    { { 'Y', 'B' }, TIE },
    { { 'Y', 'C' }, LOS },

    { { 'Z', 'A' }, LOS },
    { { 'Z', 'B' }, WIN },
    { { 'Z', 'C' }, TIE },
};

std::unordered_map<char, unsigned long> s =
{
    { 'X', 1},
    { 'Y', 2},
    { 'Z', 3},
};

std::unordered_map<Con, unsigned long> ws =
{
    { WIN, 6 },
    { TIE, 3 },
    { LOS, 0 },
};

void part1()
{
    // std::fstream f("sample.txt");
    std::fstream f("input.txt");

    unsigned long tol{};

    std::string buffer;
    while (std::getline(f, buffer))
    {
        std::stringstream ss(buffer);

        char a{};
        ss >> a;

        char b{};
        ss >> b;

        std::swap(a, b);

        Con r = c[std::make_pair(a, b)];
        tol += s[a];
        tol += ws[r];
    }

    std::cout << tol << std::endl;
}

void part2()
{
    std::unordered_map<std::pair<char, char>, char, boost::hash<std::pair<char, char>>> n =
    {
        { { 'X', 'A' }, 'Z' },
        { { 'X', 'B' }, 'X' },
        { { 'X', 'C' }, 'Y' },

        { { 'Y', 'A' }, 'X' },
        { { 'Y', 'B' }, 'Y' },
        { { 'Y', 'C' }, 'Z' },

        { { 'Z', 'A' }, 'Y' },
        { { 'Z', 'B' }, 'Z' },
        { { 'Z', 'C' }, 'X' },
    };

    // std::fstream f("sample.txt");
    std::fstream f("input.txt");

    unsigned long tol{};

    std::string buffer;
    while (std::getline(f, buffer))
    {
        std::stringstream ss(buffer);

        char a{};
        ss >> a;

        char b{};
        ss >> b;

        std::swap(a, b);

        char ne = n[std::make_pair(a, b)];

        Con r = c[std::make_pair(ne, b)];
        tol += s[ne];
        tol += ws[r];
    }

    std::cout << tol << std::endl;

}

int main()
{
    // part1();
    part2();

    return 0;
}
