/********************************************************************************
** Form generated from reading UI file 'hanoi.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HANOI_H
#define UI_HANOI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hanoi
{
public:
    QAction *action_New;
    QAction *action_Undo;
    QAction *action_Undo_All;
    QAction *actionAuto_Play;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QAction *action_5;
    QAction *action_6;
    QAction *action_7;
    QAction *action_8;
    QAction *actionNth_Play;
    QAction *action_New_Arbitrary;
    QAction *actionComo_Jugar;
    QAction *actionHow_to_Play;
    QWidget *centralWidget;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menuBar;
    QMenu *menu_Game;
    QMenu *menu_Set_Disks;
    QMenu *menu_Play;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Hanoi)
    {
        if (Hanoi->objectName().isEmpty())
            Hanoi->setObjectName(QStringLiteral("Hanoi"));
        Hanoi->resize(799, 563);
        action_New = new QAction(Hanoi);
        action_New->setObjectName(QStringLiteral("action_New"));
        action_Undo = new QAction(Hanoi);
        action_Undo->setObjectName(QStringLiteral("action_Undo"));
        action_Undo_All = new QAction(Hanoi);
        action_Undo_All->setObjectName(QStringLiteral("action_Undo_All"));
        actionAuto_Play = new QAction(Hanoi);
        actionAuto_Play->setObjectName(QStringLiteral("actionAuto_Play"));
        action_2 = new QAction(Hanoi);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_3 = new QAction(Hanoi);
        action_3->setObjectName(QStringLiteral("action_3"));
        action_4 = new QAction(Hanoi);
        action_4->setObjectName(QStringLiteral("action_4"));
        action_5 = new QAction(Hanoi);
        action_5->setObjectName(QStringLiteral("action_5"));
        action_6 = new QAction(Hanoi);
        action_6->setObjectName(QStringLiteral("action_6"));
        action_7 = new QAction(Hanoi);
        action_7->setObjectName(QStringLiteral("action_7"));
        action_8 = new QAction(Hanoi);
        action_8->setObjectName(QStringLiteral("action_8"));
        actionNth_Play = new QAction(Hanoi);
        actionNth_Play->setObjectName(QStringLiteral("actionNth_Play"));
        action_New_Arbitrary = new QAction(Hanoi);
        action_New_Arbitrary->setObjectName(QStringLiteral("action_New_Arbitrary"));
        actionComo_Jugar = new QAction(Hanoi);
        actionComo_Jugar->setObjectName(QStringLiteral("actionComo_Jugar"));
        actionHow_to_Play = new QAction(Hanoi);
        actionHow_to_Play->setObjectName(QStringLiteral("actionHow_to_Play"));
        centralWidget = new QWidget(Hanoi);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton_1 = new QPushButton(centralWidget);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        pushButton_1->setGeometry(QRect(20, 0, 231, 401));
        pushButton_1->setFlat(true);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 0, 231, 401));
        pushButton_2->setFlat(true);
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(520, 0, 231, 401));
        pushButton_3->setFlat(true);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(420, 420, 142, 68));
        QFont font;
        font.setFamily(QStringLiteral("DejaVu Sans Mono"));
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_3->setTextFormat(Qt::RichText);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(530, 420, 142, 68));
        label_4->setFont(font);
        Hanoi->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Hanoi);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 799, 19));
        menu_Game = new QMenu(menuBar);
        menu_Game->setObjectName(QStringLiteral("menu_Game"));
        menu_Set_Disks = new QMenu(menu_Game);
        menu_Set_Disks->setObjectName(QStringLiteral("menu_Set_Disks"));
        menu_Play = new QMenu(menuBar);
        menu_Play->setObjectName(QStringLiteral("menu_Play"));
        Hanoi->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Hanoi);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Hanoi->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Hanoi);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Hanoi->setStatusBar(statusBar);

        menuBar->addAction(menu_Game->menuAction());
        menuBar->addAction(menu_Play->menuAction());
        menu_Game->addAction(action_New);
        menu_Game->addAction(action_New_Arbitrary);
        menu_Game->addAction(menu_Set_Disks->menuAction());
        menu_Set_Disks->addAction(action_2);
        menu_Set_Disks->addAction(action_3);
        menu_Set_Disks->addAction(action_4);
        menu_Set_Disks->addAction(action_5);
        menu_Set_Disks->addAction(action_6);
        menu_Set_Disks->addAction(action_7);
        menu_Set_Disks->addAction(action_8);
        menu_Play->addAction(action_Undo);
        menu_Play->addAction(action_Undo_All);
        menu_Play->addAction(actionAuto_Play);
        menu_Play->addAction(actionNth_Play);

        retranslateUi(Hanoi);

        QMetaObject::connectSlotsByName(Hanoi);
    } // setupUi

    void retranslateUi(QMainWindow *Hanoi)
    {
        Hanoi->setWindowTitle(QApplication::translate("Hanoi", "Hanoi", 0));
        action_New->setText(QApplication::translate("Hanoi", "&New", 0));
        action_Undo->setText(QApplication::translate("Hanoi", "&Undo", 0));
        action_Undo->setShortcut(QApplication::translate("Hanoi", "Ctrl+Z", 0));
        action_Undo_All->setText(QApplication::translate("Hanoi", "Undo &All", 0));
        action_Undo_All->setShortcut(QApplication::translate("Hanoi", "Ctrl+A", 0));
        actionAuto_Play->setText(QApplication::translate("Hanoi", "Auto &Play", 0));
        actionAuto_Play->setShortcut(QApplication::translate("Hanoi", "Ctrl+P", 0));
        action_2->setText(QApplication::translate("Hanoi", "&2", 0));
        action_3->setText(QApplication::translate("Hanoi", "&3", 0));
        action_4->setText(QApplication::translate("Hanoi", "&4", 0));
        action_5->setText(QApplication::translate("Hanoi", "&5", 0));
        action_6->setText(QApplication::translate("Hanoi", "&6", 0));
        action_7->setText(QApplication::translate("Hanoi", "&7", 0));
        action_8->setText(QApplication::translate("Hanoi", "&8", 0));
        actionNth_Play->setText(QApplication::translate("Hanoi", "Nth &Play", 0));
        actionNth_Play->setShortcut(QApplication::translate("Hanoi", "Ctrl+T", 0));
        action_New_Arbitrary->setText(QApplication::translate("Hanoi", "&New Arbitrary", 0));
        action_New_Arbitrary->setShortcut(QApplication::translate("Hanoi", "Ctrl+R", 0));
        actionComo_Jugar->setText(QApplication::translate("Hanoi", "How Activate the Auto Player", 0));
        actionHow_to_Play->setText(QApplication::translate("Hanoi", "How to Play", 0));
        pushButton_1->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        label_3->setText(QApplication::translate("Hanoi", "STEPS:", 0));
        label_4->setText(QString());
        menu_Game->setTitle(QApplication::translate("Hanoi", "&Game", 0));
        menu_Set_Disks->setTitle(QApplication::translate("Hanoi", "&Set Disks", 0));
        menu_Play->setTitle(QApplication::translate("Hanoi", "&Play", 0));
    } // retranslateUi

};

namespace Ui {
    class Hanoi: public Ui_Hanoi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HANOI_H
