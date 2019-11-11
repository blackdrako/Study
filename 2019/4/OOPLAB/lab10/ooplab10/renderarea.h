#ifndef RENDERAREA_H
#define RENDERAREA_H
#include <QBrush>
#include <QPen>
#include <QWidget>

class RenderArea : public QWidget
{
    Q_OBJECT

public:
    enum Shape { Line, Polyline, Polygon, Rect, RoundedRect, Ellipse, Arc,
                 Chord, Pie, Path};

    RenderArea(QWidget *parent = 0);

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

public slots:
    void setShape(Shape shape);
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Shape shape;
    QPen pen;
    QBrush brush;
};
#endif // RENDERAREA_H
