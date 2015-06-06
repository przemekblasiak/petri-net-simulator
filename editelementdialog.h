#ifndef EDITELEMENTDIALOG_H
#define EDITELEMENTDIALOG_H

#include <QDialog>

namespace Ui {
class EditElementDialog;
}

class EditElementDialog : public QDialog
{
    Q_OBJECT

public:
    enum EditMode{
        EditPlace,
        EditTransition
    };
    explicit EditElementDialog(QWidget *parent = 0);
    ~EditElementDialog();
    void setEditView(EditMode mode);

signals:
    void livenessChanged(int liveness);
    void descriptionChanged(QString description);

private slots:
    void on_livenessLineEdit_textEdited(const QString &liveness);
    void on_descriptionLineEdit_textEdited(const QString &description);

    void on_buttonBox_accepted();

private:
    Ui::EditElementDialog *ui;

    int liveness;
    QString description;
};

#endif // EDITELEMENTDIALOG_H
