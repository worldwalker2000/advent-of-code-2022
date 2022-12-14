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

typedef unsigned long long UL;

template <typename T>
T pop(std::vector<T>& vec)
{
    T val = vec.back();
    vec.pop_back();

    return val;
}

struct File
{
    std::string name;
    UL size;
};

struct Dir
{
    Dir* parent;
    std::string name;
    UL size;
    std::vector<File*> files;
    std::vector<Dir*> dirs;
};

void freeDir(Dir* root)
{
    for (File* f : root->files) delete f;

    for (Dir* dir : root->dirs) freeDir(dir);

    delete root;
}

UL fillSizes(Dir* root)
{
    UL size{};

    for (File* f : root->files) size += f->size;

    for (Dir* dir : root->dirs) size += fillSizes(dir);

    root->size = size;

    return size;
}

UL sumSmallDirs(Dir* root)
{
    UL sum{};

    if (root->size <= 100000)
        sum += root->size;

    for (Dir* dir : root->dirs)
    {
        UL iSum = sumSmallDirs(dir);
        if (iSum <= 100000)
        {
            std::cerr << "small dir: " << dir->name << " - " << dir->size << std::endl;
            sum += iSum;
        }
    }

    return sum;
}

void part1()
{
    std::ifstream f("sample.txt");
    // std::ifstream f("input.txt");

    Dir* root = nullptr;
    Dir* curr = nullptr;

    std::string buffer;
    while (std::getline(f, buffer))
    {
        std::vector<std::string> tk{};
        boost::split(tk, buffer, boost::is_any_of(" "));

        std::vector<std::string> tkNonCmd{ tk.begin(), tk.end() };

        std::reverse(tk.begin(), tk.end());

        std::string op = pop(tk);
        if (op == "$")
        {
            std::string cmd = pop(tk);

            if (cmd == "cd")
            {
                std::string dirName = pop(tk);

                if (!root && dirName == "/")
                {
                    root = new Dir{ nullptr, dirName, static_cast<UL>(-1), {}, {} };
                    curr = root;
                }
                else if (!root)
                {
                    std::cerr << "something broke" << std::endl;
                    exit(-1);
                }
                else if (dirName == "..")
                {
                    curr = curr->parent;
                }
                else
                {
                    Dir* newDir = new Dir{ curr, dirName, static_cast<UL>(-1), {}, {} };
                    curr->dirs.push_back(newDir);
                    curr = newDir;
                }
            }
        }
        else
        {
            std::string name = pop(tkNonCmd);
            std::string ts = pop(tkNonCmd);

            if (ts != "dir")
            {
                curr->files.push_back(new File{ name, static_cast<UL>(std::atoll(ts.c_str())) });
            }
        }
    }

    UL size = fillSizes(root);
    // std::cout << size << std::endl;

    UL sum = sumSmallDirs(root);
    std::cout << sum << std::endl;

    freeDir(root);
}

void part2()
{
    std::ifstream f("sample.txt");
    // std::ifstream f("input.txt");
}

int main()
{
    part1();
    // part2();

    return 0;
}
