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

void print_packages() {
    printf("\033[1;34mPackages:\033[0m Unknown (bspm)\n");
}

void print_shell() {
    printf("\033[1;34mShell:\033[0m BrightS Shell\n");
}

void print_resolution() {
    printf("\033[1;34mResolution:\033[0m 1920x1080\n");
}

void print_de() {
    printf("\033[1;34mDE:\033[0m BrightS Desktop\n");
}

void print_wm() {
    printf("\033[1;34mWM:\033[0m BrightS Window Manager\n");
}

void print_terminal() {
    printf("\033[1;34mTerminal:\033[0m BrightS Terminal\n");
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
    {"title", "Title", NULL},  // Special case
    {"separator", "Separator", NULL},  // Special case
    {"os", "Operating System", print_os_info},
    {"kernel", "Kernel", print_kernel_info},
    {"uptime", "Uptime", print_uptime},
    {"packages", "Packages", print_packages},
    {"shell", "Shell", print_shell},
    {"resolution", "Resolution", print_resolution},
    {"de", "Desktop Environment", print_de},
    {"wm", "Window Manager", print_wm},
    {"terminal", "Terminal", print_terminal},
    {"cpu", "CPU", print_cpu},
    {"gpu", "GPU", NULL},  // Not implemented yet
    {"memory", "Memory", print_memory},
    {"swap", "Swap", NULL},  // Not implemented yet
    {"disk", "Disk", print_disk},
    {"battery", "Battery", NULL},  // Not implemented yet
    {"locale", "Locale", NULL},  // Not implemented yet
    {"break", "Break", NULL},  // Special case
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

/* AI-generated ASCII art patterns */
const char *ai_patterns[] = {
    "███████╗██╗   ██╗██████╗ ███████╗██████╗ ███████╗███████╗████████╗ ██████╗██╗  ██╗\n"
    "██╔════╝██║   ██║██╔══██╗██╔════╝██╔══██╗██╔════╝██╔════╝╚══██╔══╝██╔════╝██║  ██║\n"
    "███████╗██║   ██║██████╔╝█████╗  ██████╔╝█████╗  █████╗     ██║   ██║     ███████║\n"
    "╚════██║██║   ██║██╔═══╝ ██╔══╝  ██╔══██╗██╔══╝  ██╔══╝     ██║   ██║     ██╔══██║\n"
    "███████║╚██████╔╝██║     ███████╗██║  ██║██║     ███████╗   ██║   ╚██████╗██║  ██║\n"
    "╚══════╝ ╚═════╝ ╚═╝     ╚══════╝╚═╝  ╚═╝╚═╝     ╚══════╝   ╚═╝    ╚═════╝╚═╝  ╚═╝",

    "╔══════════════════════════════════════════════════════════════════════════════╗\n"
    "║                           🌟 BrightS System 🌟                            ║\n"
    "║                                                                            ║\n"
    "║                  ███████╗██╗   ██╗██████╗ ███████╗██████╗                 ║\n"
    "║                  ██╔════╝██║   ██║██╔══██╗██╔════╝██╔══██╗                ║\n"
    "║                  ███████╗██║   ██║██████╔╝█████╗  ██████╔╝                ║\n"
    "║                  ╚════██║██║   ██║██╔═══╝ ██╔══╝  ██╔══██╗                ║\n"
    "║                  ███████║╚██████╔╝██║     ███████╗██║  ██║                ║\n"
    "║                  ╚══════╝ ╚═════╝ ╚═╝     ╚══════╝╚═╝  ╚═╝                ║\n"
    "║                                                                            ║\n"
    "║                        ✨ Fast, Beautiful, Informative ✨                ║\n"
    "╚══════════════════════════════════════════════════════════════════════════════╝",

    "    ____        __           ____  ____ \n"
    "   / __ )____  / /_____     / __ \\/  _/\n"
    "  / __  / __ \\/ __/ __ \\   / /_/ / /  \n"
    " / /_/ / /_/ / /_/ /_/ /  / ____/ /   \n"
    " \\____/\\____/\\__/\\____/  /_/   /___/   \n"
    "                                      \n"
    "   BrightS SuperFetch v" VERSION "    \n",

    "🐧 BrightS Linux 🐧\n"
    "━━━━━━━━━━━━━━━━━━━━━\n"
    "  ████████\n"
    "  ██    ██\n"
    "  ██    ██\n"
    "  ██    ██\n"
    "  ████████\n"
    "━━━━━━━━━━━━━━━━━━━━━"
};

#define AI_PATTERNS_COUNT (sizeof(ai_patterns) / sizeof(ai_patterns[0]))

/* Generate AI-powered ASCII art */
void generate_ai_ascii() {
    /* Seed random number generator */
    srand(time(NULL));

    /* Select random pattern */
    int pattern_idx = rand() % AI_PATTERNS_COUNT;

    printf("\033[1;36m");  /* Cyan color */
    printf("%s", ai_patterns[pattern_idx]);
    printf("\033[0m\n");   /* Reset color */
}

void print_help() {
    printf("SuperFetch v%s - System Information Tool\n\n", VERSION);
    printf("Usage: superfetch [OPTIONS]\n\n");
    printf("Options:\n");
    printf("  --help, -h          Show this help message\n");
    printf("  --version, -v       Show version information\n");
    printf("  --no-color          Disable colored output\n");
    printf("  --ascii PATH        Use custom ASCII art file\n");
    printf("  --ai-ascii          Generate AI-powered ASCII art\n");
    printf("  --theme THEME       Use specific theme\n");
    printf("\nAvailable modules:\n");
    for (Module *mod = modules; mod->name; mod++) {
        printf("  %-10s %s\n", mod->name, mod->display_name);
    }
    printf("\n");
}

void print_title() {
    printf("\033[1;35m%s@bright-pc\033[0m\n", getenv("USER") ?: "user");
}

void print_separator() {
    printf("\033[1;34m─────────────\033[0m\n");
}

void print_break() {
    printf("\n");
}

int main(int argc, char *argv[]) {
    int use_ai_ascii = 0;

    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {
            print_help();
            return 0;
        } else if (strcmp(argv[i], "--version") == 0 || strcmp(argv[i], "-v") == 0) {
            printf("SuperFetch v%s\n", VERSION);
            return 0;
        } else if (strcmp(argv[i], "--ai-ascii") == 0) {
            use_ai_ascii = 1;
        }
    }

    // Print ASCII art
    if (use_ai_ascii) {
        generate_ai_ascii();
    } else {
        print_ascii();
    }

    // Print separator
    printf("\n");

    // Print system information modules
    for (Module *mod = modules; mod->name; mod++) {
        if (mod->func) {
            mod->func();
        } else if (strcmp(mod->name, "title") == 0) {
            print_title();
        } else if (strcmp(mod->name, "separator") == 0) {
            print_separator();
        } else if (strcmp(mod->name, "break") == 0) {
            print_break();
        }
    }

    printf("\n");
    return 0;
}