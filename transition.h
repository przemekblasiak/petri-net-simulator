#ifndef TRANSITION_H
#define TRANSITION_H

#include "element.h"

const QString TransitionStyleSheet = "border-style: outset;"\
                                     "border-width: 6 1 6 1;";

namespace Ui {
class Transition;
}

class Transition : public Element
{
    Q_OBJECT

public:
    explicit Transition(QPoint &origin, QWidget *parent = 0);
    ~Transition();

    void makeChildrenNotClickable();
    bool isClicked() const;
    void setClicked(bool clicked);
    int number() const;
    void setNumber(int number);

    static int count;

public slots:
    void showContextMenu(const QPoint &pos);
    void contextActionTriggered(QAction *action);


private:
    Ui::Transition *ui;
    bool clicked;
    int _number;

    enum ContextActionType {
        Remove
    };

signals:
    void removeTransitionRequested();
};

#endif // TRANSITION_H
