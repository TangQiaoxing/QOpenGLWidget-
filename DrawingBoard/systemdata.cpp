#include "systemdata.h"

SystemData SystemData::g_SystemData;

SystemData *SystemData::GetSystemData()
{
    return &g_SystemData;
}

ShapeData * SystemData::CreateShapeItem(ShapeType &type, QPoint &clickedPoint,QPoint &movePoint,QVector<QPoint> &Vec,ContentEdit &contentEdit,QVector<QPoint> &DemensionsVec){
    ShapeData * temp = new ShapeData;
    switch (type) {
    case ShapeType::Shape_Reckangle:
    {
        temp =new RectangleData(clickedPoint,movePoint);
        break;
    }
    case ShapeType::Shape_Ellipse:
    {
        temp =new EllipseData(clickedPoint,movePoint);
        break;
    }
    case ShapeType::Shape_Triangle:
    {
        temp =new TriangeleData(clickedPoint,movePoint);
        break;
    }
    case ShapeType::Shape_Line:
    {
        temp =new LineData(clickedPoint,movePoint);
        break;
    }
    case ShapeType::Shape_Text:
    {
        temp =new TextData(clickedPoint,contentEdit);
        break;
    }
    case ShapeType::Erasure:
    {
        temp =new ErasureData(Vec);
        break;
    }
    case ShapeType::Shape_Demensions:
    {
        if(DemensionsVec.size() == 3){
            temp = new DemensionsData(DemensionsVec);
        }
        break;
    }
    default:
        break;
    }
    //    QSharedPointer<ShapeData> item(temp);
    //    delete temp;
    //    return item;// 不想出现警告可以使用智能指针来替代，这样就比较安全，不会出现内存泄露
    return temp;
}

//class Singleton
//{
//private:
//    static Singleton* instance;
//    Singleton(){
//    }
//public:
//    static Singleton* GetInstace()
//    {
//        if (NULL == instance)
//        {
//            instance = new Singleton();
//        }
//        return instance;
//    }
//};

SystemData::SystemData()
{

}

SystemData::~SystemData()
{

    qDeleteAll(m_ShapeVec);
    m_ShapeVec.clear();
    m_ShapeVec.shrink_to_fit();
}
