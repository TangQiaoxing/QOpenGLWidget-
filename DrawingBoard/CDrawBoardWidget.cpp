#include "CDrawBoardWidget.h"
#include "ui_CDrawBoardWidget.h"

CDrawBoardWidget::CDrawBoardWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CDrawBoardWidget)
{
    ui->setupUi(this);
    this->setWindowTitle(QStringLiteral("画图板"));
    this->setWindowIcon(QIcon(QString(":/Icon.png")));
    m_qstrNormalBtnStyle = QString("QToolButton {background-color:#00BFFF;padding:0px;margin:2px;border:none;font-family:'YouYuan';font-size:14px;color:#222222;}"
                                   "QToolButton:hover{background-color:#1E90FF;}");
    m_qstrSelectBtnStyle = QString("QToolButton {background-color:#1E90FF;border:2px solid #9932CC;padding:0px;margin:2px;font-family:'YouYuan';font-size:14px;color:#222222;}");

    // 设置所有按钮的属性 开始
    this->m_EllipaseBtn.setParent(this);
    this->m_EllipaseBtn.setText("椭圆");
    this->m_EllipaseBtn.setIcon(QIcon(QString(":/Ellipase.png")));
    this->m_EllipaseBtn.setIconSize(QSize(ICON_SIZE,ICON_SIZE));
    this->m_EllipaseBtn.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    this->m_EllipaseBtn.setStyleSheet(m_qstrNormalBtnStyle);

    this->m_RectangleBtn.setParent(this);
    this->m_RectangleBtn.setText("矩形");
    this->m_RectangleBtn.setIcon(QIcon(QString(":/Rectangle.png")));
    this->m_RectangleBtn.setIconSize(QSize(ICON_SIZE,ICON_SIZE));
    this->m_RectangleBtn.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    this->m_RectangleBtn.setStyleSheet(m_qstrNormalBtnStyle);

    this->m_TriangleBtn.setParent(this);
    this->m_TriangleBtn.setText("三角形");
    this->m_TriangleBtn.setIcon(QIcon(QString(":/Triangle.png")));
    this->m_TriangleBtn.setIconSize(QSize(ICON_SIZE,ICON_SIZE));
    this->m_TriangleBtn.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    this->m_TriangleBtn.setStyleSheet(m_qstrNormalBtnStyle);

    this->m_LineBtn.setParent(this);
    this->m_LineBtn.setText("直线");
    this->m_LineBtn.setIcon(QIcon(QString(":/Line.png")));
    this->m_LineBtn.setIconSize(QSize(ICON_SIZE,ICON_SIZE));
    this->m_LineBtn.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    this->m_LineBtn.setStyleSheet(m_qstrNormalBtnStyle);

    this->m_TextBtn.setParent(this);
    this->m_TextBtn.setText("文字");
    this->m_TextBtn.setIcon(QIcon(QString(":/Text.png")));
    this->m_TextBtn.setIconSize(QSize(ICON_SIZE,ICON_SIZE));
    this->m_TextBtn.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    this->m_TextBtn.setStyleSheet(m_qstrNormalBtnStyle);

    this->m_LeftRotateBtn.setParent(this);
    this->m_LeftRotateBtn.setText("画面左转");
    this->m_LeftRotateBtn.setObjectName(QString("RotateBtn"));
    this->m_LeftRotateBtn.setIcon(QIcon(QString(":/LeftRotate.png")));
    this->m_LeftRotateBtn.setIconSize(QSize(ICON_SIZE,ICON_SIZE));
    this->m_LeftRotateBtn.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    this->m_RightRotateBtn.setParent(this);
    this->m_RightRotateBtn.setText("画面右转");
    this->m_RightRotateBtn.setObjectName(QString("RotateBtn"));
    this->m_RightRotateBtn.setIcon(QIcon(QString(":/RightRotate.png")));
    this->m_RightRotateBtn.setIconSize(QSize(ICON_SIZE,ICON_SIZE));
    this->m_RightRotateBtn.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    this->m_ResetRotateBtn.setParent(this);
    this->m_ResetRotateBtn.setText("缩放");
    this->m_ResetRotateBtn.setObjectName(QString("RotateBtn"));
    this->m_ResetRotateBtn.setIcon(QIcon(QString(":/Scole.png")));
    this->m_ResetRotateBtn.setIconSize(QSize(ICON_SIZE,ICON_SIZE));
    this->m_ResetRotateBtn.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);


    this->m_ErasureBtn.setParent(this);
    this->m_ErasureBtn.setText("擦除");
    this->m_ErasureBtn.setObjectName(QString("RotateBtn"));
    this->m_ErasureBtn.setIcon(QIcon(QString(":/Erasure.png")));
    this->m_ErasureBtn.setIconSize(QSize(ICON_SIZE,ICON_SIZE));
    this->m_ErasureBtn.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    this->m_SelectBtn.setParent(this);
    this->m_SelectBtn.setText("选择");
    this->m_SelectBtn.setObjectName(QString("RotateBtn"));
    this->m_SelectBtn.setIcon(QIcon(QString(":/Select.png")));
    this->m_SelectBtn.setIconSize(QSize(ICON_SIZE,ICON_SIZE));
    this->m_SelectBtn.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    this->m_Dimensions.setParent(this);
    this->m_Dimensions.setText("标注");
    this->m_Dimensions.setObjectName(QString("RotateBtn"));
    this->m_Dimensions.setIcon(QIcon(QString(":/Dimensions.png")));
    this->m_Dimensions.setIconSize(QSize(ICON_SIZE,ICON_SIZE));
    this->m_Dimensions.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    this->m_RotateBtn.setParent(this);
    this->m_RotateBtn.setText("图形旋转");
    this->m_RotateBtn.setObjectName(QString("RotateBtn"));
    this->m_RotateBtn.setIcon(QIcon(QString(":/RightRotate.png")));
    this->m_RotateBtn.setIconSize(QSize(ICON_SIZE,ICON_SIZE));
    this->m_RotateBtn.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    // 设置所有按钮的属性 结束

    // 设置画板的父类
    this->m_DrawWidget.setParent(this);

    // 点击矩形按钮，画矩形，需要进行设置矩形的类型
    // 一定要加引号
    connect(&m_RectangleBtn,&QToolButton::clicked,this,&CDrawBoardWidget::fn_MyRectangleBtn_Clicked,Qt::ConnectionType::DirectConnection);//
    connect(&m_EllipaseBtn,&QToolButton::clicked,this,&CDrawBoardWidget::fn_MyEllipseBtn_Clicked,Qt::ConnectionType::DirectConnection);//
    connect(&m_TriangleBtn,&QToolButton::clicked,this,&CDrawBoardWidget::fn_MyTriangleBtn_Clicked,Qt::ConnectionType::DirectConnection);//
    connect(&m_LineBtn,&QToolButton::clicked,this,&CDrawBoardWidget::fn_MyLineBtn_Clicked,Qt::ConnectionType::DirectConnection);//
    connect(&m_TextBtn,&QToolButton::clicked,this,&CDrawBoardWidget::fn_MyTextBtn_Clicked,Qt::ConnectionType::DirectConnection);//
    connect(&m_LeftRotateBtn,&QToolButton::clicked,this,&CDrawBoardWidget::fn_MyLeftRotateBtn_Clicked,Qt::ConnectionType::DirectConnection);//
    connect(&m_RightRotateBtn,&QToolButton::clicked,this,&CDrawBoardWidget::fn_MyRightRotateBtn_Clicked,Qt::ConnectionType::DirectConnection);//
    connect(&m_ErasureBtn,&QToolButton::clicked,this,&CDrawBoardWidget::fn_MyErasureBtn_Clicked,Qt::ConnectionType::DirectConnection);//
    connect(&m_SelectBtn,&QToolButton::clicked,this,&CDrawBoardWidget::fn_MySelectBtn_Clicked,Qt::ConnectionType::DirectConnection);//
    connect(&m_RotateBtn,&QToolButton::clicked,this,&CDrawBoardWidget::fn_MyRotateBtn_Clicked,Qt::ConnectionType::DirectConnection);//
    connect(&m_Dimensions,&QToolButton::clicked,this,&CDrawBoardWidget::fn_MyDimensionsBtn_Clicked,Qt::ConnectionType::DirectConnection);//

    this->fn_LoadStyleSheet();


}

CDrawBoardWidget::~CDrawBoardWidget()
{
    delete ui;
}

void CDrawBoardWidget::resizeEvent(QResizeEvent *event)
{
    // 设置按钮的位置
    m_EllipaseBtn.setGeometry(0,0,BTN_SIZE,BTN_SIZE);
    m_RectangleBtn.setGeometry(BTN_SIZE,0,BTN_SIZE,BTN_SIZE);
    m_TriangleBtn.setGeometry(BTN_SIZE*2,0,BTN_SIZE,BTN_SIZE);
    m_LineBtn.setGeometry(BTN_SIZE*3,0,BTN_SIZE,BTN_SIZE);
    m_TextBtn.setGeometry(BTN_SIZE*4,0,BTN_SIZE,BTN_SIZE);
    m_SelectBtn.setGeometry(BTN_SIZE*5,0,BTN_SIZE,BTN_SIZE);
    m_ErasureBtn.setGeometry(BTN_SIZE*6,0,BTN_SIZE,BTN_SIZE);
    m_Dimensions.setGeometry(BTN_SIZE*7,0,BTN_SIZE,BTN_SIZE);
    m_RotateBtn.setGeometry(BTN_SIZE*8,0,BTN_SIZE,BTN_SIZE);
    m_LeftRotateBtn.setGeometry(BTN_SIZE*9,0,BTN_SIZE,BTN_SIZE);
    m_RightRotateBtn.setGeometry(BTN_SIZE*10,0,BTN_SIZE,BTN_SIZE);
    m_ResetRotateBtn.setGeometry(BTN_SIZE*11,0,BTN_SIZE,BTN_SIZE);

    m_DrawWidget.setGeometry(5,BTN_SIZE+5,this->width()-10,this->height()-10-BTN_SIZE);
    m_DrawWidget.m_StatusEdit.setGeometry(0,this->height()-30-BTN_SIZE,this->width()-10,20);
    QWidget::resizeEvent(event);
}

void CDrawBoardWidget::keyPressEvent(QKeyEvent *event)
{

    //    https://www.cnblogs.com/linuxAndMcu/p/11023299.html#:~:text=%2F%2F%20%E9%94%AE%E7%9B%98%E6%8C%89%E4%B8%8B%E4%BA%8B%E4%BB%B6%20void%20Widget%3A%3AkeyPressEvent%28QKeyEvent%20%2A%20event%29%20%7B%20%2F%2F,%3C%3C%20%22release%3A%20%22%20%3C%3C%20%22up%22%20%3B%20%7D%20%7D
    // 普通键
    switch (event->key())
    {
    // Delete
    case Qt::Key_Delete:
    {
        if(m_DrawWidget.m_curShapeIndex != -1){
            m_DrawWidget.m_pSystemData->m_ShapeVec.erase(m_DrawWidget.m_pSystemData->m_ShapeVec.begin() + m_DrawWidget.m_curShapeIndex);
            m_DrawWidget.m_pSystemData->RemoveShapePointMap(m_DrawWidget.m_curShapeIndex);
            m_DrawWidget.m_curShape = NULL; // 边框也去除
        }
        break;
    }
        // ESC键
    case Qt::Key_Escape:
        qDebug() <<"ESC";
        m_DrawWidget.SetShapeType(ShapeType::Shape_Unkonwn);
        m_pLastClickBtn->setStyleSheet(m_qstrNormalBtnStyle);
        m_pLastClickBtn = &m_LineBtn;// 不设默认值回崩
        break;
        // 回车键
    case Qt::Key_Return:
        qDebug() <<"Enter";
        break;
        // F1键
    case Qt::Key_F1:
        qDebug() <<"F1";
        break;
    }
    QWidget::keyPressEvent(event);
}

void CDrawBoardWidget::keyReleaseEvent(QKeyEvent *event)
{
    qDebug()<< "鼠标松开";
    QWidget::keyReleaseEvent(event);
}


void CDrawBoardWidget::fn_MyRectangleBtn_Clicked()
{
    m_pLastClickBtn->setStyleSheet(m_qstrNormalBtnStyle);// 把之前的选中去掉
    m_DrawWidget.SetShapeType(ShapeType::Shape_Reckangle);// 设置当前选中的图像类型
    m_RectangleBtn.setStyleSheet(m_qstrSelectBtnStyle);// 设置现在选中的类型，进行按钮的颜色标记
    m_pLastClickBtn = &m_RectangleBtn;// 把变量更改，方便下一次选中的时候进行更改颜色
    //    return NORMAL_RETURN;
    m_DrawWidget.m_SelectBtnClicked = false;// 这个按钮只有在需要选择面板中的图像元素的时候才进行设置true

}

void CDrawBoardWidget::fn_MyEllipseBtn_Clicked()
{
    m_pLastClickBtn->setStyleSheet(m_qstrNormalBtnStyle);
    m_DrawWidget.SetShapeType(ShapeType::Shape_Ellipse);
    m_EllipaseBtn.setStyleSheet(m_qstrSelectBtnStyle);
    m_pLastClickBtn = &m_EllipaseBtn;
    m_DrawWidget.m_SelectBtnClicked = false;

}

void CDrawBoardWidget::fn_MyTriangleBtn_Clicked()
{
    m_pLastClickBtn->setStyleSheet(m_qstrNormalBtnStyle);
    m_DrawWidget.SetShapeType(ShapeType::Shape_Triangle);
    m_TriangleBtn.setStyleSheet(m_qstrSelectBtnStyle);
    m_pLastClickBtn = &m_TriangleBtn;
    m_DrawWidget.m_SelectBtnClicked = false;

}

void CDrawBoardWidget::fn_MyLineBtn_Clicked()
{
    m_pLastClickBtn->setStyleSheet(m_qstrNormalBtnStyle);
    m_DrawWidget.SetShapeType(ShapeType::Shape_Line);
    m_LineBtn.setStyleSheet(m_qstrSelectBtnStyle);
    m_pLastClickBtn = &m_LineBtn;
    m_DrawWidget.m_SelectBtnClicked = false;

}

void CDrawBoardWidget::fn_MyTextBtn_Clicked()
{
    m_pLastClickBtn->setStyleSheet(m_qstrNormalBtnStyle);
    m_DrawWidget.SetShapeType(ShapeType::Shape_Text);
    m_TextBtn.setStyleSheet(m_qstrSelectBtnStyle);
    m_pLastClickBtn = &m_TextBtn;
    m_DrawWidget.m_SelectBtnClicked = false;

}

void CDrawBoardWidget::fn_MyLeftRotateBtn_Clicked()
{
    m_pLastClickBtn->setStyleSheet(m_qstrNormalBtnStyle);
    m_DrawWidget.RotateLeft();
    m_DrawWidget.m_SelectBtnClicked = false;

}

void CDrawBoardWidget::fn_MyRightRotateBtn_Clicked()
{
    m_pLastClickBtn->setStyleSheet(m_qstrNormalBtnStyle);
    m_DrawWidget.RotateRight();
    m_DrawWidget.m_SelectBtnClicked = false;
}

void CDrawBoardWidget::fn_MyErasureBtn_Clicked()
{
    m_DrawWidget.SetShapeType(ShapeType::Erasure);
    m_DrawWidget.m_SelectBtnClicked = false;
    qDebug()<<QString(int(m_DrawWidget.GetShapeType()));
}

void CDrawBoardWidget::fn_MySelectBtn_Clicked()
{
    m_pLastClickBtn->setStyleSheet(m_qstrNormalBtnStyle);
    m_DrawWidget.SetShapeType(ShapeType::Shape_Unkonwn);
    m_DrawWidget.m_SelectBtnClicked = true;
    //    m_pLastClickBtn = &m_SelectBtn;

}

void CDrawBoardWidget::fn_MyRotateBtn_Clicked()
{
    m_pLastClickBtn->setStyleSheet(m_qstrNormalBtnStyle);
    m_DrawWidget.SetShapeType(ShapeType::Shape_Unkonwn);
    //    qDebug()<<"  m_DrawWidget.SetShapeType(ShapeType::Shape_Unkonwn);";
    if(!m_DrawWidget.m_curShape){
        m_DrawWidget.m_curShape =m_DrawWidget.m_pSystemData->m_ShapeVec.back();
    }
    //    if(!m_DrawWidget.m_StartingClickPoint){

    //    }else{
    //        m_DrawWidget.m_curShape->rotate(m_DrawWidget.m_curShape->m_Center,90);
    //    }
    m_DrawWidget.m_RotateBtnClicked = true;
    m_DrawWidget.m_StatusEdit.setText(QString("Enter the rotation Angle (90 degrees by default) and click to Select Rotation base Point:"));
}

void CDrawBoardWidget::fn_MyDimensionsBtn_Clicked()
{
    m_pLastClickBtn->setStyleSheet(m_qstrNormalBtnStyle);
    m_DrawWidget.SetShapeType(ShapeType::Shape_Unkonwn);
    m_DrawWidget.m_SelectBtnClicked = false;
    m_DrawWidget.SetShapeType(ShapeType::Shape_Demensions);
    m_DrawWidget.Demensions();// 进行尺寸的标记
}


// 加载样式
int CDrawBoardWidget::fn_LoadStyleSheet()
{
    QFile file(QString("../DrawingBoard/Resource/QSS/DrawingBoardWidget.qss"));
    if(file.open(QIODevice::OpenModeFlag::ReadOnly)){
        QByteArray bytes = file.readAll();
        this->setStyleSheet(QString(bytes));
        file.close();
    }
    return NORMAL_RETURN;
}

