#include <iostream>
#include <fstream>
#include <sys/inotify.h>
#include <unistd.h>
#include <string>

#define EVENT_SIZE (sizeof(struct inotify_event))
#define EVENT_BUF_LEN (1024 * (EVENT_SIZE + 16))

void log_event(std::string event) {
    std::ofstream log_file("directory.log", std::ios_base::app);
    if (log_file.is_open()) {
        log_file << event << std::endl;
        log_file.close();
    } else {
        std::cerr << "Error: Could not open log file" << std::endl;
    }
}

int main() {
    int fd, wd;
    char buffer[EVENT_BUF_LEN];

    // Change working directory to directory where executable is located
    if (chdir("/home/afraz/OperatingSystemsLab/OSProject-daemons") < 0) {
        std::cerr << "Error: Could not change working directory" << std::endl;
        //return 1;
    }

    fd = inotify_init();
    if (fd < 0) {
        std::cerr << "Error: Could not initialize inotify" << std::endl;
        return 1;
    }

    wd = inotify_add_watch(fd, "/home/afraz/OperatingSystemsLab/OSProject-daemons", IN_CREATE | IN_DELETE);
    std::cout << wd;
    if (wd < 0) {
        std::cerr << "Error: Could not watch directory" << std::endl;
        //return 1;
    }

    // Fork to create a daemon process
    pid_t pid = fork();
    if (pid < 0) {
        std::cerr << "Error: Could not fork daemon process" << std::endl;
        return 1;
    } else if (pid > 0) {
        return 0; // Exit parent process
    }

    // Child process continues to monitor directory for changes
    while (1) {
        int length = read(fd, buffer, EVENT_BUF_LEN);
        if (length < 0) {
            std::cerr << "Error: Could not read directory changes" << std::endl;
            return 1;
        }

        int i = 0;
        while (i < length) {
            struct inotify_event *event = (struct inotify_event *) &buffer[i];
            if (event->len) {
                if (event->mask & IN_CREATE) {
                    log_event("File created: " + std::string(event->name));
                } else if (event->mask & IN_DELETE) {
                    log_event("File deleted: " + std::string(event->name));
                }
            }
            i += EVENT_SIZE + event->len;
        }
    }

    // Unreachable code
    return 0;
}

