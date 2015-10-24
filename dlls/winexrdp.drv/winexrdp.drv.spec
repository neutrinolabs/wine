
# GDI driver
@ cdecl wine_get_gdi_driver(long) xrdpdrv_get_gdi_driver

# USER driver
@ cdecl CreateWindow(long) xrdpdrv_CreateWindow
@ cdecl CreateDesktopWindow(long) xrdpdrv_CreateDesktopWindow

# Desktop
@ cdecl wine_create_desktop(long long) xrdpdrv_create_desktop
