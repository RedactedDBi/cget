#include <gtest/gtest.h>
#include <temp.h>

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(Addition, CanAddTwoNumbers) {
    EXPECT_TRUE(add(2, 2) == 4);
}