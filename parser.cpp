#include <fstream>
#include <string>
#include <unordered_map>

class ConfigParser {
public:
    std::unordered_map<std::string, std::string> parse(const std::string& path) {
        std::unordered_map<std::string, std::string> config;
        std::ifstream file(path);

        std::string line;
        while (std::getline(file, line)) {
            auto pos = line.find('=');
            if (pos == std::string::npos) continue;

            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
            config[key] = value;
        }
        return config;
    }
};

int main() {
    ConfigParser parser;
    parser.parse("config.env");
    return 0;
}
