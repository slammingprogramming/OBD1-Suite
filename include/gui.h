#ifndef GUI_H
#define GUI_H

#include <gtk/gtk.h>

void create_main_window();   // Initializes and displays the main GUI window
void on_retrieve_dtc_clicked(GtkButton *button, gpointer user_data); // Handler for retrieving DTC codes
void on_clear_dtc_clicked(GtkButton *button, gpointer user_data);    // Handler for clearing DTC codes

#endif // GUI_H