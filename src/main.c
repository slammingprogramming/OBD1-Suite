#include "connection.h"
#include "gui.h"
#include <stdio.h>
#include <gtk/gtk.h>

// Function to create an input dialog for serial port
static char* get_serial_port_from_user(GtkWindow *parent) {
    GtkWidget *dialog;
    GtkWidget *entry;
    GtkDialogFlags flags = GTK_DIALOG_MODAL;
    char *port = NULL;

    // Create a dialog for serial port input
    dialog = gtk_dialog_new_with_buttons("Enter Serial Port",
                                         parent,
                                         flags,
                                         ("OK"),
                                         GTK_RESPONSE_OK,
                                         ("Cancel"),
                                         GTK_RESPONSE_CANCEL,
                                         NULL);

    // Create an entry widget for user input
    entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(gtk_dialog_get_content_area(GTK_DIALOG(dialog))), entry, TRUE, TRUE, 0);
    gtk_widget_show(entry);

    // Run the dialog
    gtk_widget_show(dialog);
    int response = gtk_dialog_run(GTK_DIALOG(dialog));

    if (response == GTK_RESPONSE_OK) {
        const char *port_entry_text = gtk_entry_get_text(GTK_ENTRY(entry));
        port = g_strdup(port_entry_text);  // Duplicate the string for use
    }

    // Destroy the dialog
    gtk_widget_destroy(dialog);
    return port;
}

// Main function for the OBD-I Debugging Suite
int main(int argc, char *argv[]) {
    // Ensure that the GTK library is initialized
    gtk_init(&argc, &argv);

    char *serial_port = NULL;

    // Check if a serial port argument is provided
    if (argc >= 2) {
        serial_port = argv[1];
    } else {
        // Prompt for serial port using a GUI dialog
        GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        serial_port = get_serial_port_from_user(GTK_WINDOW(window));
        gtk_widget_destroy(window); // Destroy the temporary window
    }

    // Ensure that a serial port was specified
    if (!serial_port || g_strcmp0(serial_port, "") == 0) {
        fprintf(stderr, "No serial port specified.\n");
        return 1;
    }

    // Attempt to connect to the OBD
    if (!connect_to_obd(serial_port)) {
        fprintf(stderr, "Failed to connect to OBD at %s\n", serial_port);
        g_free(serial_port); // Free allocated memory for serial port
        return 1;
    }

    // Create the GTK application
    GtkApplication *app = gtk_application_new("com.obd1.debugging_suite", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);

    // Run the application
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    g_free(serial_port); // Free allocated memory for serial port

    return status;
}
