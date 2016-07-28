#include <time.h>

#include <string>

#include "Gui.h"

Gui *g_gui = NULL;

std::string getAttachSelection(void)
{
    int lineNo = g_gui->browserAttachments->value();
    if(lineNo == 0) return "";
    const char *text = g_gui->browserAttachments->text(lineNo);
    if(text == NULL) return "";
    return std::string(text);
}

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
    
    std::string tmp("new blog file: ");
    tmp += buf;
    g_gui->displayLog->add(tmp.c_str());
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

void onBtnAttachRemove(void)
{
    int lineNo = g_gui->browserAttachments->value();
    if(lineNo != 0) {
        g_gui->browserAttachments->remove(lineNo);
    }
    else {
        printf("ERROR: no selection to delete\n");
    }
}

void addAttachmentResizeEntry(const char *suffix)
{
    std::string path = getAttachSelection();
    if(path.empty()) {
        printf("ERROR: empty selection, cannot resize\n");
    }
    else {
        int idx = path.find_last_of(".");
        if(idx == std::string::npos) {
            printf("ERROR: expected image file to have extension\n");
        }
        else {
            std::string base = path.substr(0, idx);
            std::string ext = path.substr(idx+1);
            std::string newPath = base + suffix + "." + ext;
            g_gui->browserAttachments->add(newPath.c_str());
        }
    }
}  

void onBtnAttachResize64x64(void)
{
    addAttachmentResizeEntry("_64x64");
}

void onBtnAttachResize128x128(void)
{
    addAttachmentResizeEntry("_128x128");
}

void onBtnAttachResizeQQx64(void)
{
    addAttachmentResizeEntry("_QQx64");
}

void onBtnAttachResizeQQx128(void)
{
    addAttachmentResizeEntry("_QQx128");
}

void onBtnAttachAdd(void)
{
    g_gui->displayLog->add(__func__);
}


