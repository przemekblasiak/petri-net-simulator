#ifndef ELEMENT_H
#define ELEMENT_H

#include <QFrame>
#include "pnsglobal.h"
#include "descriptionlabel.h"

class Element : public QFrame
{
    Q_OBJECT
public:
    explicit Element(QWidget *parent);
    virtual ~Element();
    bool selected() const;
    void setSelected(bool clicked);
    int number() const;
    void setNumber(int number);
    virtual QString description();
    virtual void setActive(bool active);
    virtual bool active();

signals:
    void removeElementRequested();
    void modifyElementRequested();
    void elementClicked();
    void selectedElementDestroyed();

public slots:
    void showContextMenu(const QPoint &position);
    void contextActionTriggered(QAction *action);
    virtual void setDescription(const QString &description);
    virtual void setSimulationModeOn(bool on);


protected:
    QString letter;
    static QString selectedAttribute;
    static QString activeAttribute;
    bool moving;
    bool pressed;
    QPoint offset;
    virtual void updateNumber() = 0;
    void setChildrenClickable(bool clickable);
    void paintEvent(QPaintEvent *event);

private:
    bool _selected;
    QString _description;
    int _number;
    bool _active;
    DescriptionLabel *_descriptionLabel;
    bool _simulationModeOn;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void adjustDescriptionLabelPosition();
};

#endif // ELEMENT_H
