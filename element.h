#ifndef ELEMENT_H
#define ELEMENT_H

#include <QFrame>

class Element : public QFrame
{
    Q_OBJECT
public:
    explicit Element(QWidget *parent = 0);
    virtual ~Element();

    bool selected() const;
    void setSelected(bool clicked);
    int number() const;
    void setNumber(int number);

signals:
    void removeElementRequested();
    void modifyElementRequested();

public slots:
    void showContextMenu(const QPoint &position);
    void contextActionTriggered(QAction *action);

protected:
    virtual void setChildrenClickable(bool clickable);
    virtual void updateNumber() = 0;

    QString letter;
    QString basicStyleSheet; // TODO: static?
    bool moving;
    QPoint offset;

private:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    bool _selected;
    int _number;

    enum ContextActionType {
        Edit,
        Remove
    };
};

#endif // ELEMENT_H
