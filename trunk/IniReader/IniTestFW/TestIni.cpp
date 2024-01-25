#include "TestIni.h"
#include <iostream>
#if defined(WIN32) || defined(_WIN32)
#include <direct.h>
#elif defined(linux) || defined(__linux__)
#include <unistd.h>
#endif

#include "IniParser.h"

const char* INI_PATH = "./Config/SysConfig.ini";

TestIni::TestIni()
{

}

void TestIni::TestReadIni()
{
    char path[256]={};
    _getcwd(path, 256);
    std::cout << "INI file path is: "<< path << std::endl;

    IniParser iParser(INI_PATH);

    if (iParser.ParseError() < 0) {
        std::cout << "Can't load 'test.ini'\n";
    }
    std::cout << "Config loaded from 'test.ini': version="
              << iParser.GetInteger("protocol", "version", -1) << ", unsigned version="
              << iParser.GetUnsigned("protocol", "version", -1) << ", trillion="
              << iParser.GetInteger64("user", "trillion", -1) << ", unsigned trillion="
              << iParser.GetUnsigned64("user", "trillion", -1) << ", name="
              << iParser.Get("user", "name", "UNKNOWN") << ", email="
              << iParser.Get("user", "email", "UNKNOWN") << ", pi="
              << iParser.GetReal("user", "pi", -1) << ", active="
              << iParser.GetBoolean("user", "active", true) << "\n";
    std::cout << "Has values: user.name=" << iParser.HasValue("user", "name")
              << ", user.nose=" << iParser.HasValue("user", "nose") << "\n";
    std::cout << "Has sections: user=" << iParser.HasSection("user")
              << ", fizz=" << iParser.HasSection("fizz") << "\n";
}
