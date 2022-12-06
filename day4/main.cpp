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

    std::vector<std::string> lines{};

    std::string buffer{};
    while (std::getline(f, buffer))
        lines.push_back(buffer);

    std::vector<std::pair<std::pair<UL, UL>, std::pair<UL, UL>>> rs;

    for (std::string line : lines)
    {
        std::vector<std::string> rsr{};
        boost::split(rsr, line, boost::is_any_of(","));

        std::vector<std::string> a_nrs{};
        boost::split(a_nrs, rsr[0], boost::is_any_of("-"));

        std::vector<std::string> b_nrs{};
        boost::split(b_nrs, rsr[1], boost::is_any_of("-"));

        rs.push_back(
                std::make_pair<
                    std::pair<UL, UL>,
                    std::pair<UL, UL>>(
                            std::make_pair<UL, UL>(std::atoi(a_nrs[0].c_str()), std::atoi(a_nrs[1].c_str())),
                            std::make_pair<UL, UL>(std::atoi(b_nrs[0].c_str()), std::atoi(b_nrs[1].c_str()))
                        ));
    }

    UL tol{};

    for (std::pair<std::pair<UL, UL>, std::pair<UL, UL>> p : rs)
    {
        /*
        std::cout << p.first.first << "-" << p.first.second;
        std::cout << "<>"<< p.second.first << "-" << p.second.second << std::endl;
        */

        std::pair<UL, UL> f = p.first;
        std::pair<UL, UL> s = p.second;

        if (f.first <= s.first && f.second >= s.second) tol++;
        else if (s.first <= f.first && s.second >= f.second) tol++;
    }

    std::cout << tol << std::endl;
}

void part2()
{
    // std::ifstream f("sample.txt");
    std::ifstream f("input.txt");

    std::vector<std::string> lines{};

    std::string buffer{};
    while (std::getline(f, buffer))
        lines.push_back(buffer);

    std::vector<std::pair<std::pair<UL, UL>, std::pair<UL, UL>>> rs;

    for (std::string line : lines)
    {
        std::vector<std::string> rsr{};
        boost::split(rsr, line, boost::is_any_of(","));

        std::vector<std::string> a_nrs{};
        boost::split(a_nrs, rsr[0], boost::is_any_of("-"));

        std::vector<std::string> b_nrs{};
        boost::split(b_nrs, rsr[1], boost::is_any_of("-"));

        rs.push_back(
                std::make_pair<
                    std::pair<UL, UL>,
                    std::pair<UL, UL>>(
                            std::make_pair<UL, UL>(std::atoi(a_nrs[0].c_str()), std::atoi(a_nrs[1].c_str())),
                            std::make_pair<UL, UL>(std::atoi(b_nrs[0].c_str()), std::atoi(b_nrs[1].c_str()))
                        ));
    }

    UL tol{};

    for (std::pair<std::pair<UL, UL>, std::pair<UL, UL>> p : rs)
    {
        std::pair<UL, UL> f = p.first;
        std::pair<UL, UL> s = p.second;

        if (f.first <= s.second && f.second >= s.first) tol++;
        else if (s.first <= f.second && s.second >= f.first) tol++;
    }

    std::cout << tol << std::endl;
}

int main()
{
    // part1();
    part2();

    return 0;
}
