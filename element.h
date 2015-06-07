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
    virtual QRect innerFrame() const = 0;
    virtual QString description() const = 0;

signals:
    void removeElementRequested();
    void modifyElementRequested();
    void elementClicked();

public slots:
    void showContextMenu(const QPoint &position);
    void contextActionTriggered(QAction *action);
    void onDescriptionChanged(QString description);
    virtual void setDescription(const QString &description) = 0;

protected:
    virtual void updateNumber() = 0;

    QString letter;
    QString basicStyleSheet; // TODO: static?
    bool moving;
    bool pressed;
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

// TODO: Co myślisz, Mateo? Może jakieś utility class?
inline void setChildrenClickable(QWidget *parent, bool clickable) {
    foreach (QObject* child, parent->children()) {
        QWidget *widget = qobject_cast<QWidget *>(child);
        if (widget) {
            widget->setAttribute(Qt::WA_TransparentForMouseEvents, !clickable);
        }
    }
}

#endif // ELEMENT_H
