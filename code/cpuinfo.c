#include <osinfo.h>

int main() {
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
