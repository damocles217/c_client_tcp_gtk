#include "application.h"
#include "button/button.h"

GtkWidget *activate()
{
  GtkWidget *window;
  GtkWidget *box;

  GtkWidget *button;

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Yummis project");
  gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  button = generalButton();
  box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

  gtk_container_add(GTK_CONTAINER(window), box);

  gtk_box_pack_start(GTK_BOX(box), button, TRUE, TRUE, 0);

  gtk_widget_set_halign(box, GTK_ALIGN_CENTER);
  gtk_widget_set_valign(box, GTK_ALIGN_CENTER);

  return window;
}

int application_started(int argc, char **argv)
{
  gtk_init(&argc, &argv);
  GtkWidget *window = activate();
  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}