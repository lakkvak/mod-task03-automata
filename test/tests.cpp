#include <gtest/gtest.h>
#include "Automata.h"

TEST(taskA, test1)
{
    auto cof = Automata();
    cof.on();
    cof.coin(200);
    cof.finish();
    cof.choice(3);
    States result = cof.getState();
    EXPECT_EQ(WAIT, result);
}

TEST(taskA, test2)
{
    auto cof = Automata();
    cof.on();
    cof.choice(1);
    States result = cof.getState();
    EXPECT_EQ(WAIT, result);
}

TEST(taskA, test3)
{
    auto cof = Automata();
    cof.on();
    cof.coin(150);
    cof.choice(0);
    int result = cof.finish();
    EXPECT_EQ(50, result);
}