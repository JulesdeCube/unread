/**
** \file src/neural_network/neurone.h
** \author Jules Lefebvre <jules.lefebvre@epita.fr
** \version 1.0.0
** \date 2020/10/04
** \brief declaraton of the `neurone` object.
**
** definition of constuctor, destructor and method of the `neurone` object.
*/

#ifndef UNREAD__SRC_NEURAL_NETWORK__NEURONE_H_
#define UNREAD__SRC_NEURAL_NETWORK__NEURONE_H_

#include <stdlib.h>

/**
** \struct s_neurone
** \brief a neurone for neural network
*/
struct s_neurone
{
  double sum;
  double output;
  double bias;
  double *weights;
  double derivate_error;
  struct s_layer *layer;
};

#include <stdio.h>
#include "layer.h"
#include "utils.h"
#include "neural_network_error.h"

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//                                CONSTRUCTOR                                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

/**
** \brief `s_neurone` constuctor.
**
** create a neurone for neural network. if there is an error durring creation,
** function will return NULL
**
** \param parrent the parrent layer
** \param error the return error channel
**
** \return a new instance of `s_neurone`
**
** \throw NN_NO_PARRENT_LAYER no parrent layer provided to the neurone
** \throw NN_ERROR_SPACE there is not enought free space to store the neurone
**        it's self or his weight
*/
struct s_neurone ne_consructor(struct s_layer *parrent, enum e_nn_error *error);

/**
** \brief `s_neurone` constuctor.
**
** create a neurone for neural network from a file.if there is an error durring
** creation, function will return NULL
**
** \param parrent the parrent layer
** \param error the return error channel
**
** \return a new instance of `s_neurone`
**
** \throw NN_PERMISSION_DENIED no file was provided
** \throw NN_NO_PARRENT_LAYER no parrent layer provided to the neurone
** \throw NN_ERROR_SPACE there is not enought free space to store the neurone
**        it's self or his weight
*/
struct s_neurone ne_file_consructor(FILE *fp, struct s_layer *parrent, enum e_nn_error *error);

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//                                 DESTRUCTOR                                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

/**
** \brief `s_neural_network` destructor.
**
**  free space and propely destruct the neural network
**
** \param self a pointer to the neural network to destroy
*/
void ne_destructor(struct s_neurone *neurone);

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//                                  METHODE                                  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

/**
** \brief update the value of the neurone
**
** make the sum of the previous layer weighted and pass all the sum into the
** activation function
**
** \param self the neurone to update
** \param error the return error channel
**
** \throw NN_NO_NEURONE no neurone provided
** \throw NN_NO_PARRENT_LAYER no parrent layer in the neurone
** \throw NN_NO_PARRENT_NEURAL_NETWORK no parrented neural network in the parent
**        of th neurone
*/
void ne_compute(struct s_neurone *self, enum e_nn_error *error);

/**
** \brief write the content of a neurone
**
** write the weight and the biais of a the neurone
**
** \param self the neuone to save
** \param fp file
** \param error the return error channel
**
** \throw NN_NO_NEURONE no neurone provided
** \throw NN_NO_PARRENT_LAYER no parrent layer in the neurone
*/
void ne_write(struct s_neurone *self, FILE *fp, enum e_nn_error *error);

/**
** \brief get the error error from the neurone
**
** use the neurone network error function to get the error of the neurone
**
** \param self the neuone
** \param target the wanted value
** \param error the return error channel
**
** \return the error of the neurone or 0 if there is an error
**
** \throw NN_NO_NEURONE no neurone provided
** \throw NN_NO_PARRENT_LAYER no parrent layer in the neurone
** \throw NN_NO_PARRENT_NEURAL_NETWORK no parrented neural network from le
**        parrent layer
** \throw NN_NO_FUNCTION no error function from the parrent neural network from
**        the parrent layer
*/
double ne_get_error(struct s_neurone *self, double target, enum e_nn_error *error);

/**
** \brief get the output of a neurone
**
** get the caculated neurone output
**
** \param self the neurone
** \param error the return error channel
**
** \return the output value of the neurone
**
** \throw NN_NO_NEURONE no neurone provided
*/
double ne_get_output(struct s_neurone *self, enum e_nn_error *error);

/**
** \brief update neurone
**
** update neurone weight and bias base on the `derivate_error` and propagate
** error on previous neurones
**
** \param self the neurone
** \param error the return error channel
**
** \throw NN_NO_NEURONE no neurone provided
** \throw NN_NO_PARRENT_LAYER no parrent layer or previous layer
*/
void ne_back_propagage(struct s_neurone *self, enum e_nn_error *error);

/**
** \brief reset the `derivate_error` attribute
**
** \param self the neurone
** \param error the return error channel
**
** \throw NN_NO_NEURONE no neurone provided
*/
void ne_reset_error(struct s_neurone *self, enum e_nn_error *error);

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//                                   VIEWER                                  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

/**
** \brief diplay the neurone information
**
** \param self the neurone to print
*/
void ne_print(struct s_neurone *self);

#endif // UNREAD__SRC_NEURAL_NETWORK__NEURONE_H_