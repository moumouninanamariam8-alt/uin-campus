#include "uincampus/version.hpp"

#include <print>

int main()
{
    std::println("uin-campus systeme de gestion academique");
    std::println("version {}", uin::version());
}
