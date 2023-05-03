#ifndef CDRAWBOARDWIDGET_H
#define CDRAWBOARDWIDGET_H

#include <QWidget>
#include <QToolButton>
#include "MACRO.h"
#include <QResizeEvent>
#include "DrawWidget.h"
#include <QObject>
#include <QFile>
#include <QDebug>


QT_BEGIN_NAMESPACE
namespace Ui { class CDrawBoardWidget; }
QT_END_NAMESPACE


class CDrawBoardWidget : public QWidget
{
    Q_OBJECT
public:
    CDrawBoardWidget(QWidget *parent = nullptr);
    ~CDrawBoardWidget();

    void resizeEvent(QResizeEvent *event);

public  slots:
    /*
    *函数说明：点击按钮，设置绘画类型为矩形
    *参数列表：无
    *返回值：无
    */
    void fn_MyRectangleBtn_Clicked();
    void fn_MyEllipseBtn_Clicked();
    void fn_MyTriangleBtn_Clicked();
    void fn_MyLineBtn_Clicked();
    void fn_MyTextBtn_Clicked();
    void fn_MyLeftRotateBtn_Clicked();
    void fn_MyRightRotateBtn_Clicked();
    void fn_MyErasureBtn_Clicked();
    void fn_MySelectBtn_Clicked();
    void fn_MyRotateBtn_Clicked();
    void fn_MyDimensionsBtn_Clicked();

    void keyReleaseEvent(QKeyEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    int fn_LoadStyleSheet();

private:
    Ui::CDrawBoardWidget *ui;

    QString m_TextContent;// 文字获取

    QToolButton m_EllipaseBtn;// 椭圆
    QToolButton m_RectangleBtn;// 矩形
    QToolButton m_TriangleBtn;// 三角形
    QToolButton m_LineBtn;// 三角形
    QToolButton m_TextBtn;// 文字

    QToolButton m_LeftRotateBtn;// 左转
    QToolButton m_RightRotateBtn;// 右转
    QToolButton m_ResetRotateBtn;// 缩放

    QToolButton m_ErasureBtn;// 擦除
    QToolButton m_SelectBtn;// 选择
    QToolButton m_Dimensions;// 移动
    QToolButton m_RotateBtn;//旋转，默认90度

    DrawWidget m_DrawWidget;// 绘画窗体，用于绘画的所有操作

    QToolButton *m_pLastClickBtn = &m_LineBtn;// 上一次点击的按钮

private:
    QString m_qstrSelectBtnStyle;// 选中样式
    QString m_qstrNormalBtnStyle;// 普通按钮样式

};
#endif // CDRAWBOARDWIDGET_H
