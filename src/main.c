#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// SuperFetch - System Information Tool
// Inspired by fastfetch

#define VERSION "1.0.0"

typedef struct {
    const char *name;
    const char *display_name;
    void (*func)(void);
} Module;

void print_os_info() {
    printf("\033[1;34mOS:\033[0m BrightS Linux\n");
}

void print_kernel_info() {
    printf("\033[1;34mKernel:\033[0m BrightS Kernel 0.1.2.2\n");
}

void print_uptime() {
    printf("\033[1;34mUptime:\033[0m Unknown\n");
}

void print_memory() {
    printf("\033[1;34mMemory:\033[0m 512 MB / 1024 MB\n");
}

void print_cpu() {
    printf("\033[1;34mCPU:\033[0m BrightS CPU @ 2.0GHz\n");
}

void print_disk() {
    printf("\033[1;34mDisk:\033[0m 10 GB / 50 GB\n");
}

void print_colors() {
    printf("\033[1;34mColors:\033[0m ");
    for (int i = 0; i < 8; i++) {
        printf("\033[4%dm   ", i);
    }
    printf("\033[0m\n");
    printf("         ");
    for (int i = 8; i < 16; i++) {
        printf("\033[4%dm   ", i);
    }
    printf("\033[0m\n");
}

Module modules[] = {
    {"os", "Operating System", print_os_info},
    {"kernel", "Kernel", print_kernel_info},
    {"uptime", "Uptime", print_uptime},
    {"memory", "Memory", print_memory},
    {"cpu", "CPU", print_cpu},
    {"disk", "Disk", print_disk},
    {"colors", "Colors", print_colors},
    {NULL, NULL, NULL}
};

void print_ascii() {
    printf("\033[1;34m");
    printf("██████╗ ██████╗ ██╗ ██████╗ ██╗  ██╗████████╗███████╗\n");
    printf("██╔══██╗██╔══██╗██║██╔════╝ ██║  ██║╚══██╔══╝██╔════╝\n");
    printf("██████╔╝██████╔╝██║██║  ███╗███████║   ██║   ███████╗\n");
    printf("██╔══██╗██╔══██╗██║██║   ██║██╔══██║   ██║   ╚════██║\n");
    printf("██████╔╝██║  ██║██║╚██████╔╝██║  ██║   ██║   ███████║\n");
    printf("╚═════╝ ╚═╝  ╚═╝╚═╝ ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚══════╝\n");
    printf("\033[0m\n");
}

void print_help() {
    printf("SuperFetch v%s - System Information Tool\n\n", VERSION);
    printf("Usage: superfetch [OPTIONS]\n\n");
    printf("Options:\n");
    printf("  --help, -h          Show this help message\n");
    printf("  --version, -v       Show version information\n");
    printf("  --no-color          Disable colored output\n");
    printf("  --ascii PATH        Use custom ASCII art file\n");
    printf("  --theme THEME       Use specific theme\n");
    printf("\nAvailable modules:\n");
    for (Module *mod = modules; mod->name; mod++) {
        printf("  %-10s %s\n", mod->name, mod->display_name);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {
            print_help();
            return 0;
        } else if (strcmp(argv[i], "--version") == 0 || strcmp(argv[i], "-v") == 0) {
            printf("SuperFetch v%s\n", VERSION);
            return 0;
        }
    }

    // Print ASCII art
    print_ascii();

    // Print separator
    printf("\n");

    // Print system information modules
    for (Module *mod = modules; mod->name; mod++) {
        mod->func();
    }

    printf("\n");
    return 0;
}