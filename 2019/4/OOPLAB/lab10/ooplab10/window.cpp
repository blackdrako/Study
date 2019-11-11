#include "renderarea.h"
#include "window.h"
#include <QtWidgets>

const int IdRole = Qt::UserRole;

Window::Window()
{
    renderArea = new RenderArea;

    shapeComboBox = new QComboBox;
    shapeComboBox->addItem(tr("Polygon"), RenderArea::Polygon);
    shapeComboBox->addItem(tr("Rectangle"), RenderArea::Rect);
    shapeComboBox->addItem(tr("Rounded Rectangle"), RenderArea::RoundedRect);
    shapeComboBox->addItem(tr("Ellipse"), RenderArea::Ellipse);
    shapeComboBox->addItem(tr("Pie"), RenderArea::Pie);
    shapeComboBox->addItem(tr("Chord"), RenderArea::Chord);
    shapeComboBox->addItem(tr("Path"), RenderArea::Path);
    shapeComboBox->addItem(tr("Line"), RenderArea::Line);
    shapeComboBox->addItem(tr("Polyline"), RenderArea::Polyline);
    shapeComboBox->addItem(tr("Arc"), RenderArea::Arc);
    shapeLabel = new QLabel(tr("&Shape:"));
    shapeLabel->setBuddy(shapeComboBox);

    penWidthSpinBox = new QSpinBox;
    penWidthSpinBox->setRange(0, 10);
    penWidthSpinBox->setSpecialValueText(tr("0 (cosmetic pen)"));

    penWidthLabel = new QLabel(tr("Pen &Width:"));
    penWidthLabel->setBuddy(penWidthSpinBox);

    penStyleComboBox = new QComboBox;
    penStyleComboBox->addItem(tr("Solid"), static_cast<int>(Qt::SolidLine));
    penStyleComboBox->addItem(tr("Dash"), static_cast<int>(Qt::DashLine));
    penStyleComboBox->addItem(tr("Dot"), static_cast<int>(Qt::DotLine));
    penStyleComboBox->addItem(tr("None"), static_cast<int>(Qt::NoPen));

    penStyleLabel = new QLabel(tr("&Pen Style:"));
    penStyleLabel->setBuddy(penStyleComboBox);

    penColorComboBox = new QComboBox;
    penColorComboBox->addItem(tr("Black"),static_cast<int>(Qt::black));
    penColorComboBox->addItem(tr("Green"),static_cast<int>(Qt::green));
    penColorComboBox->addItem(tr("Red"),static_cast<int>(Qt::red));
    penColorComboBox->addItem(tr("Blue"),static_cast<int>(Qt::blue));

    penColorLabel = new QLabel(tr("&Pen Color:"));
    penColorLabel->setBuddy(penColorComboBox);

    brushStyleComboBox = new QComboBox;
    brushStyleComboBox->addItem(tr("Solid"), static_cast<int>(Qt::SolidPattern));
    brushStyleComboBox->addItem(tr("Horizontal"), static_cast<int>(Qt::HorPattern));
    brushStyleComboBox->addItem(tr("Vertical"), static_cast<int>(Qt::VerPattern));
    brushStyleComboBox->addItem(tr("Cross"), static_cast<int>(Qt::CrossPattern));
    brushStyleComboBox->addItem(tr("Backward Diagonal"), static_cast<int>(Qt::BDiagPattern));
    brushStyleComboBox->addItem(tr("Forward Diagonal"), static_cast<int>(Qt::FDiagPattern));
    brushStyleComboBox->addItem(tr("Diagonal Cross"), static_cast<int>(Qt::DiagCrossPattern));
    brushStyleComboBox->addItem(tr("None"), static_cast<int>(Qt::NoBrush));

    brushStyleLabel = new QLabel(tr("&Brush:"));
    brushStyleLabel->setBuddy(brushStyleComboBox);

    brushColorComboBox = new QComboBox;
    brushColorComboBox->addItem(tr("Green"), static_cast<int>(Qt::green));
    brushColorComboBox->addItem(tr("Red"), static_cast<int>(Qt::red));
    brushColorComboBox->addItem(tr("Blue"), static_cast<int>(Qt::blue));

    brushColorLabel = new QLabel(tr("&ColorBrush:"));
    brushColorLabel->setBuddy(brushColorComboBox);


    connect(shapeComboBox, QOverload<int>::of(&QComboBox::activated),this, &Window::shapeChanged);
    connect(penWidthSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),this, &Window::penChanged);
    connect(penStyleComboBox, QOverload<int>::of(&QComboBox::activated),this, &Window::penChanged);
    connect(penColorComboBox, QOverload<int>::of(&QComboBox::activated),this, &Window::penChanged);
    connect(brushStyleComboBox, QOverload<int>::of(&QComboBox::activated),this, &Window::brushChanged);
    connect(brushColorComboBox, QOverload<int>::of(&QComboBox::activated),this, &Window::brushChanged);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(3, 1);
    mainLayout->addWidget(renderArea, 0, 0, 1, 4);
    mainLayout->addWidget(shapeLabel, 2, 0, Qt::AlignRight);
    mainLayout->addWidget(shapeComboBox, 2, 1);
    mainLayout->addWidget(penWidthLabel, 3, 0, Qt::AlignRight);
    mainLayout->addWidget(penWidthSpinBox, 3, 1);
    mainLayout->addWidget(penStyleLabel, 4, 0, Qt::AlignRight);
    mainLayout->addWidget(penStyleComboBox, 4, 1);
    mainLayout->addWidget(penColorLabel, 3, 2, Qt::AlignRight);
    mainLayout->addWidget(penColorComboBox, 3, 3);
    mainLayout->addWidget(brushStyleLabel, 4, 2, Qt::AlignRight);
    mainLayout->addWidget(brushStyleComboBox, 4, 3);
    mainLayout->addWidget(brushColorLabel, 5, 2, Qt::AlignRight);
    mainLayout->addWidget(brushColorComboBox, 5, 3, Qt::AlignRight);
    setLayout(mainLayout);

    shapeChanged();
    penChanged();
    brushChanged();

    setWindowTitle(tr("Basic Drawing"));
}

void Window::shapeChanged()
{
    RenderArea::Shape shape = RenderArea::Shape(shapeComboBox->itemData(shapeComboBox->currentIndex(), IdRole).toInt());
    renderArea->setShape(shape);
}

void Window::penChanged()
{
    int width = penWidthSpinBox->value();
    Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(penStyleComboBox->currentIndex(), IdRole).toInt());
    Qt::GlobalColor color = Qt::GlobalColor(penColorComboBox->itemData(penColorComboBox->currentIndex(), IdRole).toInt());

    renderArea->setPen(QPen(color, width, style));
}

void Window::brushChanged()
{
    Qt::GlobalColor color = Qt::GlobalColor(brushColorComboBox->itemData(brushColorComboBox->currentIndex(),IdRole).toInt());
    Qt::BrushStyle style = Qt::BrushStyle(brushStyleComboBox->itemData(brushStyleComboBox->currentIndex(), IdRole).toInt());
    renderArea->setBrush(QBrush(color, style));
}
