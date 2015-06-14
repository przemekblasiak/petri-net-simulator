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
        EditTransition,
        EditArrow
    };
    explicit EditElementDialog(QWidget *parent = 0);
    ~EditElementDialog();
    void setEditView(EditMode mode);
    void setDescription(const QString &description);
    void setTokenCount(int tokenCount);
    int tokenCount();
    void setWeight(int weight);

signals:
    void tokenCountChanged(int tokenCount);
    void descriptionChanged(QString description);
    void weightChanged(int weight);

private slots:
    void on_buttonBox_accepted();
    void on_descriptionLineEdit_textEdited(const QString &description);
    void on_tokenCountLineEdit_textEdited(const QString &tokenCount);
    void on_weightLineEdit_textEdited(const QString &weight);

private:
    Ui::EditElementDialog *ui;
    int _tokenCount;
    QString _description;
    int _weight;
};

#endif // EDITELEMENTDIALOG_H
