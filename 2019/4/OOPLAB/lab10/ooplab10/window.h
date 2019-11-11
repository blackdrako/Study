#ifndef WINDOW_Hr
#define WINDOW_H
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QSvgGenerator>
#include <QFileDialog>


QT_BEGIN_NAMESPACE
class QCheckBox;
class QComboBox;
class QLabel;
class QSpinBox;
class QPushButtom;
QT_END_NAMESPACE
class RenderArea;

class Window : public QWidget
{
    Q_OBJECT

public:
    Window();

private slots:
    void shapeChanged();
    void penChanged();
    void brushChanged();
    void on_saveButton_clicked();

private:
    RenderArea *renderArea;
    QLabel *shapeLabel;
    QLabel *penWidthLabel;
    QLabel *penStyleLabel;
    QLabel *penColorLabel;
    QLabel *brushStyleLabel;
    QLabel *brushColorLabel;
    QComboBox *shapeComboBox;
    QSpinBox *penWidthSpinBox;
    QComboBox *penStyleComboBox;
    QComboBox *penColorComboBox;
    QComboBox *brushStyleComboBox;
    QComboBox *brushColorComboBox;
};
#endif // WINDOW_H
