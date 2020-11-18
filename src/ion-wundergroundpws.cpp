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

#include "ion-wundergroundpws.h"

#include <KUnitConversion/Converter>
#include <QJsonArray>
#include <QJsonDocument>

WundergroundPWSIon::WundergroundPWSIon(QObject* parent, const QVariantList& args)
    : IonInterface(parent, args)
{
    setupNamingSchemeMap();
    // call whenever the ion is ready
    setInitialized(true);
}

WundergroundPWSIon::~WundergroundPWSIon()
{
}

// TODO: refactor to something like the icon mappings
void WundergroundPWSIon::setupNamingSchemeMap()
{
    namingSchemeMap = QMap<QString, QString> {
        { QStringLiteral("temp"), QStringLiteral("Temperature") },
        { QStringLiteral("windChill"), QStringLiteral("Windchill") },
        { QStringLiteral("heatIndex"), QStringLiteral("Humindex") },

        { QStringLiteral("winddir"), QStringLiteral("Wind Directin") },
        { QStringLiteral("windSpeed"), QStringLiteral("Wind Speed") },
        { QStringLiteral("windGust"), QStringLiteral("Wind Gust") },

        { QStringLiteral("lat"), QStringLiteral("Latitude") },
        { QStringLiteral("lon"), QStringLiteral("Longitude") },

        { QStringLiteral("country"), QStringLiteral("Country") },
        { QStringLiteral("neighborhood"), QStringLiteral("Place") },
        { QStringLiteral("stationID"), QStringLiteral("Station") },

        { QStringLiteral("realtimeFrequency"), QStringLiteral("Observation Frequency") },
        { QStringLiteral("wxPhraseLong"), QStringLiteral("Current Conditions") },
        { QStringLiteral("iconCode"), QStringLiteral("Condition Icon") },
        { QStringLiteral("obsTimeLocal"), QStringLiteral("Observation Timestamp") },

        { QStringLiteral("humidity"), QStringLiteral("Humidity") },
        { QStringLiteral("dewpt"), QStringLiteral("Dewpoint") },
        { QStringLiteral("pressure"), QStringLiteral("Pressure") },
        { QStringLiteral("pressureTendencyTrend"), QStringLiteral("Pressure Tendeny") },
        { QStringLiteral("visibility"), QStringLiteral("Visibility") },

        { QStringLiteral("uv"), QStringLiteral("UV Index") },
        { QStringLiteral("uvDescription"), QStringLiteral("UV Rating") },
        { QStringLiteral("solarRadiation"), QStringLiteral("Solar Intensity") },
    };
}

QMap<QString, IonInterface::ConditionIcons> WundergroundPWSIon::setupDayIconMappings() const
{
    return QMap<QString, IonInterface::ConditionIcons> {
        { QStringLiteral("0"), Thunderstorm },
        { QStringLiteral("1"), Thunderstorm },
        { QStringLiteral("2"), Thunderstorm },
        { QStringLiteral("3"), Showers },
        { QStringLiteral("4"), Thunderstorm },
        { QStringLiteral("5"), RainSnow },
        { QStringLiteral("6"), FreezingRain },
        { QStringLiteral("7"), FreezingDrizzle },
        { QStringLiteral("8"), FreezingDrizzle },
        { QStringLiteral("9"), LightRain },
        { QStringLiteral("10"), FreezingRain },
        { QStringLiteral("11"), Showers },
        { QStringLiteral("12"), Rain },
        { QStringLiteral("13"), Flurries },
        { QStringLiteral("14"), LightSnow },
        { QStringLiteral("15"), LightSnow },
        { QStringLiteral("16"), Snow },
        { QStringLiteral("17"), Hail },
        { QStringLiteral("18"), FreezingDrizzle },
        { QStringLiteral("19"), NotAvailable },
        { QStringLiteral("20"), NotAvailable },
        { QStringLiteral("21"), Haze },
        { QStringLiteral("22"), NotAvailable },
        { QStringLiteral("23"), ClearWindyDay },
        { QStringLiteral("24"), ClearWindyDay },
        { QStringLiteral("25"), NotAvailable },
        { QStringLiteral("26"), FewCloudsDay },
        { QStringLiteral("27"), PartlyCloudyNight },
        { QStringLiteral("28"), PartlyCloudyDay },
        { QStringLiteral("29"), PartlyCloudyNight },
        { QStringLiteral("30"), PartlyCloudyDay },
        { QStringLiteral("31"), ClearNight },
        { QStringLiteral("32"), ClearDay },
        { QStringLiteral("33"), FewCloudsNight },
        { QStringLiteral("34"), FewCloudsDay },
        { QStringLiteral("35"), Hail },
        { QStringLiteral("36"), ClearDay },
        { QStringLiteral("37"), Thunderstorm },
        { QStringLiteral("38"), ChanceThunderstormDay },
        { QStringLiteral("39"), ChanceShowersDay },
        { QStringLiteral("40"), Rain },
        { QStringLiteral("41"), ChanceSnowDay },
        { QStringLiteral("42"), Snow },
        { QStringLiteral("43"), Snow },
        { QStringLiteral("44"), NotAvailable },
        { QStringLiteral("45"), ChanceShowersNight },
        { QStringLiteral("46"), ChanceSnowNight },
        { QStringLiteral("47"), ChanceThunderstormNight },
    };
}

QMap<QString, IonInterface::ConditionIcons> WundergroundPWSIon::setupNightIconMappings() const
{
    return QMap<QString, IonInterface::ConditionIcons> {
        { QStringLiteral("0"), Thunderstorm },
        { QStringLiteral("1"), Thunderstorm },
        { QStringLiteral("2"), Thunderstorm },
        { QStringLiteral("3"), Showers },
        { QStringLiteral("4"), Thunderstorm },
        { QStringLiteral("5"), RainSnow },
        { QStringLiteral("6"), FreezingRain },
        { QStringLiteral("7"), FreezingDrizzle },
        { QStringLiteral("8"), FreezingDrizzle },
        { QStringLiteral("9"), LightRain },
        { QStringLiteral("10"), FreezingRain },
        { QStringLiteral("11"), Showers },
        { QStringLiteral("12"), Rain },
        { QStringLiteral("13"), Flurries },
        { QStringLiteral("14"), LightSnow },
        { QStringLiteral("15"), LightSnow },
        { QStringLiteral("16"), Snow },
        { QStringLiteral("17"), Hail },
        { QStringLiteral("18"), FreezingDrizzle },
        { QStringLiteral("19"), NotAvailable },
        { QStringLiteral("20"), NotAvailable },
        { QStringLiteral("21"), Haze },
        { QStringLiteral("22"), NotAvailable },
        { QStringLiteral("23"), ClearWindyDay },
        { QStringLiteral("24"), ClearWindyDay },
        { QStringLiteral("25"), NotAvailable },
        { QStringLiteral("26"), FewCloudsDay },
        { QStringLiteral("27"), PartlyCloudyNight },
        { QStringLiteral("28"), PartlyCloudyDay },
        { QStringLiteral("29"), PartlyCloudyNight },
        { QStringLiteral("30"), PartlyCloudyDay },
        { QStringLiteral("31"), ClearNight },
        { QStringLiteral("32"), ClearDay },
        { QStringLiteral("33"), FewCloudsNight },
        { QStringLiteral("34"), FewCloudsDay },
        { QStringLiteral("35"), Hail },
        { QStringLiteral("36"), ClearDay },
        { QStringLiteral("37"), Thunderstorm },
        { QStringLiteral("38"), ChanceThunderstormDay },
        { QStringLiteral("39"), ChanceShowersDay },
        { QStringLiteral("40"), Rain },
        { QStringLiteral("41"), ChanceSnowDay },
        { QStringLiteral("42"), Snow },
        { QStringLiteral("43"), Snow },
        { QStringLiteral("44"), NotAvailable },
        { QStringLiteral("45"), ChanceShowersNight },
        { QStringLiteral("46"), ChanceSnowNight },
        { QStringLiteral("47"), ChanceThunderstormNight },
    };
}

QMap<QString, IonInterface::ConditionIcons> const& WundergroundPWSIon::dayIcons() const
{
    static QMap<QString, ConditionIcons> const dval = setupDayIconMappings();
    return dval;
}

QMap<QString, IonInterface::ConditionIcons> const& WundergroundPWSIon::nightIcons() const
{
    static QMap<QString, ConditionIcons> const nval = setupNightIconMappings();
    return nval;
}

bool WundergroundPWSIon::updateIonSource(const QString& source)
{
    // We expect the applet to send the source in the following tokenization:
    // ionname:validate:place_name - Triggers validation of place
    // ionname:weather:place_name - Triggers receiving weather of place

    const QStringList sourceAction = source.split(QLatin1Char('|'));

    // Guard: if the size of array is not 2 then we have bad data, return an error
    if (sourceAction.size() < 2) {
        setData(source, QStringLiteral("validate"), "wundergroundpws|malformed");
        return true;
    }

    if (sourceAction.at(1) == QLatin1String("validate") && sourceAction.size() > 2) {
        fetchValidStations(sourceAction[2], source);
        return true;
    }

    if (sourceAction.at(1) == QLatin1String("weather") && sourceAction.size() > 2) {
        fetchObservationData(sourceAction[2], source);
        return true;
    }

    setData(source, QStringLiteral("validate"), "wundergroundpws|malformed");
    return true;
}

void WundergroundPWSIon::reset()
{
}

// purpose: fetch/use data from provider and trigger processing of returned data in a handler
void WundergroundPWSIon::fetchValidStations(const QString& place, const QString& source)
{
    const QUrl url(QStringLiteral("https://api.weather.com/v3/location/search?query=") + place + QStringLiteral("&locationType=pws&language=en-US&format=json&apiKey=6532d6454b8aa370768e63d6ba5a832e"));

    KIO::TransferJob* getJob = KIO::get(url, KIO::Reload, KIO::HideProgressInfo);
    getJob->addMetaData(QStringLiteral("Accept-Encoding"), QStringLiteral("gzip"));

    m_jobJson.insert(getJob, new QByteArray());
    m_jobList.insert(getJob, source);

    connect(getJob, &KIO::TransferJob::data, this, &WundergroundPWSIon::search_slotDataArrived);
    connect(getJob, &KJob::result, this, &WundergroundPWSIon::search_slotJobFinished);
}

// purpose: fetch data from provider and trigger processing of returned data in a handler
void WundergroundPWSIon::fetchObservationData(const QString& stationId, const QString& source)
{
    const QUrl obsUrl(QStringLiteral("https://api.weather.com/v2/pws/observations/current?stationId=") + stationId + QStringLiteral("&units=m&format=json&apiKey=6532d6454b8aa370768e63d6ba5a832e&numericPrecision=decimal"));

    qDebug() << obsUrl;

    KIO::TransferJob* getJob = KIO::get(obsUrl, KIO::Reload, KIO::HideProgressInfo);
    getJob->addMetaData(QStringLiteral("Accept-Encoding"), QStringLiteral("gzip"));

    m_jobJson.insert(getJob, new QByteArray());
    m_jobList.insert(getJob, source);

    connect(getJob, &KIO::TransferJob::data, this, &WundergroundPWSIon::observation_slotDataArrived);
    connect(getJob, &KJob::result, this, &WundergroundPWSIon::observation_slotJobFinished);
}

void WundergroundPWSIon::fetchDemandData(const QString& latitude, const QString& longitude, const QString& source)
{
    const QString geocode = QString(latitude + QStringLiteral(",") + longitude);

    const QUrl demandUrl(QStringLiteral("https://api.weather.com/v3/wx/observations/current?geocode=") + geocode + QStringLiteral("9&units=m&language=en-US&format=json&apiKey=6532d6454b8aa370768e63d6ba5a832e"));

    qDebug() << demandUrl;

    QStringList* latLongList = new QStringList();

    latLongList->append(latitude);
    latLongList->append(longitude);

    KIO::TransferJob* demandJob = KIO::get(demandUrl, KIO::Reload, KIO::HideProgressInfo);
    demandJob->addMetaData(QStringLiteral("Accept-Encoding"), QStringLiteral("gzip"));

    m_jobJson.insert(demandJob, new QByteArray());
    m_jobLatLong.insert(demandJob, latLongList);
    m_jobList.insert(demandJob, source);

    connect(demandJob, &KIO::TransferJob::data, this, &WundergroundPWSIon::demand_slotDataArrived);
    connect(demandJob, &KJob::result, this, &WundergroundPWSIon::demand_slotJobFinished);
}

void WundergroundPWSIon::fetchForecastData(const QString& latitude, const QString& longitude, const QString& source)
{
    const QUrl forecastUrl(QStringLiteral("https://api.weather.com/v1/geocode/") + latitude + QStringLiteral("/") + longitude + QStringLiteral("/forecast/daily/7day.json?units=m&language=en-US&apiKey=6532d6454b8aa370768e63d6ba5a832e"));

    qDebug() << forecastUrl;

    KIO::TransferJob* forecastJob = KIO::get(forecastUrl, KIO::Reload, KIO::HideProgressInfo);
    forecastJob->addMetaData(QStringLiteral("Accept-Encoding"), QStringLiteral("gzip"));

    m_jobJson.insert(forecastJob, new QByteArray());
    m_jobList.insert(forecastJob, source);

    connect(forecastJob, &KIO::TransferJob::data, this, &WundergroundPWSIon::forecast_slotDataArrived);
    connect(forecastJob, &KJob::result, this, &WundergroundPWSIon::forecast_slotJobFinished);
}

void WundergroundPWSIon::search_slotDataArrived(KIO::Job* job, const QByteArray& data)
{
    if (data.isEmpty() || !m_jobJson.contains(job)) {
        return;
    }

    m_jobJson[job]->append(data);
}

void WundergroundPWSIon::search_slotJobFinished(KJob* job)
{
    const QString source = m_jobList[job];

    QByteArray* reply = m_jobJson[job];

    QJsonObject resValues;

    QJsonParseError err;

    QJsonDocument resPage = QJsonDocument::fromJson(*reply, &err);

    if (err.error != QJsonParseError::NoError) {
        qDebug() << "[SEARCH] JSON parse error";

        m_jobList.remove(job);
        delete m_jobJson[job];
        m_jobJson.remove(job);

        return;
    }

    if (!resPage.isNull()) {
        resValues = resPage.object();

        QJsonObject location = resValues["location"].toObject();
        QJsonArray stations = location["pwsId"].toArray();

        QStringList res;

        for (const QJsonValue& stationId : stations) {
            res.append(stationId.toString());
        }

        m_jobList.remove(job);
        delete m_jobJson[job];
        m_jobJson.remove(job);

        onValidateReport(res, source);
    }
}

void WundergroundPWSIon::observation_slotDataArrived(KIO::Job* job, const QByteArray& data)
{
    if (data.isEmpty() || !m_jobJson.contains(job)) {
        return;
    }

    m_jobJson[job]->append(data);
}
void WundergroundPWSIon::observation_slotJobFinished(KJob* job)
{
    const QString source = m_jobList[job];

    QByteArray* reply = m_jobJson[job];

    QJsonObject resValues;

    QJsonParseError err;

    QJsonDocument resPage = QJsonDocument::fromJson(*reply, &err);

    if (err.error != QJsonParseError::NoError) {
        qDebug() << "[OBSERVATION] JSON parse error";

        m_jobList.remove(job);
        delete m_jobJson[job];
        m_jobJson.remove(job);

        return;
    }

    if (!resPage.isNull()) {
        resValues = resPage.object();

        QJsonArray obsArr = resValues["observations"].toArray();
        QJsonObject obsObj = obsArr[0].toObject();
        QJsonObject obsDetails = obsObj["metric"].toObject();

        // Removing "metric" object allows for all key/value pairs to be converted in loop
        obsObj.remove(QStringLiteral("metric"));

        for (const QString& key : obsObj.keys()) {
            QVariant value = obsObj[key].toVariant();

            weatherData.insert(namingSchemeMap[key], value);
        }

        for (const QString& key : obsDetails.keys()) {
            QVariant value = obsDetails[key].toVariant();

            weatherData.insert(namingSchemeMap[key], value);
        }

        weatherData.insert("Temperature Unit", KUnitConversion::Celsius);
        weatherData.insert("Wind Speed Unit", KUnitConversion::KilometerPerHour);
        weatherData.insert("Wind Gust Unit", KUnitConversion::Celsius);
        weatherData.insert("Dewpoint Unit", KUnitConversion::Celsius);
        weatherData.insert("Pressure Unit", KUnitConversion::Hectopascal);
        weatherData.insert("Credit Url", "https://www.wunderground.com/pws/overview");
        weatherData.insert("Credit", "Data from Wunderground PWS Network");

        m_jobList.remove(job);
        delete m_jobJson[job];
        m_jobJson.remove(job);

        qDebug() << weatherData;

        QString latitude = weatherData["Latitude"].toString();
        QString longitude = weatherData["Longitude"].toString();

        fetchDemandData(latitude, longitude, source);
    }
}

void WundergroundPWSIon::demand_slotDataArrived(KIO::Job* job, const QByteArray& data)
{
    if (data.isEmpty() || !m_jobJson.contains(job)) {
        return;
    }

    m_jobJson[job]->append(data);
}

void WundergroundPWSIon::demand_slotJobFinished(KJob* job)
{
    const QString source = m_jobList[job];

    QByteArray* reply = m_jobJson[job];

    QStringList* latLongList = m_jobLatLong[job];

    QJsonObject resValues;

    QJsonParseError err;

    QJsonDocument resPage = QJsonDocument::fromJson(*reply, &err);

    if (err.error != QJsonParseError::NoError) {
        qDebug() << "[DEMAND] JSON parse error";

        m_jobList.remove(job);
        delete m_jobJson[job];
        delete m_jobLatLong[job];
        m_jobJson.remove(job);
        m_jobLatLong.remove(job);

        return;
    }

    if (!resPage.isNull()) {
        resValues = resPage.object();

        for (const QString& key : resValues.keys()) {
            if (namingSchemeMap.contains(key)) {
                QVariant value = resValues[key].toVariant();

                int keyIsIconCode = QString::compare(key, QString("iconCode"), Qt::CaseInsensitive);

                if (keyIsIconCode == 0) {
                    weatherData.insert(namingSchemeMap[key], getWeatherIcon(dayIcons(), value.toString()));
                } else {
                    weatherData.insert(namingSchemeMap[key], value);
                }
            }
        }

        weatherData.insert("Visibility Unit", KUnitConversion::Kilometer);

        QString lat = latLongList->at(0);
        QString lon = latLongList->at(1);

        m_jobList.remove(job);
        delete m_jobJson[job];
        delete m_jobLatLong[job];
        m_jobJson.remove(job);
        m_jobLatLong.remove(job);

        fetchForecastData(lat, lon, source);
    }
}

void WundergroundPWSIon::forecast_slotDataArrived(KIO::Job* job, const QByteArray& data)
{
    if (data.isEmpty() || !m_jobJson.contains(job)) {
        return;
    }

    m_jobJson[job]->append(data);
}

void WundergroundPWSIon::forecast_slotJobFinished(KJob* job)
{
    const QString source = m_jobList[job];

    QByteArray* reply = m_jobJson[job];

    QJsonObject resValues;

    QJsonParseError err;

    QJsonDocument resPage = QJsonDocument::fromJson(*reply, &err);

    if (err.error != QJsonParseError::NoError) {
        qDebug() << "[FORECAST] JSON parse error";

        m_jobList.remove(job);
        delete m_jobJson[job];
        m_jobJson.remove(job);

        return;
    }

    if (!resPage.isNull()) {
        resValues = resPage.object();

        QJsonArray forecasts = resValues["forecasts"].toArray();

        weatherData.insert("Total Weather Days", "7");

        // Exclude current day
        for (int i = 1; i < forecasts.size(); ++i) {
            QJsonObject forecast = forecasts[i].toObject();

            QJsonObject dayPart = forecast["day"].toObject();

            QString dayReport;

            QString stringDate = dayPart["fcst_valid_local"].toString();

            // Cut off timezone and time part (2020-11-05T07:00:00-0500)
            stringDate.chop(14);

            QString monthDay = stringDate.right(2);

            monthDay.remove(QRegExp("^[0]*"));

            dayReport.append(monthDay).append("|");

            dayReport.append(getWeatherIcon(dayIcons(), QString::number(dayPart["icon_code"].toInt()))).append("|");

            dayReport.append(dayPart["shortcast"].toString()).append("|");

            dayReport.append(QString::number(forecast["max_temp"].toDouble())).append("|");

            dayReport.append(QString::number(forecast["min_temp"].toDouble())).append("|");

            weatherData.insert(QString("Short Forecast Day %1").arg(i - 1), dayReport);
        }

        onWeatherDataReport(source);
    }
}

// purpose: process data from provider and turn into DataEngine data
void WundergroundPWSIon::onValidateReport(const QStringList& placeList, const QString& source)
{
    const QStringList sourceAction = source.split(QLatin1Char('|'));

    if (placeList.size() == 1) {
        setData(source, QStringLiteral("validate"), QStringLiteral("wundergroundpws|valid|single|place|").append(placeList.at(0)));
        return;
    }
    if (placeList.size() > 1) {
        setData(source, QStringLiteral("validate"), QStringLiteral("wundergroundpws|valid|multiple|place|").append(placeList.join(QStringLiteral("|place|"))));
        return;
    }
    if (placeList.size() == 0) {
        setData(source, QStringLiteral("validate"), QStringLiteral("wundergroundpws|invalid|single|").append(sourceAction.at(2)));
        return;
    }
}

// purpose: process data from provider and turn into DataEngine data for the given source key
void WundergroundPWSIon::onWeatherDataReport(const QString& source)
{
    // finally set the created data for the given source key, so it will be pushed out to all consumers
    setData(source, weatherData);
}

K_EXPORT_PLASMA_DATAENGINE_WITH_JSON(wundergroundpws, WundergroundPWSIon, "ion-wundergroundpws.json")

#include "ion-wundergroundpws.moc"
