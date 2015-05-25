#ifndef TRANSITION_H
#define TRANSITION_H

#include <QFrame>

namespace Ui {
class Transition;
}

class Transition : public QFrame
{
    Q_OBJECT

public:
    explicit Transition(int x, int y, QWidget *parent = 0);
    ~Transition();
    void makeChildrenNotClickable();

private:
    Ui::Transition *ui;
};

#endif // TRANSITION_H
