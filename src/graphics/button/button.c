#include "button.h"

GtkWidget *generalButton()
{
  GtkWidget *button = gtk_button_new_with_label("Holaaa prro");

  gtk_widget_set_name(button, "btn");

  return button;
}