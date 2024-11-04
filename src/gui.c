#include "gui.h"

// Callback function to activate the main application window
void on_activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *sidebar;
    GtkWidget *main_area;

    // Create main window
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Universal OBD-I Debugging Suite");
    gtk_window_set_default_size(GTK_WINDOW(window), 1000, 700);

    // Create a grid to hold sidebar and main content
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Sidebar for navigation
    sidebar = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_grid_attach(GTK_GRID(grid), sidebar, 0, 0, 1, 1);
    create_sidebar(sidebar);

    // Main content area
    main_area = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_grid_attach(GTK_GRID(grid), main_area, 1, 0, 1, 1);
    create_main_content(main_area);

    gtk_widget_show_all(window);
}

// Create sidebar navigation buttons
void create_sidebar(GtkWidget *sidebar) {
    GtkWidget *btn_dtc;
    GtkWidget *btn_data_logging;
    GtkWidget *btn_real_time_monitoring;
    GtkWidget *btn_report_generation;
    GtkWidget *btn_settings;

    // Add navigation buttons for each feature
    btn_dtc = gtk_button_new_with_label("DTC Retrieval");
    gtk_box_pack_start(GTK_BOX(sidebar), btn_dtc, TRUE, TRUE, 0);

    btn_data_logging = gtk_button_new_with_label("Data Logging");
    gtk_box_pack_start(GTK_BOX(sidebar), btn_data_logging, TRUE, TRUE, 0);

    btn_real_time_monitoring = gtk_button_new_with_label("Real-time Monitoring");
    gtk_box_pack_start(GTK_BOX(sidebar), btn_real_time_monitoring, TRUE, TRUE, 0);

    btn_report_generation = gtk_button_new_with_label("Report Generation");
    gtk_box_pack_start(GTK_BOX(sidebar), btn_report_generation, TRUE, TRUE, 0);

    btn_settings = gtk_button_new_with_label("Settings");
    gtk_box_pack_start(GTK_BOX(sidebar), btn_settings, TRUE, TRUE, 0);
}

// Create main content placeholders
void create_main_content(GtkWidget *main_area) {
    GtkWidget *frame_dtc;
    GtkWidget *frame_data_logging;
    GtkWidget *frame_monitoring;
    GtkWidget *frame_report;
    GtkWidget *frame_settings;
    
    // Create frame for each placeholder and add labels
    frame_dtc = gtk_frame_new("DTC Retrieval");
    gtk_box_pack_start(GTK_BOX(main_area), frame_dtc, TRUE, TRUE, 0);
    GtkWidget *label_dtc = gtk_label_new("Placeholder for DTC Retrieval and Interpretation.");
    gtk_container_add(GTK_CONTAINER(frame_dtc), label_dtc);

    frame_data_logging = gtk_frame_new("Data Logging");
    gtk_box_pack_start(GTK_BOX(main_area), frame_data_logging, TRUE, TRUE, 0);
    GtkWidget *label_logging = gtk_label_new("Placeholder for Data Logging and Exporting.");
    gtk_container_add(GTK_CONTAINER(frame_data_logging), label_logging);

    frame_monitoring = gtk_frame_new("Real-time Monitoring");
    gtk_box_pack_start(GTK_BOX(main_area), frame_monitoring, TRUE, TRUE, 0);
    GtkWidget *label_monitoring = gtk_label_new("Placeholder for Real-time Data Monitoring.");
    gtk_container_add(GTK_CONTAINER(frame_monitoring), label_monitoring);

    frame_report = gtk_frame_new("Report Generation");
    gtk_box_pack_start(GTK_BOX(main_area), frame_report, TRUE, TRUE, 0);
    GtkWidget *label_report = gtk_label_new("Placeholder for Report Generation.");
    gtk_container_add(GTK_CONTAINER(frame_report), label_report);

    frame_settings = gtk_frame_new("Settings");
    gtk_box_pack_start(GTK_BOX(main_area), frame_settings, TRUE, TRUE, 0);
    GtkWidget *label_settings = gtk_label_new("Placeholder for Settings and Configuration.");
    gtk_container_add(GTK_CONTAINER(frame_settings), label_settings);
}
