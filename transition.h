#ifndef TRANSITION_H
#define TRANSITION_H

#include <QFrame>

const QString TransitionStyleSheet = "border-style: outset;"\
                                     "border-width: 6 1 6 1;";

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

    bool isClicked() const;
    void setClicked(bool clicked);

private:
    Ui::Transition *ui;
    bool clicked;
};

#endif // TRANSITION_H
