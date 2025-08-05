#include "user_aircraft_data.h"

QString ModeSEhsConfigInfo::ToJson() const
{
    QJsonObject obj;

    obj["ias"] = QJsonValue::Null;
    obj["mach"] = QJsonValue::Null;
    obj["selectedAltitude"] = QJsonValue::Null;

   if (HasIAS())
    {
        obj["ias"] = std::round(std::max(IAS, 0.0));
    }

    if (HasMach())
    {
        obj["mach"] = std::round(std::max(Mach * 100, 0.0));
    }

    if (HasSelectedAltitude())
    {
        obj["selectedAltitude"] = std::round(std::max(SelectedAltitudeFt, 0.0));
    }

    QJsonDocument doc(obj);
    return doc.toJson(QJsonDocument::Compact);
}