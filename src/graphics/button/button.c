#include "button.h"

GtkWidget *generalButton(GtkCssProvider *buttonProvider)
{
  GtkWidget *button = gtk_button_new_with_label("Holaaa prro");

  gtk_widget_set_name(button, "btn");

  gtk_widget_class_set_css_name(GTK_WIDGET_GET_CLASS(button), "btn");

  GtkStyleContext *context = gtk_widget_get_style_context(button);

  return button;
}