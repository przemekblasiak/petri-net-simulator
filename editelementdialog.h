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
    void setDescription(const QString &description);
    void setTokenCount(int tokenCount);

signals:
    void tokenChanged(int token); // TODO: Refactor token => tokenCount
    void descriptionChanged(QString description);

private slots:
    void on_tokenLineEdit_textEdited(const QString &token);
    void on_descriptionLineEdit_textEdited(const QString &description);

    void on_buttonBox_accepted();

private:
    Ui::EditElementDialog *ui;

    int token;
    QString description;
};

#endif // EDITELEMENTDIALOG_H
