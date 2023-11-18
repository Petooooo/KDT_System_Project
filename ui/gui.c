#include <stdio.h>

#include <system_server.h>
#include <gui.h>
#include <input.h>
#include <web_server.h>

int create_gui()
{
    pid_t systemPid;

    printf("여기서 GUI 프로세스를 생성합니다.\n");

    sleep(3);
    
    switch (systemPid = fork()) {
        case -1:
            printf("Failed to fork on GUI.\n");
        case 0:
            execl("/usr/bin/chromium-browser", "chromium-browser", "http://localhost:8282", NULL);
            break;
    }

    return 0;
}
