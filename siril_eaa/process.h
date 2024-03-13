// Provides the interface to Siril for this plugin

#ifndef PROCESS_H
#define PROCESS_H

#include <QObject>
#include <QProcess>
#include <QSocketNotifier>
#include <QFile>

class process : public QObject
{
    Q_OBJECT
public:
    explicit process(QObject *parent = nullptr);

public slots:
    void startProgram(QString path);
    void stopProgram();
//    QString livestackImage(QString filename);

signals:
    void programFinished();
    void programStarted();
    void sirilMessage(QString message);
    void processError(QString error);

private:
    QProcess programProcess;
    bool startLivestacking();
    bool stopLivestacking();
    void readMessage();

    QString sirilMessages = "/tmp/siril_command.out";
    QString sirilCommands = "/tmp/siril_command.in";
    QSocketNotifier* notifier;
    int fd;
    int flags;
    QFile* messagePipe;
    QFile* comandPipe;
    char* buffer;
};

#endif // PROCESS_H
