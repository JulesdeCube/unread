/**
** \file src/neural_network/layer.h
** \author Jules Lefebvre <jules.lefebvre@epita.fr
** \version 1.0.0
** \date 2020/10/04
** \brief declaraton of the `s_layer` object.
**
** definition of constuctor, destructor and method of the  s_layer` object.
*/

#ifndef UNREAD__SRC_NEURAL_NETWORK__LAYER_H_
#define UNREAD__SRC_NEURAL_NETWORK__LAYER_H_

#include <stdlib.h>
#include <stdio.h>

#include "neural_network_error.h"
#include "neural_network.h"
#include "neurone.h"

/**
** \struct s_layer
** \brief layer for a neural network
*/
struct s_layer
{
  unsigned int size;
  struct s_neurone *neurones;
  struct s_layer *previous_layer;
  struct s_layer *next_layer;
  struct s_neural_network *neural_network;
};

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//                                CONSTRUCTOR                                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

/**
** \brief `s_layer` constuctor.
**
** create a layer for neural network. if there is an error durring creation
** function will return NULL
**
** ⚠️** you need to use the `la_destructor` function after use (to free space )
** ** ⚠️
**
** \param size number of neurone in the layer
** \param previous_layer a pointer to the previous layer (can be null)
** \param neural_network the neural network that get the neurone
** \param error the return error channel
**
** \return a pointer to a new instance of `s_layer` or `NULL` if we can't create
**         du to some error.
**
** \throw NN_NO_NEURAL_NETWORK no parrent neural_network provided
** \throw NN_ERROR_SPACE there is not enought free space to store the neurones
**        or/and it's self
**
** \see neurone.h:ne_consructor for sub error code
*/
struct s_layer *la_consructor(unsigned int size, struct s_layer *previous_layer, struct s_neural_network *neural_network, enum e_nn_error *error);

/**
** \brief `s_layer` constuctor.
**
** create a layer for neural network form a file. if there is an error durring
** creation, function will return NULL
**
** ⚠️** you need to use the `la_destructor` function after use (to free space )
** ** ⚠️
**
** \param fp the file where the layer is store
** \param previous_layer a pointer to the previous layer (can be null)
** \param neural_network the neural network that get the neurone
** \param error the return error channel
**
** \return a pointer to a new instance of `s_layer` or `NULL` if we can't create
**         du to some error.
**
** \throw NN_PERMISSION_DENIED no file was provided
** \throw NN_NO_NEURAL_NETWORK no parrent neural_network provided
** \throw NN_ERROR_SPACE there is not enought free space to store the neurones
**        or/and it's self
**
** \see neurone.h:ne_file_consructor for sub error code
*/
struct s_layer *la_file_consructor(FILE *fp, struct s_layer *previous_layer, struct s_neural_network *neural_network, enum e_nn_error *error);

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//                                 DESTRUCTOR                                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

/**
** \brief `s_layer` destructor.
**
**  free space and propely destruct the layer neural network
**
** \param self a pointer to the layer to destroy
*/
void la_destructor(struct s_layer *self);

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//                                  METHODE                                  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

/**
** \brief set output of neurone of the layer
**
** set each output of each neurone of the layer base on a array
**
** \param self the layer to set values
** \param value the list of values, the lenght need to match with the layer size
** \param error the return error channel
**
** \throw NN_NO_LAYER no layer provided
** \throw NN_NO_VALUES value array not provided
*/
void la_set_values(struct s_layer *self, double *values, enum e_nn_error *error);

/**
** \brief apply forward propagation to each neurone
**
** compute with the previous neurone the output of each neurone of the layer
**
** \param self the layer compute
** \param error the return error channel
**
** \throw NN_NO_LAYER no layer provided
**
** \see neurone.h:ne_compute for sub error code
*/
void la_compute(struct s_layer *self, enum e_nn_error *error);

/**
** \brief write the content of a layer
**
** write the weight and the biais of a the neurone of the layer
**
** \param self the layer to save
** \param fp file
** \param error the return error channel
**
** \throw NN_NO_LAYER no layer provided
** \throw NN_PERMISSION_DENIED if no file is procided
**
** \see neurone.h:ne_write for sub error code
*/
void la_write(struct s_layer *self, FILE *fp, enum e_nn_error *error);

/**
** \brief get the somme of the error of the neurone of the layer
**
** get the value of the error of each neurone of it and sum it
**
** \param self the layer to get total error
** \param targets an array of targeted value with a size of the layer
** \param error the return error channel
**
** \return the sum or 0 if there is an error
**
** \throw NN_NO_LAYER no layer provided
** \throw NN_NO_VALUES no targets array provided
**
** \see neurone.h:ne_get_output for sub error code
*/
double la_get_sum_error(struct s_layer *self, double *targets, enum e_nn_error *error);

/**
** \brief transfer the output into the outputs pointer
**
** set each case of the outputs array to the output of the neurone
**
** \param self the layer
** \param outputs an array to store the outputs
** \param error the return error channel
**
** \throw NN_NO_LAYER no layer provided
** \throw NN_NO_VALUES no outputs arrat provided
**
** \see neurone.h:ne_get_output for sub error code
*/
void la_get_outputs(struct s_layer *self, double *outputs, enum e_nn_error *error);

/**
** \brief applay a function to each neurone
**
** \param self the layer to browse
** \param f the function to apply
** \param error the return error channel
**
** \throw NN_NO_LAYER no layer provided
**
** \see error code of the parametred function
*/
void la_foreach_neurone(struct s_layer *self, void (*f)(struct s_neurone *, enum e_nn_error *error), enum e_nn_error *error);

/**
** \brief update all the neurone of the layer.
**
** update weight and bais base on the derivate error value an propagete it to
** previous layer if exist
**
** \param self the layer
** \param error the return error channel
**
** \throw NN_NO_LAYER no layer provided
**
** \see neurone.h:ne_back_propagage for sub error code
*/
void la_back_propagage(struct s_layer *self, enum e_nn_error *error);

/**
** \brief reset all the neurone derivate value
**
** \param self the layer
** \param error the return error channel
**
** \throw NN_NO_LAYER no layer provided
**
** \see neurone.h:ne_reset_error for sub error code
** \see la_foreach_neurone for sub error code
*/
void la_reset_error(struct s_layer *self, enum e_nn_error *error);

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//                                   VIEWER                                  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

/**
** \brief diplay the layer information
**
** \param self the layer to print
*/
void la_print(struct s_layer *self);

#endif // UNREAD__SRC_NEURAL_NETWORK__LAYER_H_