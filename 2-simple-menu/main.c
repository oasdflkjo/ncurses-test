#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <ncurses.h>

struct menu_item
{
    char *name;
    bool hilighted;
    void (*callback)();
};

void callback_exit()
{
    endwin();
    exit(0);
}

int main()
{
    struct menu_item items[] = {
        {"Item 1", false, NULL},
        {"Item 2", false, NULL},
        {"EXIT", false, callback_exit}};
    int selected = 0;
    int key;
    int i;
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    bool exit = false;
    while (exit == false)
    {
        for (i = 0; i < 3; i++)
        {
            if (i == selected)
            {
                attron(A_REVERSE);
            }
            mvprintw(i + 1, 1, "%s", items[i].name);
            attroff(A_REVERSE);
        }
        key = getch();
        switch (key)
        {
        case KEY_UP:
            selected--;
            if (selected < 0)
            {
                selected = 0;
            }
            break;
        case KEY_DOWN:
            selected++;
            if (selected > 2)
            {
                selected = 2;
            }
            break;
        case 10:
            if (items[selected].callback != NULL)
            {
                items[selected].callback();
            }
            break;
        }
    }
}