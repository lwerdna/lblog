#include <FL/Fl.H>
#include <FL/Fl_Output.H>

#include "Fl_Output_Dnd.h"

Fl_Output_Dnd::Fl_Output_Dnd(int x, int y, int w, int h, const char *label):
    Fl_Text_Display(x, y, w, h, label)
{
    printf("Fl_Output_Dnd constructor\n");
}

int Fl_Output_Dnd::handle(int event)
{
    int rc = 0; /* 0 if not used or understood, 1 if event was used and can be deleted */
    Fl_Text_Buffer *buf;

    switch(event) {
        case FL_DND_ENTER:
            printf("on FL_DND_ENTER\n");
            rc = 1;
            break;
        case FL_DND_DRAG:
            printf("on FL_DND_DRAG\n");
            rc = 1;
            break;
        case FL_DND_RELEASE:
            printf("on FL_DND_RELEASE\n");
            rc = 1;
            break;

        case FL_PASTE:
            //printf("got paste event");
            printf("event text: %s\n", Fl::event_text());
            //printf("event length: %d\n", Fl::event_length());
            attachPaths.push_back(Fl::event_text());
    
            buf = buffer();
            if(buf) {
                buf->text("");
                for(int i=0; i<attachPaths.size(); ++i) {
                    if(buf->length() != 0)
                        buf->append("\n");
                    buf->append(attachPaths[i].c_str());
                }
            }
            else {
                printf("ERROR: buffer() is returning NULL\n");
            }

            rc = 1;
            break;

        default:
            while(0);
            //printf("got event id: %d\n", event);
    }

    return rc;
}

