// generated by Fast Light User Interface Designer (fluid) version 1.0303

#include "Gui.h"
#include "logic.h"
#include <FL/Fl_Text_Buffer.h>

void Gui::cb_inputTime_i(Fl_Input*, void*) {
  onInputTimeChange();
}
void Gui::cb_inputTime(Fl_Input* o, void* v) {
  ((Gui*)(o->parent()->user_data()))->cb_inputTime_i(o,v);
}

void Gui::cb_inputTitle_i(Fl_Input*, void*) {
  onInputTitleChange();
}
void Gui::cb_inputTitle(Fl_Input* o, void* v) {
  ((Gui*)(o->parent()->user_data()))->cb_inputTitle_i(o,v);
}

void Gui::cb_remove_i(Fl_Button*, void*) {
  onBtnAttachRemove();
}
void Gui::cb_remove(Fl_Button* o, void* v) {
  ((Gui*)(o->parent()->user_data()))->cb_remove_i(o,v);
}

void Gui::cb_64x64_i(Fl_Button*, void*) {
  onBtnAttachResize64x64();
}
void Gui::cb_64x64(Fl_Button* o, void* v) {
  ((Gui*)(o->parent()->user_data()))->cb_64x64_i(o,v);
}

void Gui::cb_128x128_i(Fl_Button*, void*) {
  onBtnAttachResize128x128();
}
void Gui::cb_128x128(Fl_Button* o, void* v) {
  ((Gui*)(o->parent()->user_data()))->cb_128x128_i(o,v);
}

void Gui::cb_x64_i(Fl_Button*, void*) {
  onBtnAttachResizeQQx64();
}
void Gui::cb_x64(Fl_Button* o, void* v) {
  ((Gui*)(o->parent()->user_data()))->cb_x64_i(o,v);
}

void Gui::cb_x128_i(Fl_Button*, void*) {
  onBtnAttachResizeQQx128();
}
void Gui::cb_x128(Fl_Button* o, void* v) {
  ((Gui*)(o->parent()->user_data()))->cb_x128_i(o,v);
}

void Gui::cb_add_i(Fl_Button*, void*) {
  onBtnAttachAdd();
}
void Gui::cb_add(Fl_Button* o, void* v) {
  ((Gui*)(o->parent()->user_data()))->cb_add_i(o,v);
}

Fl_Double_Window* Gui::make_window() {
  Fl_Double_Window* w;
  { Fl_Double_Window* o = new Fl_Double_Window(530, 401, "lblog");
    w = o;
    o->user_data((void*)(this));
    { inputTime = new Fl_Input(4, 4, 84, 24);
      inputTime->callback((Fl_Callback*)cb_inputTime);
    } // Fl_Input* inputTime
    { inputTitle = new Fl_Input(90, 4, 356, 24);
      inputTitle->callback((Fl_Callback*)cb_inputTitle);
    } // Fl_Input* inputTitle
    { inputTags = new Fl_Input(448, 4, 79, 24);
    } // Fl_Input* inputTags
    { displayLog = new Fl_Browser(4, 295, 521, 101);
      displayLog->color(FL_FOREGROUND_COLOR);
      displayLog->textcolor(FL_BACKGROUND2_COLOR);
    } // Fl_Browser* displayLog
    { Fl_Browser_Dnd* o = browserAttachments = new Fl_Browser_Dnd(4, 166, 521, 104, "attachments:");
      browserAttachments->box(FL_NO_BOX);
      browserAttachments->color(FL_BACKGROUND2_COLOR);
      browserAttachments->selection_color(FL_SELECTION_COLOR);
      browserAttachments->labeltype(FL_NORMAL_LABEL);
      browserAttachments->labelfont(0);
      browserAttachments->labelsize(14);
      browserAttachments->labelcolor(FL_FOREGROUND_COLOR);
      browserAttachments->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      browserAttachments->when(FL_WHEN_RELEASE_ALWAYS);
      o->type(FL_HOLD_BROWSER);
      o->callback(onBrowserClick);
    } // Fl_Browser_Dnd* browserAttachments
    { Fl_Button* o = new Fl_Button(72, 272, 63, 20, "remove");
      o->callback((Fl_Callback*)cb_remove);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(140, 272, 63, 20, "64x64");
      o->callback((Fl_Callback*)cb_64x64);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(208, 272, 63, 20, "128x128");
      o->callback((Fl_Callback*)cb_128x128);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(276, 272, 63, 20, "?\?x64");
      o->callback((Fl_Callback*)cb_x64);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(344, 272, 63, 20, "?\?x128");
      o->callback((Fl_Callback*)cb_x128);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(4, 272, 63, 20, "add");
      o->callback((Fl_Callback*)cb_add);
    } // Fl_Button* o
    o->end();
  } // Fl_Double_Window* o
  return w;
}

int main(int argc, char **argv) {
  Gui *gui = new Gui();
  Fl_Double_Window *w = gui->make_window();
  w->show();
  onGuiStart(gui);
  printf("Hello, World!\n");
  return Fl::run();
}
