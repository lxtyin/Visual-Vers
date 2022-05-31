
#include "myPainterWidget.h"
#include <QPainter>
#include <cmath>
#include <QStyleOption>
using namespace std;

myPainterWidget::myPainterWidget(QWidget *parent): QWidget((parent)), lines(vector<QLineF>()) {}

void myPainterWidget::paintEvent(QPaintEvent *event) {

    QPainter painter(this);
    QStyleOption opt;
    opt.initFrom(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);//绘制样式
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen(Qt::green, 4, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);
    painter.setPen(pen);
    for(auto &l: lines){
        painter.drawLine(l);
        //绘制箭头
        qreal ag1 = l.angle() - 150;
        qreal ag2 = l.angle() + 150;
        QPointF r1 = l.p2() + 15 * QPointF(cos(ag1 * M_PI / 180), -sin(ag1 * M_PI / 180));
        QPointF r2 = l.p2() + 15 * QPointF(cos(ag2 * M_PI / 180), -sin(ag2 * M_PI / 180));
        painter.drawLine(l.p2(), r1);
        painter.drawLine(l.p2(), r2);
    }
}

void myPainterWidget::clearContents() {
    lines.clear();
}

void myPainterWidget::addLine(QLineF l){
    lines.push_back(l);
}
