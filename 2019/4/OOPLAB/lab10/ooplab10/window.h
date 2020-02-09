#ifndef WINDOW_Hr
#define WINDOW_H
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QFileDialog>
#include <QPushButton>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QComboBox;
class QLabel;
class QSpinBox;
QT_END_NAMESPACE
class RenderArea;

class Window : public QWidget
{
    Q_OBJECT

public:
    Window();

private:
    RenderArea *renderArea;
    QPushButton *SaveGameButton;
    QPushButton *LoadGameButton;
    QPushButton *ExitGameButton;
    QLabel *penWidthLabel;
    QLabel *penStyleLabel;
    QLabel *penColorLabel;
    QLabel *brushStyleLabel;
    QLabel *brushColorLabel;
    QSpinBox *penWidthSpinBox;
    QComboBox *penStyleComboBox;
    QComboBox *penColorComboBox;
    QComboBox *brushStyleComboBox;
    QComboBox *brushColorComboBox;
};
#endif // WINDOW_H
