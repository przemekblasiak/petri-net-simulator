#ifndef STATE_H
#define STATE_H

#include "element.h"

namespace Ui {
class State;
}

class State : public Element
{
    Q_OBJECT

public:
    explicit State(QWidget *parent = 0);
    ~State();

private:
    Ui::State *ui;
};

#endif // STATE_H
