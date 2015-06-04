#ifndef ELEMENT_H
#define ELEMENT_H

#include <QFrame>

class Element : public QFrame
{
    Q_OBJECT
public:
    explicit Element(QPoint &origin, QWidget *parent = 0);
    virtual ~Element();

    bool clicked() const;
    void setClicked(bool clicked);
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

private:
    bool _clicked;
    int _number;

    enum ContextActionType {
        Edit,
        Remove
    };
};

#endif // ELEMENT_H
