#include <gtest/gtest.h>
#include "../src/command/init.h"
#include "../src/constants.h"
#include <fstream>
#include <json.hpp>

using namespace cget::constants;
using json = nlohmann::json;
using std::string;

struct InitModelTests : testing::Test {
    virtual void SetUp() {
        std::remove(PACKAGE_FILE.c_str());
    }

    cget::command::Init::Model sut;
};

TEST_F(InitModelTests, RejectsEmptyName) {
    ASSERT_THROW(sut.setName(""), std::invalid_argument);
}

TEST_F(InitModelTests, AcceptsCorrectSemanticVersion) {
    ASSERT_NO_THROW(sut.setSemanticVersion("1.2.3"));
}

TEST_F(InitModelTests, RejectsIncorrectVersion) {
    ASSERT_THROW(sut.setSemanticVersion("abc"), std::invalid_argument);
    ASSERT_THROW(sut.setSemanticVersion("1.1.1.1"), std::invalid_argument);
    ASSERT_THROW(sut.setSemanticVersion("1.1"), std::invalid_argument);
}

TEST_F(InitModelTests, SavesFileToDisk) {
    sut.setName("test");
    sut.setSemanticVersion("1.1.1");
    sut.writePackageFile();
    ASSERT_TRUE(std::ifstream(PACKAGE_FILE));
}

TEST_F(InitModelTests, WritesDataToDisk) {
    sut.setName("test");
    sut.setSemanticVersion("1.1.1");
    sut.setAuthor("Eric");
    sut.setDescription("Description");
    sut.writePackageFile();

    std::ifstream pkg(PACKAGE_FILE);
    std::stringstream buffer;
    buffer << pkg.rdbuf();

    std::string pkgJson = buffer.str();
    auto data = json::parse(pkgJson);

    EXPECT_EQ(data["name"].get<string>(), "test");
    EXPECT_EQ(data["version"].get<string>(), "1.1.1");
    EXPECT_EQ(data["author"].get<string>(), "Eric");
    EXPECT_EQ(data["description"].get<string>(), "Description");
}
