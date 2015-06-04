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
    void setNumber(int number);

    static int count;

public slots:
    void showContextMenu(const QPoint &pos);
    void contextActionTriggered(QAction *action);


private:
    Ui::Transition *ui;
    // TODO: Inheritance, those fields should be a common base. M.D.
    bool clicked;
    bool moving;
    QPoint offset;
    int _number;

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    enum ContextActionType {
        Remove
    };

signals:
    void removeTransitionRequested();
};

#endif // TRANSITION_H
