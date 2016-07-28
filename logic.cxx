#include <time.h>

#include "Gui.h"

Gui *g_gui = NULL;

void updateSubdir(void)
{
    char buf[1024];
    const char *pDateStr = g_gui->inputTime->value();
    const char *pTitleStr = g_gui->inputTitle->value();
    strcpy(buf, pDateStr);
    strcat(buf, "_");
    int src=0, dst=strlen(buf), limit=strlen(pTitleStr);
    while(src < limit) {
        char c = pTitleStr[src++];
        if(isalnum(c))
            buf[dst++] = c;
        else
            buf[dst++] = '_';
    }
    buf[dst] = '\0';

    g_gui->outputSubdir->value(buf);
}

void onGuiStart(Gui *gui)
{
    char buf[16];

    g_gui = gui;

    // "calendar time" (internally is secs since epoch)
    time_t ct;
    time(&ct);
    // "brokend down time", has .tm_sec, etc.
    struct tm *bdt;
    bdt = localtime(&ct);
    // %F is ISO 8601 format: YYYY-MM-DD (or %Y-%m-%d)
    strftime(buf, 16, "%F", bdt);

    gui->inputTime->value(buf);
    gui->inputTitle->value("Awesome Topic!");

    gui->outputSubdir->readonly(1);

    updateSubdir();
}

/* callback when the time buffer (internal to time input field) changes
    (normal callback won't trigger during text change) */
void
onInputTimeChange()
{
    printf("%s()\n", __func__);
    updateSubdir();
}

void onInputTitleChange(void)
{
    printf("%s()\n", __func__);
    updateSubdir();
}

void onBrowserClick(Fl_Widget* o, void *)
{
    printf("callback, selection = %d, event_clicks = %d\n",
        ((Fl_Browser*)o)->value(), Fl::event_clicks());
}

