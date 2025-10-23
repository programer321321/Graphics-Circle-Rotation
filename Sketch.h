//
// Created by vasimasr on 23-Oct-25.
//

#ifndef CODING4434_SKETCH_H
#define CODING4434_SKETCH_H


#include <QMainWindow>
#include <QPainter>
#include <qDebug>
#include <QMouseEvent>
#include <QStaticText>
#include <cmath>

using namespace std;

class Sketch : public QMainWindow {
    Q_OBJECT
    float mouseX = 0;
    float mouseY = 0;

public:
    explicit Sketch(QMainWindow *parent = nullptr) : QMainWindow(parent) {
        setFixedSize(600, 600);
        setWindowTitle("coding4145");
        QIcon logo = QIcon("E:\\CLionProjects\\GraphicsPrograms\\Graphics\\coding4452345\\img.png");
        setWindowIcon(logo);
        show();
    }
private:
    float x;
    float y;
    float velocity;
    float radius;
    float width;
    float height;
    qreal angle;
    bool setupProgram = true;
    void setup() {
        x = 0;
        y = 0;
        velocity = 0;
        radius = 200;
        width = 600;
        height = 600;
        angle = 0;
    }

    void draw(QPainter *drawTool) {
        // background
        drawTool->setPen(Qt::NoPen);
        QBrush backgroundBrush;
        backgroundBrush.setColor(Qt::green);
        backgroundBrush.setStyle(Qt::CrossPattern);
        drawTool->setBrush(backgroundBrush);
        drawTool->drawRect(0, 0, 600, 600);
        // bouncing ball program
        QPen pen;
        pen.setColor(Qt::blue);
        pen.setStyle(Qt::DashDotLine);
        drawTool->setPen(pen);
        QBrush brush;
        brush.setColor(Qt::green);
        brush.setStyle(Qt::SolidPattern);
        drawTool->setBrush(brush);
        drawTool->save();
        drawTool->translate(width / 2, height / 2);
        drawTool->translate(x, y);
        drawTool->rotate(angle);
        drawTool->drawEllipse(x, y, radius, radius);
        drawTool->restore();
        angle += 0.01;
        x += velocity * cos(angle);
        y += velocity * sin(angle);
    }
    void paintEvent(QPaintEvent *) override {
        QPainter drawTool(this);
        if (setupProgram) {
            setup();
            setupProgram = false;
        }
        draw(&drawTool);
        update();
    }
    void mousePressEvent(QMouseEvent * mouse ) override {
        QPoint mousePoint = mouse->pos();
        mouseX = mousePoint.x();
        mouseY = mousePoint.y();
        qDebug() << mouseX << " " << mouseY;
        repaint();
    }
    void mouseMoveEvent(QMouseEvent* mouse) override {
        QPoint mousePoint = mouse->pos();
        mouseX = mousePoint.x();
        mouseY = mousePoint.y();
        qDebug() << mouseX << " " << mouseY;
        update();
        repaint();
    }
};


#endif //CODING4434_SKETCH_H