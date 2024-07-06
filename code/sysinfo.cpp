#include <sysinfo.h>
int cpuinfo;
int memoryinfo;

int main() {
    struct utsname info;
    if (uname(&info) == 0) {
        std::cout << "OS: " << info.sysname << " " << info.release << std::endl;
    } else {
        std::cerr << "Error getting system information." << std::endl;
    }
    return 0;
}

int cpuinfo() {
    FILE *cpuinfo = fopen("/proc/cpuinfo", "rb");
    char *line = NULL;
    size_t size = 0;

    if (cpuinfo != NULL) {
        while (getline(&line, &size, cpuinfo) != -1) {
            puts(line);
        }
        free(line);
        fclose(cpuinfo);
    } else {
        printf("Error opening /proc/cpuinfo\n");
    }

    return 0;
}

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
