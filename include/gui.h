#ifndef GUI_H
#define GUI_H

#include <gtk/gtk.h>

void on_activate(GtkApplication *app, gpointer user_data);
void create_sidebar(GtkWidget *sidebar);
void create_main_content(GtkWidget *main_area);

#endif // GUI_H