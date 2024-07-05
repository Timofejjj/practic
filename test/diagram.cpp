#include "diagram.h"

Diagram::Diagram(QWidget* parent) : QWidget(parent)
{
    pen = new QPen();
}

std::istream& operator>>(std::istream& in, Diagram& diagram) {
    diagram.points.clear();
    int height{};
    diagram.MaxHeight = 0;
    while (in >> height) {
        diagram.points.push_back(height);
        diagram.MaxHeight = std::max(diagram.MaxHeight, height);
    }
    diagram.update();
    return in;
}

void Diagram::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.begin(this);


    pen->setColor(Qt::blue);
    pen->setWidth(6);
    painter.setPen(*pen);


    double DiagramWidth = this->height();
    double DiagramHeight = this->width();
    double interval = DiagramWidth / (points.size() + 3);
    double position_x = interval;
    for (auto i : points) {
        double height = (static_cast<double>(i) / MaxHeight) * (DiagramHeight - 20);
        painter.drawLine(height, position_x, 0, position_x);
        position_x += interval;
    }

    painter.end();
}

