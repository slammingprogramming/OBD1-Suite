#include <gtk/gtk.h>
#include "obd1_interface.h"
#include "data_parser.h"
#include "report_generator.h"

int obd_fd;
GtkWidget *text_view;

// Callback functions for buttons
void on_retrieve_dtc_clicked(GtkButton *button, gpointer user_data) {
    DiagnosticCode dtc_codes[50];
    int count = retrieve_dtc_codes(obd_fd, dtc_codes, 50);
    if (count > 0) {
        generate_report(dtc_codes, count);
        gtk_text_buffer_set_text(gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view)), "DTC Codes retrieved.\n", -1);
    }
}

void on_clear_dtc_clicked(GtkButton *button, gpointer user_data) {
    clear_dtc_codes(obd_fd);
    gtk_text_buffer_set_text(gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view)), "DTC Codes cleared.\n", -1);
}

void create_main_window() {
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), box);

    GtkWidget *retrieve_dtc_btn = gtk_button_new_with_label("Retrieve DTC");
    g_signal_connect(retrieve_dtc_btn, "clicked", G_CALLBACK(on_retrieve_dtc_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(box), retrieve_dtc_btn, FALSE, FALSE, 0);

    GtkWidget *clear_dtc_btn = gtk_button_new_with_label("Clear DTC");
    g_signal_connect(clear_dtc_btn, "clicked", G_CALLBACK(on_clear_dtc_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(box), clear_dtc_btn, FALSE, FALSE, 0);

    text_view = gtk_text_view_new();
    gtk_box_pack_start(GTK_BOX(box), text_view, TRUE, TRUE, 0);

    gtk_widget_show_all(window);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    obd_fd = init_obd_connection("/dev/ttyUSB0");
    if (obd_fd == -1) return 1;

    create_main_window();

    gtk_main();
    close_obd_connection(obd_fd);
    return 0;
}