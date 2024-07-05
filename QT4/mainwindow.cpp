#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Pen = new QPen();
    PenPos = new QPoint(0, 0);
    Pen->setColor(Qt::red);  // Изменяем цвет пера на красный

    this->update();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete Pen;
    delete PenPos;
}

void MainWindow::paintEvent(QPaintEvent*)
{
    if (Data.size() == 0)
        return;
    double Step = double(this->width() / MaxElement);
    int Ofset = (this->height()) / (Data.size());
    double Y = Ofset / 2;
    Pen->setWidth((this->height() / Data.size()) * 0.5);
    QPainter Painter(this);
    Painter.begin(this);
    Painter.setPen(*Pen);
    for (int i = 0; i < Data.size(); i++) {
        Painter.drawLine(0, Y, Data[i] * Step, Y);
        Y += Ofset;
    }
    Painter.end();
}

void MainWindow::on_importButton_clicked()
{
    QString File = QFileDialog::getOpenFileName(0, "Open dialog", "", "*.json");
    std::fstream fin(File.toStdString());
    if (!fin.is_open())
        return;
    nlohmann::json tempJson = nlohmann::json::parse(fin);
    fin.close();

    // Merge new data with existing Json
    Json.merge_patch(tempJson);

    UpDate();
    this->update();
}

void MainWindow::on_addButton_clicked()
{
    QString fieldName = ui->fieldName->text();
    if (fieldName.isEmpty())
        return;

    Json[fieldName.toStdString()] = ui->fieldValue->value();
    UpDate();
    this->update();
}

void MainWindow::UpDate()
{
    Data.clear();
    for (auto i : Json)
        Data.push_back(i);
    MaxElement = *(std::max_element(Data.begin(), Data.end()));
}

void MainWindow::on_saveButton_clicked()
{
    QString file = QFileDialog::getSaveFileName(0, "Save dialog", "", "*.json");
    if (file.isEmpty())
        return;
    std::ofstream fout(file.toStdString());
    fout << Json.dump(4);
}

