
#include "config.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include "windef.h"
#include "winbase.h"
#include "winreg.h"
#include "wine/debug.h"

#include "wingdi.h"
#include "winuser.h"
#include "wine/gdi_driver.h"
#include "wine/list.h"

WINE_DEFAULT_DEBUG_CHANNEL(xrdpdrv);

static BOOL xrdpdrv_CreateCompatibleDC(PHYSDEV orig, PHYSDEV *pdev)
{
    printf("xrdpdrv_CreateCompatibleDC:\n");
    //push_dc_driver(pdev, &physDev->dev, &macdrv_funcs);
    return 1;
}

static BOOL xrdpdrv_CreateDC(PHYSDEV *pdev, LPCWSTR driver, LPCWSTR device,
                             LPCWSTR output, const DEVMODEW* initData)
{
    printf("xrdpdrv_CreateDC:\n");
    return 1;
}

static BOOL xrdpdrv_DeleteDC(PHYSDEV dev)
{
    printf("xrdpdrv_DeleteDC:\n");
    return 1;
}

static INT xrdpdrv_GetDeviceCaps(PHYSDEV dev, INT cap)
{
    printf("xrdpdrv_GetDeviceCaps:\n");
    return 1;
}

static const struct gdi_dc_funcs xrdpdrv_funcs =
{
    NULL,                               /* pAbortDoc */
    NULL,                               /* pAbortPath */
    NULL,                               /* pAlphaBlend */
    NULL,                               /* pAngleArc */
    NULL,                               /* pArc */
    NULL,                               /* pArcTo */
    NULL,                               /* pBeginPath */
    NULL,                               /* pBlendImage */
    NULL,                               /* pChord */
    NULL,                               /* pCloseFigure */
    xrdpdrv_CreateCompatibleDC,         /* pCreateCompatibleDC */
    xrdpdrv_CreateDC,                   /* pCreateDC */
    xrdpdrv_DeleteDC,                   /* pDeleteDC */
    NULL,                               /* pDeleteObject */
    NULL,                               /* pDeviceCapabilities */
    NULL,                               /* pEllipse */
    NULL,                               /* pEndDoc */
    NULL,                               /* pEndPage */
    NULL,                               /* pEndPath */
    NULL,                               /* pEnumFonts */
    NULL,                               /* pEnumICMProfiles */
    NULL,                               /* pExcludeClipRect */
    NULL,                               /* pExtDeviceMode */
    NULL,                               /* pExtEscape */
    NULL,                               /* pExtFloodFill */
    NULL,                               /* pExtSelectClipRgn */
    NULL,                               /* pExtTextOut */
    NULL,                               /* pFillPath */
    NULL,                               /* pFillRgn */
    NULL,                               /* pFlattenPath */
    NULL,                               /* pFontIsLinked */
    NULL,                               /* pFrameRgn */
    NULL,                               /* pGdiComment */
    NULL,                               /* pGetBoundsRect */
    NULL,                               /* pGetCharABCWidths */
    NULL,                               /* pGetCharABCWidthsI */
    NULL,                               /* pGetCharWidth */
    xrdpdrv_GetDeviceCaps,              /* pGetDeviceCaps */
    NULL,                               /* pGetDeviceGammaRamp */
    NULL,                               /* pGetFontData */
    NULL,                               /* pGetFontRealizationInfo */
    NULL,                               /* pGetFontUnicodeRanges */
    NULL,                               /* pGetGlyphIndices */
    NULL,                               /* pGetGlyphOutline */
    NULL,                               /* pGetICMProfile */
    NULL,                               /* pGetImage */
    NULL,                               /* pGetKerningPairs */
    NULL,                               /* pGetNearestColor */
    NULL,                               /* pGetOutlineTextMetrics */
    NULL,                               /* pGetPixel */
    NULL,                               /* pGetSystemPaletteEntries */
    NULL,                               /* pGetTextCharsetInfo */
    NULL,                               /* pGetTextExtentExPoint */
    NULL,                               /* pGetTextExtentExPointI */
    NULL,                               /* pGetTextFace */
    NULL,                               /* pGetTextMetrics */
    NULL,                               /* pGradientFill */
    NULL,                               /* pIntersectClipRect */
    NULL,                               /* pInvertRgn */
    NULL,                               /* pLineTo */
    NULL,                               /* pModifyWorldTransform */
    NULL,                               /* pMoveTo */
    NULL,                               /* pOffsetClipRgn */
    NULL,                               /* pOffsetViewportOrg */
    NULL,                               /* pOffsetWindowOrg */
    NULL,                               /* pPaintRgn */
    NULL,                               /* pPatBlt */
    NULL,                               /* pPie */
    NULL,                               /* pPolyBezier */
    NULL,                               /* pPolyBezierTo */
    NULL,                               /* pPolyDraw */
    NULL,                               /* pPolyPolygon */
    NULL,                               /* pPolyPolyline */
    NULL,                               /* pPolygon */
    NULL,                               /* pPolyline */
    NULL,                               /* pPolylineTo */
    NULL,                               /* pPutImage */
    NULL,                               /* pRealizeDefaultPalette */
    NULL,                               /* pRealizePalette */
    NULL,                               /* pRectangle */
    NULL,                               /* pResetDC */
    NULL,                               /* pRestoreDC */
    NULL,                               /* pRoundRect */
    NULL,                               /* pSaveDC */
    NULL,                               /* pScaleViewportExt */
    NULL,                               /* pScaleWindowExt */
    NULL,                               /* pSelectBitmap */
    NULL,                               /* pSelectBrush */
    NULL,                               /* pSelectClipPath */
    NULL,                               /* pSelectFont */
    NULL,                               /* pSelectPalette */
    NULL,                               /* pSelectPen */
    NULL,                               /* pSetArcDirection */
    NULL,                               /* pSetBkColor */
    NULL,                               /* pSetBkMode */
    NULL,                               /* pSetBoundsRect */
    NULL,                               /* pSetDCBrushColor */
    NULL,                               /* pSetDCPenColor */
    NULL,                               /* pSetDIBitsToDevice */
    NULL,                               /* pSetDeviceClipping */
    NULL,                               /* pSetDeviceGammaRamp */
    NULL,                               /* pSetLayout */
    NULL,                               /* pSetMapMode */
    NULL,                               /* pSetMapperFlags */
    NULL,                               /* pSetPixel */
    NULL,                               /* pSetPolyFillMode */
    NULL,                               /* pSetROP2 */
    NULL,                               /* pSetRelAbs */
    NULL,                               /* pSetStretchBltMode */
    NULL,                               /* pSetTextAlign */
    NULL,                               /* pSetTextCharacterExtra */
    NULL,                               /* pSetTextColor */
    NULL,                               /* pSetTextJustification */
    NULL,                               /* pSetViewportExt */
    NULL,                               /* pSetViewportOrg */
    NULL,                               /* pSetWindowExt */
    NULL,                               /* pSetWindowOrg */
    NULL,                               /* pSetWorldTransform */
    NULL,                               /* pStartDoc */
    NULL,                               /* pStartPage */
    NULL,                               /* pStretchBlt */
    NULL,                               /* pStretchDIBits */
    NULL,                               /* pStrokeAndFillPath */
    NULL,                               /* pStrokePath */
    NULL,                               /* pUnrealizePalette */
    NULL,                               /* pWidenPath */
    NULL,                               /* wine_get_wgl_driver */
    GDI_PRIORITY_GRAPHICS_DRV           /* priority */
};

/******************************************************************************
 *      xrdpdrv_get_gdi_driver
 */
const struct gdi_dc_funcs * CDECL xrdpdrv_get_gdi_driver(unsigned int version)
{
    printf("xrdpdrv_get_gdi_driver:\n");
    if (version != WINE_GDI_DRIVER_VERSION)
    {
        ERR("version mismatch, gdi32 wants %u but winexrdp has %u\n", version,
            WINE_GDI_DRIVER_VERSION);
        return NULL;
    }
    return &xrdpdrv_funcs;
}

/***********************************************************************
 *      xrdpdrv_create_desktop
 *
 * Create the xrdp desktop window for the desktop mode.
 */
BOOL CDECL xrdpdrv_create_desktop(UINT width, UINT height)
{
    printf("xrdpdrv_create_desktop: width %d height %d\n", width, height);
    return 1;
}


/**********************************************************************
 *      CreateWindow   (X11DRV.@)
 */
BOOL CDECL xrdpdrv_CreateWindow(HWND hwnd)
{
    printf("xrdpdrv_CreateWindow: %d\n", (int)hwnd);
    return 1;
}

BOOL CDECL xrdpdrv_CreateDesktopWindow(HWND hwnd)
{
    printf("xrdpdrv_CreateDesktopWindow: %d\n", (int)hwnd);
    return 1;
}
