#ifndef VIEWMODEL
#define VIEWMODEL

#include <QString>
#include <QSettings>
#include <QVector>

class ViewModel
{
    QString serverName;

    QString serverDescription;

    QString serverPassword;

    QString gameMode;

    unsigned short int saveSlot;

    bool pvp;

    bool voteKick;

    unsigned short int maxPlayers;

    unsigned short int serverPort;

    unsigned int connectionTimeout;

    unsigned short int tickRate;

    bool snapshot;

    bool autosaver;

    bool pauseOnEmpty;

public:
    ViewModel();
    ~ViewModel();

    QString getGameType() const;
    void setGameType(const QString &value);
    QString getServerName() const;
    void setServerName(const QString &value);
    QString getServerDescription() const;
    void setServerDescription(const QString &value);
    QString getServerPassword() const;
    void setServerPassword(const QString &value);
    unsigned short getSaveSlot() const;
    void setSaveSlot(unsigned short value);
    bool getPvp() const;
    void setPvp(const bool &value);
    bool getVoteKick() const;
    void setVoteKick(const  &value);
    unsigned short getMaxPlayers() const;
    void setMaxPlayers(unsigned short value);
    unsigned short getServerPort() const;
    void setServerPort(unsigned short value);
    unsigned int getConnectionTimeout() const;
    void setConnectionTimeout(unsigned int value);
    unsigned short getTickRate() const;
    void setTickRate(unsigned short value);
    bool getSnapshot() const;
    void setSnapshot(const bool &value);
    bool getAutosaver() const;
    void setAutosaver(const bool &value);
    bool getPauseOnEmpty() const;
    void setPauseOnEmpty(const bool &value);

    const QVector<unsigned short int>* getSaveSlots() const;
    const QVector<unsigned short int>* getTickRates() const;
    const QVector<QString>* getGameTypes() const;

    void LoadSettings(QString filePath);
    void SaveSettings(QString filePath);
};

#endif // VIEWMODEL
