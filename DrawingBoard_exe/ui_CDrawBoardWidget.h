/********************************************************************************
** Form generated from reading UI file 'CDrawBoardWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CDRAWBOARDWIDGET_H
#define UI_CDRAWBOARDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CDrawBoardWidget
{
public:

    void setupUi(QWidget *CDrawBoardWidget)
    {
        if (CDrawBoardWidget->objectName().isEmpty())
            CDrawBoardWidget->setObjectName(QString::fromUtf8("CDrawBoardWidget"));
        CDrawBoardWidget->resize(800, 600);

        retranslateUi(CDrawBoardWidget);

        QMetaObject::connectSlotsByName(CDrawBoardWidget);
    } // setupUi

    void retranslateUi(QWidget *CDrawBoardWidget)
    {
        CDrawBoardWidget->setWindowTitle(QCoreApplication::translate("CDrawBoardWidget", "Widget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CDrawBoardWidget: public Ui_CDrawBoardWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CDRAWBOARDWIDGET_H
