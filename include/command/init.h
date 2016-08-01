#pragma once
#include <command/command.h>
#include <functional>

namespace cget {
    namespace command {
        class Init : public Command {
        private:
            void eval(
                    const std::string& prompt,
                    std::function<void(const std::string&)> f,
                    const std::string& defaultValue = "");

        public:
            class Model {
                struct Package {
                    std::string name;
                    std::string version;
                    std::string description;
                    std::string author;
                } _package;

            public:
                void setName(const std::string& name);
                void setSemanticVersion(const std::string& version);
                void setDescription(const std::string& desc);
                void setAuthor(const std::string& author);
                std::string getJSONRepresentation();
                void writePackageFile();
            };

            Init(const std::string &_name);
            int invoke(const std::vector<std::string> &args) override;
        };
    }
}