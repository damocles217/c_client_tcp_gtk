#include "application.h"
#include "button/button.h"

void activate(GtkApplication *app)
{
  GtkWidget *window;
  GtkWidget *box;

  GtkWidget *button;
  GtkCssProvider *provider = gtk_css_provider_new();

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Yummis project");
  gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

  gtk_css_provider_load_from_file(provider, g_file_new_for_path("./src/styles/button/button.css"));
  gtk_style_context_add_provider_for_display(
      gtk_widget_get_display(window),
      GTK_STYLE_PROVIDER(provider),
      GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);


  button = generalButton(provider);

  box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  gtk_widget_set_halign(box, GTK_ALIGN_CENTER);
  gtk_widget_set_valign(box, GTK_ALIGN_CENTER);

  gtk_window_set_child(GTK_WINDOW(window), box);

  gtk_box_append(GTK_BOX(box), button);
  gtk_window_present(GTK_WINDOW(window));
}

int application_started(int argc, char **argv)
{

  GtkApplication *app;
  int status;

  app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);
  return status;
}