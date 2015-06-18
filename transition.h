#ifndef TRANSITION_H
#define TRANSITION_H

#include "element.h"
#include <QPaintEvent>

namespace Ui {
class Transition;
}

class Transition : public Element
{
    Q_OBJECT

public:
    static int count;
    explicit Transition(const QPoint &origin, QWidget *parent = 0);
    virtual ~Transition();
    virtual void setActive(bool active);

    unsigned delay() const;
    unsigned elapsedTime() const;

public slots:
    void onTicked();
    void setDelay(int delay);

private:
    virtual void updateNumber();
    Ui::Transition *ui;
    DescriptionLabel *_delayLabel;
    void paintEvent(QPaintEvent *);
    void adjustDelayLabelPosition();
    unsigned _delay;
    unsigned _elapsedTime;
};

#endif // TRANSITION_H
