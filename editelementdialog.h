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
    int tokenCount();
signals:
    void tokenCountChanged(int tokenCount);
    void descriptionChanged(QString description);
private slots:
    void on_descriptionLineEdit_textEdited(const QString &description);
    void on_buttonBox_accepted();
    void on_tokenCountLineEdit_textEdited(const QString &arg1);
private:
    Ui::EditElementDialog *ui;
    int _tokenCount;
    QString description;
};

#endif // EDITELEMENTDIALOG_H
