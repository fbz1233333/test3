#include "pch.h"
#include "CSV.h"

struct User
{
    std::string no;
    std::string name;
    std::string password;
};
namespace CSV
{
    template <>
    struct convert<User>
    {
        static void encode(std::ofstream &ofs, const User &user)
        {
            ofs << user.no << "," << user.name << "," << user.password << std::endl;
        }
        static bool decode(std::istringstream &iss, User &t)
        {
            return std::getline(iss, t.no, ',') && std::getline(iss, t.name, ',') && std::getline(iss, t.password);
        }
    };
};

int main()
{
    std::vector<User> users =
        {
            {"s", "fbz你好 我是办法", "123465"},
            {"s", "fbz你好 我是办法", "123465"},
            {"s", "ss萨达 sadasd", "14s sdasdasdad"},
            {"s", "ss", "阿松大14s"},
            {"s", "ss", "14s埃索达三"},
            {"a埃索达三s", "ss", "1兽打4s"},
            {"24454按时打算从", "ss", "14s"},
        };

    std::ofstream ofs("f2.csv");
    CSV::Save<User>(ofs, users);
    ofs.flush();
    ofs.close();

    std::ifstream ifs("f2.csv");
    std::vector<User> users2;
    CSV::Load<User>(ifs, users2);
    ifs.close();

    for (auto &u2 : users)
    {
        std::cout << u2.no << ',' << u2.name << "," << u2.password << std::endl;
    }

    // std::ofstream ofs("fbz.csv");
    // for (const auto &user : users)
    // {
    //     CSV::convert<User>::encode(ofs, user);
    // }
    // ofs.flush();
    // ofs.close();

    // std::vector<User> users2;
    // std::ifstream ifs("fbz.csv");
    // std::string line;

    // while(std::getline(ifs, line)){
    //     std::istringstream iss(line);
    //     User t;

    //     bool fg = CSV::convert<User>::decode(iss, t);
    //     if (fg)
    //     {
    //         users2.emplace_back(t);
    //     }
    //     else
    //     {
    //         std::cout << "error parsing " << line << std::endl;
    //     }
    // }

    // ifs.close();

    // for(const auto& u:users2)
    // {
    //     std::cout << u.no << "," << u.name << "," << u.password << std::endl;
    // }
};