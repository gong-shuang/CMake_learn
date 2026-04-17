#include <gtest/gtest.h>

// Test cases for MyLib
TEST(MyLibTest, BasicTest) {
    EXPECT_EQ(1, 1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}