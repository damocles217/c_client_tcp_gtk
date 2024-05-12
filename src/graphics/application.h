#ifndef GRAPHIC_APPLICATION_H
#define GRAPHIC_APPLICATION_H

#include <gtk/gtk.h>

void activate(GtkApplication *app);
int application_started(int argc, char **argv);

#endif