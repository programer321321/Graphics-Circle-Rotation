//
// Created by vasimasr on 23-Oct-25.
//

#ifndef CODING4434_SKETCH_H
#define CODING4434_SKETCH_H


#include <QMainWindow>
#include <QPainter>
#include <QPicture>
#include <qDebug>
#include <QMouseEvent>

using namespace std;

class Sketch : public QMainWindow {
    Q_OBJECT
    float mouseX = 0;
    float mouseY = 0;
    float width = 600;
    float height = 600;
    QIcon logo;
public:
    explicit Sketch(QMainWindow *parent = nullptr) : QMainWindow(parent) {
        setFixedSize(width, height);
        setWindowTitle("coding4145");
        logo = QIcon("E:\\CLionProjects\\GraphicsPrograms\\Graphics\\coding4452345\\img.png");
        setWindowIcon(logo);
        show();
    }
private:
    bool setupProgram = true;
    void setup() {

    }

    void draw(QPainter *drawTool) {
        drawTool->setBrush(Qt::black);
        drawTool->setPen(Qt::NoPen);
        drawTool->drawRect(0, 0, 600, 600);
        drawTool->setPen(QPen(Qt::white));
        drawTool->drawEllipse(width / 2, height / 2, 150, 150);
        int size = (int)(width * height);
        QPoint *points = new QPoint[size];
        points[0] = QPoint(0, 0);
        drawTool->drawPoints(points, width*height);
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