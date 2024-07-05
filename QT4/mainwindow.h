#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPainter>
#include <QLineF>
#include <QString>
#include <QFileDialog>
#include <vector>
#include <fstream>
#include "json.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void on_importButton_clicked();

    void on_addButton_clicked();

    void on_saaveButton_clicked();

private:
    std::vector<int> Data;
    Ui::MainWindow *ui;
    nlohmann::json Json;
    QPen *Pen;
    QPoint *PenPos;
    int MaxElement;
    void UpDate();
};
#endif // MAINWINDOW_H
