# Plasma Weather Ion Dataengine

---

## Note

Remember that this dataengine relies on a semi-public API,
as exposed by the "plasma/weather/ion.h" header.
While this API has been the same for some time, there is no guarantee
that it will be stable for all future versions of the weather dataengine
as part of Plasma Workspace.

The main purpose of having this interface semi-public is to allow everyone
to easily develop adapters to more weather data providers,
without needing to work directly in the module plasma-workspace.

Once your ion dataengine is nicely working, please consider to merge
it into the KDE module plasma-workspace with the existing ion dataengines.
Looking forward to cover another weather data providers with your help :)

## Build instructions

```bash
cd /where/your/ion/is/generated
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=MYPREFIX -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTING=OFF -DKDE_INSTALL_USE_QT_SYS_PATHS=ON
make
make install
```

(`MYPREFIX` is where you install your Plasma setup, replace it accordingly)

## Test instructions

Test your ion dataengine with
`plasmaengineexplorer --engine weather`
where you should see your ion listed in the default data "ions".
You then can test the ion itself by entering into the field for "Source name" e.g.
`wundergroundpws|weather|foo`
or
`wundergroundpws|validate|foo`
with "foo" being the beginning of the name of a personal station. (ie. KGADACUL1)

Or try to use it from the Plasma Addons Weather widget.
Start the widget in a test window with
`plasmawindowed org.kde.plasma.weather`
and then see to use your ion dataengine by configuring the widget to use
a weatherstation provided via your ion dataengine

## TODO

-   [ ] Use i18?
-   [ ] Add error handling in case station is down
-   [ ] Refactor the key property map
