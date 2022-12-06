#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <boost/functional/hash.hpp>

unsigned long charToPriority(char c)
{
    if (std::islower(c))
    {
        return ((unsigned int)c) - 97 + 1;
    }
    else
    {
        return ((unsigned int)c) - 65 + 1 + 25 + 1;
    }
}

void part1()
{
    // std::ifstream f("sample.txt");
    std::ifstream f("input.txt");

    unsigned long tol{};

    std::string buffer;
    while (std::getline(f, buffer))
    {
        std::string f = buffer.substr(0, buffer.length()/2);
        std::string b = buffer.substr(buffer.length()/2, buffer.length()/2);

        char dup{};

        // std::sort(f.begin(), f.end());
        // std::sort(b.begin(), b.end());

        for (int i = 0; i < f.length(); i++)
        {
            for (int j = 0; j < f.length(); j++)
            {
                if (f[i] == b[j])
                    dup = f[i];
            }
        }

        unsigned long pr = charToPriority(dup);
        std::cerr << pr << ", " << (char) dup << std::endl;
        tol += pr;
    }

    std::cout << tol << std::endl;
}

void part2()
{
    // std::ifstream f("sample.txt");
    std::ifstream f("input.txt");

    unsigned long tol{};

    std::vector<std::string> buffers{3};
    int bi{0};
    while (std::getline(f, buffers[bi]))
    {
        bi++;

        if (bi >= 3)
        {
            std::string a = buffers[0];
            std::string b = buffers[1];
            std::string c = buffers[2];

            std::cerr << a << std::endl;
            std::cerr << b << std::endl;
            std::cerr << c << std::endl;

            char dup{};

            for (int i = 0; i < a.length(); i++)
            {
                for (int j = 0; j < b.length(); j++)
                {
                    if (a[i] == b[j])
                        for (int k = 0; k < c.length(); k++)
                        {
                            if (b[j] == c[k])
                                dup = c[k];
                        }
                }
            }

            unsigned long pr = charToPriority(dup);
            std::cerr << pr << ", " << (char) dup << std::endl;
            tol += pr;

            bi = 0;
        }
    }

    std::cout << tol << std::endl;
}

int main()
{
    // part1();
    part2();

    return 0;
}
