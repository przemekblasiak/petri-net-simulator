#ifndef ELEMENT_H
#define ELEMENT_H

#include <QFrame>
#include "pnsglobal.h"
#include "descriptionlabel.h"

class Element : public QFrame
{
    Q_OBJECT
public:
    DescriptionLabel *descriptionLabel;
    explicit Element(QWidget *parent = 0);
    virtual ~Element();
    bool selected() const;
    void setSelected(bool clicked);
    int number() const;
    void setNumber(int number);
    virtual QString description();

signals:
    void removeElementRequested();
    void modifyElementRequested();
    void elementClicked();
    void selectedElementDestroyed();

public slots:
    void showContextMenu(const QPoint &position);
    void contextActionTriggered(QAction *action);
    virtual void setDescription(const QString &description);

protected:
    QString letter;
    QString basicStyleSheet; // TODO: static?
    bool moving;
    bool pressed;
    QPoint offset;
    virtual void updateNumber() = 0;
    void setChildrenClickable(bool clickable);

private:
    bool _selected;
    int _number;
    enum ContextActionType {
        Edit,
        Remove
    };
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
};

#endif // ELEMENT_H
