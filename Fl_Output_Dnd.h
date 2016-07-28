#include <FL/Fl.H>
#include <FL/Fl_Text_Display.H>

#include <vector>
#include <string>

class Fl_Output_Dnd : public Fl_Text_Display
{
    std::vector<std::string> attachPaths;

    public:
    Fl_Output_Dnd(int x, int y, int w, int h, const char *label);
    int handle(int event);
};
