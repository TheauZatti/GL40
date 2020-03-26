#include "model.h"
#include "../View/view.h"


Model::Model()
{
    this->view = new View(this);
}
