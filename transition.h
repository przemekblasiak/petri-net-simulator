#ifndef TRANSITION_H
#define TRANSITION_H

#include "element.h"

namespace Ui {
class Transition;
}

class Transition : public Element
{
    Q_OBJECT

public:
    explicit Transition(QPoint &origin, QWidget *parent = 0);
    virtual ~Transition();
    virtual QRect innerFrame() const;
    virtual QString description() const;

    static int count;

public slots:
    virtual void setDescription(const QString &description);

private:
    virtual void updateNumber();
    Ui::Transition *ui;
};

#endif // TRANSITION_H
