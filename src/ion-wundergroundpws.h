/*
 *   Copyright (C) 2020 by k-donn <>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU Library General Public License as
 *   published by the Free Software Foundation; either version 2, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details
 *
 *   You should have received a copy of the GNU Library General Public
 *   License along with this program; if not, write to the
 *   Free Software Foundation, Inc.,
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef IONWUNDERGROUNDPWS_H
#define IONWUNDERGROUNDPWS_H

#include <KIO/Job>
#include <plasma/weather/ion.h>

class Q_DECL_EXPORT WundergroundPWSIon : public IonInterface {
    Q_OBJECT

public:
    WundergroundPWSIon(QObject* parent, const QVariantList& args);
    ~WundergroundPWSIon();

public: // IonInterface API
    bool updateIonSource(const QString& source) override;
    void reset() override;

private Q_SLOTS:
    void search_slotDataArrived(KIO::Job*, const QByteArray&);
    void search_slotJobFinished(KJob* job);

    void observation_slotDataArrived(KIO::Job*, const QByteArray&);
    void observation_slotJobFinished(KJob*);

    void demand_slotDataArrived(KIO::Job*, const QByteArray&);
    void demand_slotJobFinished(KJob*);

    void forecast_slotDataArrived(KIO::Job*, const QByteArray&);
    void forecast_slotJobFinished(KJob* job);

private:
    void setupNamingSchemeMap();
    QMap<QString, IonInterface::ConditionIcons> setupDayIconMappings() const;
    QMap<QString, IonInterface::ConditionIcons> setupNightIconMappings() const;

    QMap<QString, IonInterface::ConditionIcons> const& dayIcons() const;
    QMap<QString, IonInterface::ConditionIcons> const& nightIcons() const;

    void fetchValidStations(const QString& place, const QString& source);
    void fetchObservationData(const QString& stationId, const QString& source);
    void fetchDemandData(const QString& latitude, const QString& longitude, const QString& source);
    void fetchForecastData(const QString& latitude, const QString& longitude, const QString& source);

    void onValidateReport(const QStringList& placeList, const QString& source);
    void onWeatherDataReport(const QString& source);

private:
    Plasma::DataEngine::Data weatherData;

    QMap<QString, QString> namingSchemeMap;

    QHash<KJob*, QString> m_jobList;
    QHash<KJob*, QByteArray*> m_jobJson;
    QHash<KJob*, QStringList*> m_jobLatLong;
};

#endif
