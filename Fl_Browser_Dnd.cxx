#include <FL/Fl.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Select_Browser.H>

#include "Fl_Browser_Dnd.h"

Fl_Browser_Dnd::Fl_Browser_Dnd(int x, int y, int w, int h, const char *label):
    Fl_Select_Browser(x, y, w, h, label)
{
    printf("Fl_Browser_Dnd constructor\n");
}

int Fl_Browser_Dnd::handle(int event)
{
    int rc = 0; /* 0 if not used or understood, 1 if event was used and can be deleted */
    switch(event) {
        case FL_DND_ENTER:
            //printf("on FL_DND_ENTER\n");
            rc = 1;
            break;
        case FL_DND_DRAG:
            //printf("on FL_DND_DRAG\n");
            rc = 1;
            break;
        case FL_DND_RELEASE:
            //printf("on FL_DND_RELEASE\n");
            rc = 1;
            break;

        case FL_PASTE:
            //printf("got paste event");
            printf("event text: %s\n", Fl::event_text());
            //printf("event length: %d\n", Fl::event_length());
            add(Fl::event_text());
    
            rc = 1;
            break;

        default:
            while(0);
            //printf("got event id: %d\n", event);
    }

    if(rc) return rc;
    else return Fl_Select_Browser::handle(event);
}

