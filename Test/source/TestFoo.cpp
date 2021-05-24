#include <gtest/gtest.h>

#include <foo/Foo.h>

TEST(Foo, Foo)
{
    EXPECT_GE(foo::now().year(), 2021);
}

TEST(Foo, Names)
{
    EXPECT_GE(foo::getNames({1, 2, 3, 4}).size(), 4);
    EXPECT_TRUE(foo::getNames({8, 9, 10}).empty());
}