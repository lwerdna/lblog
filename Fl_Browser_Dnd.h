#include <FL/Fl.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Select_Browser.H>

#include <vector>
#include <string>

class Fl_Browser_Dnd : public Fl_Select_Browser
{
    public:
    Fl_Browser_Dnd(int x, int y, int w, int h, const char *label);
    int handle(int event);
};
