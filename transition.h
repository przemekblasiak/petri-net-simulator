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
    explicit Transition(QPoint &origin, QWidget *parent = 0);
    ~Transition();
    void makeChildrenNotClickable();
    bool isClicked() const;
    void setClicked(bool clicked);
    int number() const;
    void setNumber(const int number);

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
    void removeTransitionRequested(Transition &transition);
};

#endif // TRANSITION_H
