#include <iostream>

#include <foo/Foo.h>

#include <Poco/DateTimeFormatter.h>
#include <Poco/DateTimeFormat.h>

int main(int argc, char** argv)
{
    auto now = foo::now();
    std::cout << Poco::DateTimeFormatter::format(now, Poco::DateTimeFormat::SORTABLE_FORMAT) << std::endl;

    auto names = foo::getNames({1, 2, 3, 5, 6});
    for (auto name : names)
    {
        std::cout << name << std::endl;
    }
    return 0;
}