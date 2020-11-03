#ifndef AIRCRAFTSTATUS_H
#define AIRCRAFTSTATUS_H

#include <QObject>
#include <QMap>
#include "pprz_dispatcher.h"

class AircraftStatus : public QObject
{
    Q_OBJECT
public:
    explicit AircraftStatus(QString ac_id, QObject *parent = nullptr);

    void updateMessage(pprzlink::Message msg);
    std::optional<pprzlink::Message> getMessage(std::string name);

signals:
    void flight_param();
    void ap_status();
    void nav_status();
    void circle_status();
    void segment_status();
    void engine_status();
    void waypoint_moved();
    void dl_values();
    void telemetry_status();
    void fly_by_wire();

public slots:

private:
    QString ac_id;

    QMap<std::string, pprzlink::Message> last_messages;
};

#endif // AIRCRAFTSTATUS_H
