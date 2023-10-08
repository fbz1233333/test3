#pragma once
#include <iostream>
#include <istream>
#include <fstream>
#include <ostream>
#include <vector>

namespace CSV
{


    template <typename T>
    void Save(std::ofstream &ofs, const std::vector<T> &ts)
    {
        for (const auto &t : ts)
        {
            CSV::convert<T>::encode(ofs, t);
        }
    }

    template <typename T>
    bool Load(std::ifstream &ifs, std::vector<T> &ts)
    {
        std::string line;

        while (std::getline(ifs, line))
        {
            std::istringstream iss(line);
            T t;

            bool fg = CSV::convert<T>::decode(iss, t);
            if (fg)
            {
                ts.emplace_back(t);
            }
            else
            {
                std::cerr << "error parsing " << line << std::endl;
            }
        }

        return true;
    }
};