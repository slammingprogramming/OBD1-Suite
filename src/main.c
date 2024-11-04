#include <gtk/gtk.h>
#include "obd1_interface.h"
#include "gui.h"

int main(int argc, char *argv[]) {
    // Initialize GTK
    gtk_init(&argc, &argv);

    // Initialize OBD-I connection
    int obd_fd = init_obd_connection("/dev/ttyUSB0");
    if (obd_fd == -1) {
        fprintf(stderr, "Failed to open OBD-I connection.\n");
        return 1;
    }

    // Create the main window
    create_main_window();

    // GTK main loop
    gtk_main();

    // Close the OBD connection before exiting
    close_obd_connection(obd_fd);

    return 0;
}