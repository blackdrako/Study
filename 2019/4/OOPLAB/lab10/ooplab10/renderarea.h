#ifndef RENDERAREA_H
#define RENDERAREA_H
#include <QWidget>

class RenderArea : public QWidget
{
    Q_OBJECT

public:
    RenderArea(QWidget *parent = nullptr);
    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;
protected:
    void paintEvent(QPaintEvent *event) override;
};
#endif // RENDERAREA_H
