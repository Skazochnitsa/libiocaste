/*
 * element.c
 *
 *  Created on: 24/11/2011
 *      Author: fprates
 */

#include "object.h"
#include <stdlib.h>
#include <stddef.h>

struct s_element {
	char *type;
	int iscontainable;
	struct icst_object *container;
};

struct icst_object *icst_ini_element(struct icst_object *container, char *name)
{
	struct s_element *element_ = malloc(sizeof(*element_));
	struct icst_object *element = ini_object(name, element_, NULL);

	element_->container = container;
	element_->iscontainable = 0;

	return element;
}

void def_element_type(struct icst_object *element, char *type)
{
	struct s_element *element_ = ret_extension(element);

	element_->type = type;
}
