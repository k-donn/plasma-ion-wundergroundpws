add_definitions(-DTRANSLATION_DOMAIN=\"plasma_engine_ion_wundergroundpws\")

add_library(ion_wundergroundpws MODULE ion-wundergroundpws.cpp)

target_link_libraries (ion_wundergroundpws
    ${PlasmaWeatherIon_LIBRARIES}
    KF5::Plasma
    KF5::KIOCore
    KF5::UnitConversion
)

kcoreaddons_desktop_to_json(ion_wundergroundpws ion-wundergroundpws.desktop SERVICE_TYPES plasma-dataengine.desktop)

install (FILES ion-wundergroundpws.desktop DESTINATION ${KDE_INSTALL_KSERVICES5DIR})

install (TARGETS ion_wundergroundpws DESTINATION ${KDE_INSTALL_PLUGINDIR}/plasma/dataengine)
