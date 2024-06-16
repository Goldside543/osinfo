#include <iostream>
#include <sys/utsname.h>

int main() {
    struct utsname info;
    if (uname(&info) == 0) {
        std::cout << "OS: " << info.sysname << " " << info.release << std::endl;
    } else {
        std::cerr << "Error getting system information." << std::endl;
    }
    return 0;
}
