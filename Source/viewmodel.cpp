#include "viewmodel.h"

const char* serverNameSetting = "default_server_name";
const char* serverDescriptionSetting = "default_server_description";
const char* serverPasswordSetting = "server_password";
const char* serverSaveSlotSetting = "server_save_slot";
const char* gamemodeSetting = "game_mode";
const char* pvpSetting = "pvp";
const char* voteKickSetting = "enable_vote_kick";
const char* maxPlayersSetting = "max_players";
const char* serverPortSetting = "server_port";
const char* connectionTimeoutSetting = "connection_timeout";
const char* tickRateSetting = "tick_rate";
const char* snapshotsSetting = "enable_snapshots";
const char* autosaverSetting = "enable_autosaver";
const char* pauseOnEmptySetting = "pause_when_empty";

QVector<unsigned short int>* saveSlots;
QVector<unsigned short int>* tickRates;
QVector<QString>* gameModes;

ViewModel::ViewModel()
{
}

ViewModel::~ViewModel()
{
    delete saveSlots;
    delete tickRates;
    delete gameModes;
}

QString ViewModel::getServerName() const
{
    return serverName;
}

void ViewModel::setServerName(const QString &value)
{
    serverName = value;
}

QString ViewModel::getServerDescription() const
{
    return serverDescription;
}

void ViewModel::setServerDescription(const QString &value)
{
    serverDescription = value;
}

QString ViewModel::getServerPassword() const
{
    return serverPassword;
}

void ViewModel::setServerPassword(const QString &value)
{
    serverPassword = value;
}

unsigned short ViewModel::getSaveSlot() const
{
    return saveSlot;
}

void ViewModel::setSaveSlot(unsigned short value)
{
    saveSlot = value;
}

bool ViewModel::getPvp() const
{
    return pvp;
}

void ViewModel::setPvp(const bool &value)
{
    pvp = value;
}

bool ViewModel::getVoteKick() const
{
    return voteKick;
}

void ViewModel::setVoteKick(const  &value)
{
    voteKick = value;
}

unsigned short ViewModel::getMaxPlayers() const
{
    return maxPlayers;
}

void ViewModel::setMaxPlayers(unsigned short value)
{
    maxPlayers = value;
}

unsigned short ViewModel::getServerPort() const
{
    return serverPort;
}

void ViewModel::setServerPort(unsigned short value)
{
    serverPort = value;
}

unsigned int ViewModel::getConnectionTimeout() const
{
    return connectionTimeout;
}

void ViewModel::setConnectionTimeout(unsigned int value)
{
    connectionTimeout = value;
}

unsigned short ViewModel::getTickRate() const
{
    return tickRate;
}

void ViewModel::setTickRate(unsigned short value)
{
    tickRate = value;
}

bool ViewModel::getSnapshot() const
{
    return snapshot;
}

void ViewModel::setSnapshot(const bool &value)
{
    snapshot = value;
}

bool ViewModel::getAutosaver() const
{
    return autosaver;
}

void ViewModel::setAutosaver(const bool &value)
{
    autosaver = value;
}

bool ViewModel::getPauseOnEmpty() const
{
    return pauseOnEmpty;
}

void ViewModel::setPauseOnEmpty(const bool &value)
{
    pauseOnEmpty = value;
}

QString ViewModel::getGameType() const
{
    return gameMode;
}

void ViewModel::setGameType(const QString &value)
{
    gameMode = value;
}

const QVector<unsigned short int>* ViewModel::getSaveSlots() const
{
    saveSlots = new QVector<unsigned short int>(5);

    for (unsigned short int i = 0; i < 5; i++)
    {
        (*saveSlots)[i] = i + 1;
    }

    return saveSlots;
}

const QVector<QString>* ViewModel::getGameTypes() const
{
    gameModes = new QVector<QString>(3);
    (*gameModes)[0] = "endless";
    (*gameModes)[1] = "survival";
    (*gameModes)[2] = "wilderness";

    return gameModes;
}

const QVector<unsigned short int>* ViewModel::getTickRates() const
{
    tickRates = new QVector<unsigned short int>(4);

    (*tickRates)[0] = 10;
    (*tickRates)[1] = 15;
    (*tickRates)[2] = 30;
    (*tickRates)[3] = 60;

    return tickRates;
}

void ViewModel::LoadSettings(QString filePath)
{
    QSettings settings(filePath, QSettings::IniFormat);
    settings.beginGroup("network");
    this->setServerName(settings.value(serverNameSetting, "Default Server Name").toString());
    this->setServerDescription(settings.value(serverDescriptionSetting, "Server Description").toString());
    this->setServerPassword(settings.value(serverPasswordSetting, "").toString());
    this->setSaveSlot(settings.value(serverSaveSlotSetting, "1").toInt());
    this->setGameType(settings.value(gamemodeSetting, "survival").toString());
    this->setPvp(settings.value(pvpSetting, "false").toBool());
    this->setVoteKick(settings.value(voteKickSetting, "true").toBool());
    this->setMaxPlayers(settings.value(maxPlayersSetting, "4").toInt());
    this->setServerPort(settings.value(serverPortSetting, "10999").toInt());
    this->setConnectionTimeout(settings.value(connectionTimeoutSetting, "8000").toInt());
    this->setTickRate(settings.value(tickRateSetting, "30").toInt());
    this->setSnapshot(settings.value(snapshotsSetting, "false").toBool());
    this->setAutosaver(settings.value(autosaverSetting, "true").toBool());
    this->setPauseOnEmpty(settings.value(pauseOnEmptySetting, "false").toBool());
    settings.endGroup();
    settings.beginGroup("account");
    settings.endGroup();
}

void ViewModel::SaveSettings(const QString filePath)
{
    QSettings settings(filePath, QSettings::IniFormat);
    settings.beginGroup("network");
    settings.setValue(serverNameSetting, this->getServerName());
    settings.setValue(serverDescriptionSetting, this->getServerDescription());
    settings.setValue(serverPasswordSetting, this->getServerPassword());
    settings.setValue(serverSaveSlotSetting, this->getSaveSlot());
    settings.setValue(gamemodeSetting, this->getGameType());
    settings.setValue(pvpSetting, this->getPvp());
    settings.setValue(voteKickSetting, this->getVoteKick());
    settings.setValue(maxPlayersSetting, this->getMaxPlayers());
    settings.setValue(serverPortSetting, this->getServerPort());
    settings.setValue(connectionTimeoutSetting, this->getConnectionTimeout());
    settings.setValue(tickRateSetting, this->getTickRate());
    settings.setValue(snapshotsSetting, this->getSnapshot());
    settings.setValue(autosaverSetting, this->getAutosaver());
    settings.setValue(pauseOnEmptySetting, this->getPauseOnEmpty());
    settings.endGroup();
}
