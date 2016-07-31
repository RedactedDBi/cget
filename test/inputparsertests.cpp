#include <gtest/gtest.h>
#include <inputparser.h>

using std::string;
using std::vector;

struct InputParserTest : testing::Test {
    using Result = cget::InputParser::Result;

    const cget::InputParser::Args argsFullFlag = { "install", "--save", "lib/dep" };
    const cget::InputParser::Args argsShortFlag = { "install", "-s", "lib/dep" };
    const cget::InputParser::ShortFlags shortFlags = {
            { "s", "save" }
    };

    cget::InputParser sut;
    InputParserTest() : sut(shortFlags) {}
};

TEST_F(InputParserTest, ParsesMainCommandCorrectly) {
    Result result;
    sut.parse(argsFullFlag, &result);
    ASSERT_EQ("install", result.command);
}

TEST_F(InputParserTest, ParsesBinaryFlagsCorrectly) {
    Result result;
    sut.parse(argsFullFlag, &result);
    ASSERT_EQ(result.binaryFlags.size(), 1);
    ASSERT_TRUE(result.binaryFlags.find("save") != result.binaryFlags.end());
}

TEST_F(InputParserTest, ParsesShorthandBinaryFlagCorrectly) {
    Result result;
    sut.parse(argsShortFlag, &result);
    ASSERT_EQ(result.binaryFlags.size(), 1);
    ASSERT_TRUE(result.binaryFlags.find("save") != result.binaryFlags.end());
}

TEST_F(InputParserTest, OnlyFlagsThrowsException) {
    Result result;
    ASSERT_THROW(sut.parse({ "--flag" }, &result), std::invalid_argument);
}

TEST_F(InputParserTest, EmptyArgsThrowsException) {
    Result result;
    ASSERT_THROW(sut.parse({}, &result), std::invalid_argument);
}