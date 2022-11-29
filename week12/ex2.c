#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

static const char *const evval[3] = {
    "RELEASED",
    "PRESSED ",
};

int main(void)
{
    int fd;
    struct input_event event;
    const char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";

    fd = open(dev, O_RDONLY);
    while (true)
    {
        read(fd, &event, sizeof event);

        if (event.value <= 2 && event.value >= 0 && event.type == EV_KEY)
        {
            printf("%s 0x%04x (%d)\n", evval[event.value], (int)event.code, (int)event.code);
        }
    }
    return 0;
}