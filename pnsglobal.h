#ifndef PNSGLOBAL
#define PNSGLOBAL

#include <QList>
#include <QDebug>
#include <QRect>
#include <QMap>
#include <QVariant>
#include <QAction>
#include <QMenu>
#include <QFileDialog>
#include <QtGui>
#include <QLabel>
#include <QMouseEvent>
#include <QPoint>
#include <QWidget>
#include <QDesktopWidget>

enum ContextActionType {
    Edit,
    Remove
};

inline QPixmap scaledToFitScreen(QPixmap &pixmap) {
    QRect mainScreenSize = QDesktopWidget().availableGeometry(QDesktopWidget().primaryScreen());
    const int margin = 100;
    const int maximumWidth = mainScreenSize.width() - margin;
    const int maximumHeight = mainScreenSize.height() - margin;
    if (pixmap.size().width() > maximumWidth) {
        pixmap = pixmap.scaledToWidth(maximumWidth);
    }
    else if (pixmap.size().height() > maximumHeight) {
        pixmap = pixmap.scaledToHeight(maximumHeight);
    }
    return pixmap;
}

#endif // PNSGLOBAL

