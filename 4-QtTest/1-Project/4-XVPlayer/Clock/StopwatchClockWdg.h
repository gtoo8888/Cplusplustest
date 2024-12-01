#ifndef STOPWATCHCLOCKWDG_H
#define STOPWATCHCLOCKWDG_H

#include <QWidget>
#include <QTime>
#include <QTimer>
#include <QVector>

namespace Ui {
class StopwatchClockWdg;
}

typedef struct{
    uint8_t index;
    QString nowTime;
}TimeCountInfo;


class StopwatchClockWdg : public QWidget
{
    Q_OBJECT
public:
    enum ClockStatus{
        stop = 0,
        pause,
        run
    };
    enum NameModifyStatus{
        modify = 0,
        lock,
    };

public:
    explicit StopwatchClockWdg(QWidget *parent = nullptr);
    ~StopwatchClockWdg();
    void setClockIndex(uint8_t idx);

private slots:
    void slotBtnStart(void);
    void slotBtnReset(void);
    void slotBtnDownload(void);
    void slotBtnTimeCount(void);
    void slotBtnNameModify(void);
    void slotUpdateDisplay(void);



private:
    void initUi(void);
    void initConnect(void);
    void cleanTableWdg(void);

    Ui::StopwatchClockWdg *ui;
    ClockStatus clockNowStatus;
    NameModifyStatus nameModifyStatus;
    QTimer* nowTime;
    QTime baseTime;
    uint8_t clockIndex;
    uint8_t nowClockCount;

    QString timeStr;
    QString initTimeStr = QString("00:00:00.000");
    QString stopwatchClockName = QString("Stopwatch");
    QVector<TimeCountInfo> vTimeCount;
};

#endif // STOPWATCHCLOCKWDG_H
