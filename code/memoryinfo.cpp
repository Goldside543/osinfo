#include <sysinfo.h>


int memoryinfo() {
    std::ifstream meminfo("/proc/meminfo");
    std::string line;
    
    if (meminfo.is_open()) {
        while (std::getline(meminfo, line)) {
            std::cout << line << std::endl;
        }
        meminfo.close();
    } else {
        std::cout << "Unable to open /proc/meminfo" << std::endl;
    }
    
    return 0;
}
