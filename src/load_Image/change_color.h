#ifndef UNREAD__SRC__LOAD_IMAGE__CHANGE_COLOR_H__
#define UNREAD__SRC__LOAD_IMAGE__CHANGE_COLOR_H__

#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>

#include "tools.h"

/**
 ** \brief There is all name of functions to change color
 **
 **  \enum function :
 ** - Colored_to_classicGreyLvl
 ** - ClassicGLVL_to_NormalizedGLVL
 ** - Greylvl_to_BW
 ** - Colored_to_BW
 */
enum function
{
    Colored_to_classicGreyLvl,
    ClassicGLVL_to_NormalizedGLVL,
    Greylvl_to_BW,
    Colored_to_BW,
    Colored_to_OnlyBlack
};


/**
 ** \brief Run on each pixel from image and apply the function in parameters
 ** 
 ** \param image which image to apply color
 ** \param filter function to apply on each pixel
*/
void apply_color(GtkWidget* image, void filter(guchar *, struct s_int_tuple));

/**
 ** \brief Switch from "enum function" and call `apply_color` 
 ** with the coresponding function
 **
 ** \param image which image to change color
 ** \param f enum corresponding with functions to apply on image
 */
void Change_Color(GtkWidget* image, enum function f);

#endif