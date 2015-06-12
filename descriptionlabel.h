#ifndef DESCRIPTIONLABEL_H
#define DESCRIPTIONLABEL_H

#include <QWidget>

namespace Ui {
class DescriptionLabel;
}

class DescriptionLabel : public QWidget
{
    Q_OBJECT

public:
    explicit DescriptionLabel(QWidget *parent);
    ~DescriptionLabel();

    void setText(const QString &text);
    QString text();
private:
    Ui::DescriptionLabel *ui;
};

#endif // DESCRIPTIONLABEL_H
