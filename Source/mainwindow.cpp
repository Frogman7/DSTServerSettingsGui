#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    viewModel = new ViewModel();

    QObject::connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::loadSettings);
    QObject::connect(ui->actionSave, &QAction::triggered, this, &MainWindow::saveSettings);
    QObject::connect(ui->actionExit, &QAction::triggered, this, &MainWindow::close);

    PopulateCheckboxes();

    this->filePath = QStandardPaths::locate(QStandardPaths::DocumentsLocation, QString(), QStandardPaths::LocateDirectory) + "Klei/DoNotStarveTogether/settings.ini";

    LoadServerSettings();
}

MainWindow::~MainWindow()
{
    delete viewModel;
    delete ui;
}

void MainWindow::saveSettings()
{
    QMessageBox msgbox;

    if (!this->SaveServerSettings())
    {
        msgbox.setText("There was an error saving the file, changes not saved");
        msgbox.exec();
    }
    else
    {
        msgbox.setText("Changes save successfully");
        msgbox.exec();
    }
}

void MainWindow::loadSettings()
{
    this->filePath = QFileDialog::getOpenFileName(this,
        tr("Open Settings"), "/home", tr("Configuration Files (*.ini)"));

    if (!this->LoadServerSettings())
    {
        QMessageBox msgbox;
        msgbox.setText("Settings file failed to load");
        msgbox.exec();
    }
}

bool MainWindow::LoadServerSettings()
{
    QFileInfo checkFile(this->filePath);

    if (!checkFile.exists() || !checkFile.isFile() || checkFile.suffix() != "ini")
    {
        return false;
    }

    viewModel->LoadSettings(this->filePath);

    ui->serverName_LE->setText(viewModel->getServerName());
    ui->serverDescription_LE->setText(viewModel->getServerDescription());
    ui->serverPassword_LE->setText(viewModel->getServerPassword());
    ui->saveSlot_CB->setCurrentIndex(ui->saveSlot_CB->findData(viewModel->getSaveSlot()));
    ui->gameMode_CB->setCurrentIndex(ui->gameMode_CB->findData(viewModel->getGameType()));
    ui->pvp_CB->setCurrentIndex(ui->pvp_CB->findData(viewModel->getPvp()));
    ui->maxPlayers_SB->setValue(viewModel->getMaxPlayers());
    ui->voteKick_CB->setCurrentIndex(ui->voteKick_CB->findData(viewModel->getVoteKick()));
    ui->serverPort_LE->setText(QString::number(viewModel->getServerPort()));
    ui->connectionTimeout_LE->setText(QString::number(viewModel->getConnectionTimeout()));
    ui->tickRate_CB->setCurrentIndex(ui->tickRate_CB->findData(viewModel->getTickRate()));
    ui->snapShots_CB->setCurrentIndex(ui->snapShots_CB->findData(viewModel->getSnapshot()));
    ui->autoSaver_CB->setCurrentIndex(ui->autoSaver_CB->findData(viewModel->getAutosaver()));
    ui->pauseOnEmpty_CB->setCurrentIndex(ui->pauseOnEmpty_CB->findData(viewModel->getPauseOnEmpty()));

    return true;
}

bool MainWindow::SaveServerSettings()
{
    QFileInfo checkFile(this->filePath);

    if (!checkFile.exists() || !checkFile.isFile() || checkFile.suffix() != "ini")
    {
        return false;
    }

    viewModel->setServerName(ui->serverName_LE->text());
    viewModel->setServerDescription(ui->serverDescription_LE->text());
    viewModel->setServerPassword(ui->serverPassword_LE->text());
    viewModel->setSaveSlot(ui->saveSlot_CB->currentData().toInt());
    viewModel->setGameType(ui->gameMode_CB->currentData().toString());
    viewModel->setPvp(ui->pvp_CB->currentData().toBool());
    viewModel->setMaxPlayers(ui->maxPlayers_SB->value());
    viewModel->setVoteKick(ui->voteKick_CB->currentData().toBool());
    viewModel->setServerPort(ui->serverPort_LE->text().toInt());
    viewModel->setConnectionTimeout(ui->connectionTimeout_LE->text().toInt());
    viewModel->setTickRate(ui->tickRate_CB->currentData().toInt());
    viewModel->setSnapshot(ui->snapShots_CB->currentData().toBool());
    viewModel->setAutosaver(ui->autoSaver_CB->currentData().toBool());
    viewModel->setPauseOnEmpty(ui->pauseOnEmpty_CB->currentData().toBool());

    viewModel->SaveSettings(this->filePath);

    return true;
}

void MainWindow::PopulateCheckboxes()
{
    const QVector<unsigned short int> saveSlots = *viewModel->getSaveSlots();

    for (unsigned int i = 0; i < saveSlots.count(); i++)
    {
        ui->saveSlot_CB->addItem(QString::number(saveSlots[i]), saveSlots[i]);
    }

    const QVector<unsigned short int> tickRates = *viewModel->getTickRates();

    for (unsigned short int i = 0; i < tickRates.count(); i++)
    {
        ui->tickRate_CB->addItem(QString::number(tickRates[i]), tickRates[i]);
    }

    const QVector<QString> gameModes = *viewModel->getGameTypes();

    for (unsigned short int i = 0; i < gameModes.count(); i++)
    {
        QString gameModeName = gameModes[i];
        gameModeName.replace(0,1,gameModeName[0].toUpper());
        ui->gameMode_CB->addItem(gameModeName, gameModes[i]);
    }

    QPair<QString, bool> truefalsePair[2] = { QPair<QString, bool>("True", true), QPair<QString, bool>("False", false)};

    ui->pvp_CB->addItem(truefalsePair[0].first, truefalsePair[0].second);
    ui->pvp_CB->addItem(truefalsePair[1].first, truefalsePair[1].second);

    ui->voteKick_CB->addItem(truefalsePair[0].first, truefalsePair[0].second);
    ui->voteKick_CB->addItem(truefalsePair[1].first, truefalsePair[1].second);

    ui->snapShots_CB->addItem(truefalsePair[0].first, truefalsePair[0].second);
    ui->snapShots_CB->addItem(truefalsePair[1].first, truefalsePair[1].second);

    ui->autoSaver_CB->addItem(truefalsePair[0].first, truefalsePair[0].second);
    ui->autoSaver_CB->addItem(truefalsePair[1].first, truefalsePair[1].second);

    ui->pauseOnEmpty_CB->addItem(truefalsePair[0].first, truefalsePair[0].second);
    ui->pauseOnEmpty_CB->addItem(truefalsePair[1].first, truefalsePair[1].second);
}
