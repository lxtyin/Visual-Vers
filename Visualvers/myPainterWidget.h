/*
 * 此类为scrollArea内的widget类，为了在其中绘图为其单开一个类
*/

#ifndef MYPAINTERWIDGET_H
#define MYPAINTERWIDGET_H

#include <QWidget>
#include <vector>

class myPainterWidget: public QWidget {
    Q_OBJECT
    std::vector<QLineF> lines; //保存需要绘制的内容，目前只画线（自带箭头
public:

    explicit myPainterWidget(QWidget *parent = nullptr);
    void clearContents();
    void addLine(QLineF l);

protected:
    void paintEvent(QPaintEvent *event);
};


#endif //MYPAINTERWIDGET_H
