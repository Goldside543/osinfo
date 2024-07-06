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
