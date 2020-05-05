#include "controller.h"

/// \brief Some examples
int main()
{
    Controller cont;
    cont.readDoc("filename");
    cont.makeShape<Circle>();
    cont.makeShape<Point>();

    cont.removeShape(0);
    cont.saveDoc("filename");
    return 0;
}