#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardPaths>
#include <QFileInfo>
#include <QFileDialog>
#include <QMessageBox>
#include "viewmodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void saveSettings();
    void loadSettings();

private:
    Ui::MainWindow *ui;
    ViewModel *viewModel;
    QString filePath;

    bool SaveServerSettings();
    bool LoadServerSettings();
    void PopulateCheckboxes();
};

#endif // MAINWINDOW_H
