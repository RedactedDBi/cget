#include <gtest/gtest.h>
#include <inputparser.h>
#include <vector>

using std::string;
using std::vector;

struct InputParserTest : testing::Test {
    cget::InputParser sut;
    cget::InputParser::Args args = { "install", "--save", "lib/dep" };
};

TEST_F(InputParserTest, ParsesMainCommandCorrectly) {
    cget::InputParser::Result result;
    sut.parse(args, &result);
    GTEST_ASSERT_EQ("install", result.command);
}
