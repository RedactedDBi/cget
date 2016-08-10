#include <gtest/gtest.h>
#include "../src/inputparser.h"

using std::string;
using std::vector;

struct InputParserTest : testing::Test {
    using Result = cget::InputParser::Result;

    const cget::InputParser::Args argsOneFlag = { "--save" };
    const cget::InputParser::Args argsFullFlag = { "install", "--save", "lib/dep" };
    const cget::InputParser::Args argsShortFlag = { "install", "-s", "lib/dep" };
    const cget::InputParser::ShortFlags shortFlags = {
            { "s", "save" }
    };

    cget::InputParser sut;
    InputParserTest() : sut(shortFlags) {}
};

TEST_F(InputParserTest, ParsesMainCommandCorrectly) {
    cget::InputParser::Args output;
    auto cmd = sut.parseSubCommand(argsFullFlag, &output);
    ASSERT_EQ("install", cmd);
    ASSERT_EQ(output.size(), 2);
    ASSERT_EQ(output[0], "--save");
    ASSERT_EQ(output[1], "lib/dep");
}

TEST_F(InputParserTest, ParsesBinaryFlagsCorrectly) {
    Result result;
    cget::InputParser::Args args;
    sut.parseSubCommand(argsFullFlag, &args);
    sut.parseFlags(args, &result);
    ASSERT_EQ(result.binaryFlags.size(), 1);
    ASSERT_TRUE(result.binaryFlags.find("save") != result.binaryFlags.end());
    ASSERT_TRUE(result.args[0] == "lib/dep");
}

TEST_F(InputParserTest, CorrectOffsetWhenParsingFlags) {
    Result result;
    sut.parseFlags(argsOneFlag, &result);
    ASSERT_EQ(result.binaryFlags.size(), 1);
    ASSERT_TRUE(result.binaryFlags.find("save") != result.binaryFlags.end());
}

TEST_F(InputParserTest, ParsesShorthandBinaryFlagCorrectly) {
    Result result;
    sut.parseFlags(argsShortFlag, &result);
    ASSERT_EQ(result.binaryFlags.size(), 1);
    ASSERT_TRUE(result.binaryFlags.find("save") != result.binaryFlags.end());
}

TEST_F(InputParserTest, OnlyFlagsThrowsException) {
    cget::InputParser::Args output;
    ASSERT_THROW(sut.parseSubCommand({"--flag"}, &output), std::invalid_argument);
}

TEST_F(InputParserTest, EmptyArgsThrowsException) {
    cget::InputParser::Args output;
    ASSERT_THROW(sut.parseSubCommand({}, &output), std::invalid_argument);
}

TEST_F(InputParserTest, ArgumentsParsedCorrectly) {
    Result result;
    cget::InputParser::Args output;
    sut.parseSubCommand(argsFullFlag, &output);
    sut.parseFlags(output, &result);
    ASSERT_EQ(result.args.size(), 1);
    ASSERT_EQ(result.args[0], "lib/dep");
}