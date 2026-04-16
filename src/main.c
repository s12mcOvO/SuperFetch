#define _POSIX_C_SOURCE 200112L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define VERSION "1.0.0"

typedef struct {
    const char *name;
    const char *display_name;
    void (*func)(void);
} Module;

static int no_color = 0;
#define C_RESET   no_color ? "" : "\033[0m"
#define C_BOLD    no_color ? "" : "\033[1;34m"

static void print_field(const char *label, const char *value) {
    printf("%s%s:%s %s\n", C_BOLD, label, C_RESET, value);
}

void print_os_info();
void print_kernel_info();
void print_uptime();
void print_memory();
void print_cpu();
void print_disk();
void print_packages();
void print_shell();
void print_resolution();
void print_de();
void print_wm();
void print_terminal();
void print_load();
void print_swap();
void print_battery();
void print_locale();
void print_hostname();

void print_ascii();
void print_help();
void print_title();
void print_separator();
void print_break();
void generate_ai_ascii();

Module modules[] = {
    {"title", "Title", NULL},
    {"separator", "Separator", NULL},
    {"os", "Operating System", print_os_info},
    {"host", "Hostname", print_hostname},
    {"kernel", "Kernel", print_kernel_info},
    {"uptime", "Uptime", print_uptime},
    {"shell", "Shell", print_shell},
    {"de", "Desktop Environment", print_de},
    {"wm", "Window Manager", print_wm},
    {"terminal", "Terminal", print_terminal},
    {"cpu", "CPU", print_cpu},
    {"memory", "Memory", print_memory},
    {"swap", "Swap", print_swap},
    {"disk", "Disk", print_disk},
    {"load", "System Load", print_load},
    {"packages", "Packages", print_packages},
    {"battery", "Battery", print_battery},
    {"locale", "Locale", print_locale},
    {"break", "Break", NULL},
    {"colors", "Colors", NULL},
    {NULL, NULL, NULL}
};

static const char *ai_patterns[] = {
    "███████╗██╗   ██╗██████╗ ███████╗██████╗ ███████╗███████╗████████╗ ██████╗██╗  ██╗\n"
    "██╔════╝██║   ██║██╔══██╗██╔════╝██╔══██╗██╔════╝██╔════╝╚══██╔══╝██╔════╝██║  ██║\n"
    "███████╗██║   ██║██████╔╝█████╗  ██████╔╝█████╗  █████╗     ██║   ██║     ███████║\n"
    "╚════██║██║   ██║██╔═══╝ ██╔══╝  ██╔══██╗██╔══╝  ██╔══╝     ██║   ██║     ██╔══██║\n"
    "███████║╚██████╔╝██║     ███████╗██║  ██║██║     ███████╗   ██║   ╚██████╗██║  ██║\n"
    "╚══════╝ ╚═════╝ ╚═╝     ╚══════╝╚═╝  ╚═╝╚═╝     ╚══════╝   ╚═╝    ╚═════╝╚═╝  ╚═╝",

    "╔══════════════════════════════════════════════════════════════════════════════╗\n"
    "║                           BrightS System                                   ║\n"
    "║                                                                            ║\n"
    "║                  ███████╗██╗   ██╗██████╗ ███████╗██████╗                 ║\n"
    "║                  ██╔════╝██║   ██║██╔══██╗██╔════╝██╔══██╗                ║\n"
    "║                  ███████╗██║   ██║██████╔╝█████╗  ██████╔╝                ║\n"
    "║                  ╚════██║██║   ██║██╔═══╝ ██╔══╝  ██╔══██╗                ║\n"
    "║                  ███████║╚██████╔╝██║     ███████╗██║  ██║                ║\n"
    "║                  ╚══════╝ ╚═════╝ ╚═╝     ╚══════╝╚═╝  ╚═╝                ║\n"
    "║                                                                            ║\n"
    "║                        Fast, Beautiful, Informative                       ║\n"
    "╚══════════════════════════════════════════════════════════════════════════════╝",

    "    ____        __           ____  ____ \n"
    "   / __ )____  / /_____     / __ \\/  _/\n"
    "  / __  / __ \\/ __/ __ \\   / /_/ / /  \n"
    " / /_/ / /_/ / /_/ /_/ /  / ____/ /   \n"
    " \\____/\\____/\\__/\\____/  /_/   /___/   \n"
    "                                      \n"
    "   BrightS SuperFetch v" VERSION "    \n"
};

#define AI_PATTERNS_COUNT (sizeof(ai_patterns) / sizeof(ai_patterns[0]))

void print_os_info() {
    print_field("OS", "BrightS Linux");
}

void print_kernel_info() {
    print_field("Kernel", "BrightS Kernel 0.1.2.2");
}

void print_uptime() {
    char buf[64];
    snprintf(buf, sizeof(buf), "%d days, %d hours, %d minutes", 1, 2, 30);
    print_field("Uptime", buf);
}

void print_memory() {
    char buf[64];
    snprintf(buf, sizeof(buf), "%d MB / %d MB", 512, 1024);
    print_field("Memory", buf);
}

void print_cpu() {
    print_field("CPU", "BrightS CPU @ 2.0GHz");
}

void print_disk() {
    char buf[64];
    snprintf(buf, sizeof(buf), "%d GB / %d GB", 10, 50);
    print_field("Disk", buf);
}

void print_packages() {
    print_field("Packages", "Unknown (bspm)");
}

void print_shell() {
    char *shell = getenv("SHELL");
    if (shell) {
        char *base = strrchr(shell, '/');
        print_field("Shell", base ? base + 1 : shell);
    } else {
        print_field("Shell", "BrightS Shell");
    }
}

void print_resolution() {
    print_field("Resolution", "1920x1080");
}

void print_de() {
    print_field("DE", "BrightS Desktop");
}

void print_wm() {
    print_field("WM", "BrightS Window Manager");
}

void print_terminal() {
    print_field("Terminal", "BrightS Terminal");
}

void print_load() {
    char buf[64];
    snprintf(buf, sizeof(buf), "%.2f, %.2f, %.2f", 0.15, 0.12, 0.08);
    print_field("Load", buf);
}

void print_swap() {
    print_field("Swap", "N/A");
}

void print_battery() {
    print_field("Battery", "N/A");
}

void print_locale() {
    char *lc = getenv("LANG");
    print_field("Locale", lc ? lc : "en_US.UTF-8");
}

void print_hostname() {
    char hostname[64] = "bright-pc";
    #ifdef __linux__
    gethostname(hostname, sizeof(hostname));
    #endif
    print_field("Host", hostname);
}

void print_colors() {
    printf("%sColors:%s ", C_BOLD, C_RESET);
    for (int i = 0; i < 8; i++) {
        if (no_color) printf("■   ");
        else printf("\033[4%dm   ", i);
    }
    printf("%s\n", C_RESET);
    printf("         ");
    for (int i = 8; i < 16; i++) {
        if (no_color) printf("■   ");
        else printf("\033[4%dm   ", i);
    }
    printf("%s\n", C_RESET);
}

void print_ascii() {
    if (no_color) {
        printf("BrightS System\n");
        printf("==============\n\n");
    } else {
        printf("\033[1;34m");
        printf("██████╗ ██████╗ ██╗ ██████╗ ██╗  ██╗████████╗███████╗\n");
        printf("██╔══██╗██╔══██╗██║██╔════╝ ██║  ██║╚══██╔══╝██╔════╝\n");
        printf("██████╔╝██████╔╝██║██║  ███╗███████║   ██║   ███████╗\n");
        printf("██╔══██╗██╔══██╗██║██║   ██║██╔══██║   ██║   ╚════██║\n");
        printf("██████╔╝██║  ██║██║╚██████╔╝██║  ██║   ██║   ███████║\n");
        printf("╚═════╝ ╚═╝  ╚═╝╚═╝ ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚══════╝\n");
        printf("\033[0m\n");
    }
}

void generate_ai_ascii() {
    srand((unsigned int)time(NULL));
    int pattern_idx = rand() % AI_PATTERNS_COUNT;
    
    if (no_color) {
        printf("BrightS System\n");
    } else {
        printf("\033[1;36m%s\033[0m\n", ai_patterns[pattern_idx]);
    }
}

void print_help() {
    printf("SuperFetch v%s - System Information Tool\n\n", VERSION);
    printf("Usage: superfetch [OPTIONS]\n\n");
    printf("Options:\n");
    printf("  -h, --help          Show this help message\n");
    printf("  -v, --version       Show version information\n");
    printf("  -n, --no-color      Disable colored output\n");
    printf("  -a, --ascii PATH    Use custom ASCII art file\n");
    printf("  --ai-ascii          Generate random ASCII art\n");
    printf("  -l, --list          List available modules\n");
    printf("\nExamples:\n");
    printf("  superfetch          Display system info\n");
    printf("  superfetch -n       Display without colors\n");
    printf("  superfetch --ai-ascii   Use random logo\n");
}

void print_title() {
    char *user = getenv("USER");
    char hostname[64] = "bright-pc";
    
    #ifdef __linux__
    gethostname(hostname, sizeof(hostname));
    #endif
    
    if (no_color) {
        printf("%s@%s\n", user ? user : "user", hostname);
    } else {
        printf("\033[1;35m%s@%s\033[0m\n", user ? user : "user", hostname);
    }
}

void print_separator() {
    if (no_color) {
        printf("-------------\n");
    } else {
        printf("\033[1;34m-------------\033[0m\n");
    }
}

void print_break() {
    printf("\n");
}

static void print_custom_ascii(const char *path) {
    FILE *f = fopen(path, "r");
    if (!f) {
        fprintf(stderr, "Error: Cannot open %s\n", path);
        return;
    }
    char line[512];
    while (fgets(line, sizeof(line), f)) {
        fputs(line, stdout);
    }
    fclose(f);
}

static void list_modules(void) {
    printf("Available modules:\n");
    for (Module *mod = modules; mod->name; mod++) {
        printf("  %-12s %s\n", mod->name, mod->display_name);
    }
}

int main(int argc, char *argv[]) {
    int use_ai_ascii = 0;
    const char *custom_ascii = NULL;
    int show_version = 0;
    int show_help = 0;
    int list_modules_flag = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {
            show_help = 1;
        } else if (strcmp(argv[i], "--version") == 0 || strcmp(argv[i], "-v") == 0) {
            show_version = 1;
        } else if (strcmp(argv[i], "--no-color") == 0 || strcmp(argv[i], "-n") == 0) {
            no_color = 1;
        } else if (strcmp(argv[i], "--ai-ascii") == 0) {
            use_ai_ascii = 1;
        } else if (strcmp(argv[i], "--ascii") == 0 || strcmp(argv[i], "-a") == 0) {
            if (i + 1 < argc) custom_ascii = argv[++i];
        } else if (strcmp(argv[i], "--list") == 0 || strcmp(argv[i], "-l") == 0) {
            list_modules_flag = 1;
        }
    }

    if (show_help) {
        print_help();
        return 0;
    }

    if (show_version) {
        printf("SuperFetch v%s\n", VERSION);
        return 0;
    }

    if (list_modules_flag) {
        list_modules();
        return 0;
    }

    if (custom_ascii) {
        print_custom_ascii(custom_ascii);
    } else if (use_ai_ascii) {
        generate_ai_ascii();
    } else {
        print_ascii();
    }

    printf("\n");

    for (Module *mod = modules; mod->name; mod++) {
        if (mod->func) {
            mod->func();
        } else if (strcmp(mod->name, "title") == 0) {
            print_title();
        } else if (strcmp(mod->name, "separator") == 0) {
            print_separator();
        } else if (strcmp(mod->name, "break") == 0) {
            print_break();
        } else if (strcmp(mod->name, "colors") == 0) {
            print_colors();
        }
    }

    printf("\n");
    return 0;
}
