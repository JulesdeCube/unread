#ifndef UNREAD__SRC_PREPROCESSING__LOAD_H_
#define UNREAD__SRC_PREPROCESSING__LOAD_H_

#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>

#include "change_color.h"
#include "segmentation.h"
#include "resize.h"
#include "rotate.h"
#include "noise.h"
#include "histo_grey_lvl.h"
#include "resize_char.h"

/**
** \brief Create an Image from a file
**
** \return Return an GtkWidget *image
*/
GtkWidget *create_image();

/**
** \brief We start our first window
** and display it
**
** \param app the application
** \param user_data Unused parameter
*/
void activate_window(GtkApplication *app, gpointer user_data);

/**
** \brief Generate our window with GTK
**
**
** \return if the window is create successfuly
*/
int create_window(int argc, char **argv);

#endif // UNREAD__SRC_PREPROCESSING__LOAD_H_
